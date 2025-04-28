#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//these don't even matter 
//wayland on top
#define WIDTH  600
#define HEIGHT 800

typedef struct{
  float r, g, b, a;
} Color;


bool epsEq(float a, float b){
  return fabs(a-b) < 0.00001f;
}
float floatMod(float a, float b){
  return a - (int32_t)(a/b) * b;
}

float floatNorm(float a){
  return floatMod(a, 1.0f);
}

Color colNorm(Color color){
  return (Color){ floatNorm(color.r), floatNorm(color.g), floatNorm(color.b), color.a};
}

Color mkColor(float r, float g, float b, float a){
  Color col = {.r = r, .g = g, .b = b, .a = a};
  return colNorm(col);
}

Color addColor(Color c1, Color c2){
  return mkColor(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b, c1.a + c2.a);
}

Color addChScalar(Color color, float x, int type){
  Color col = { .r = color.r, .g = color.g, .b = color.b, .a = color.a};
  switch(type){
    case 1:
      col.r += x;
      break;
    case 2:
      col.g += x;
      break;
    case 3:
      col.b += x;
      break;
    default:
  }

  return colNorm(col);
}

GLFWwindow *makeWindow(const char *name){
  GLFWwindow *win = glfwCreateWindow(WIDTH, HEIGHT, name, NULL, NULL);

  glfwMakeContextCurrent(win);
  gladLoadGL();
  return win;
}

void initGLFW(const int *ver){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ver[0]);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,ver[1]);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void processInput(GLFWwindow *window){
  if(glfwGetKey(window, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void glClearCol(Color col){
  glClearColor(col.r, col.g, col.b, col.a);
}

int main(){
  const int ver[] = {3, 3};
  const char name[] = "testingggg";
  Color color; 
  Color res = { .r = 0.0f, .g = 0.0f, .b = 0.0f, .a = 1.0f };
  float tresh = 1.0f, scale = 0.005f;
  int type = 1;
  initGLFW(ver);
  GLFWwindow *window = makeWindow(name);

  color = res;
  while(!glfwWindowShouldClose(window)){
    processInput(window);

    glClearCol(color);
    glClear(GL_COLOR_BUFFER_BIT);

    if(!epsEq(color.r + color.g + color.b,tresh)){
      color = addChScalar(color,scale,type);
    } else {
      color = res;
      type++;
      if(type>3)
        type=1;
    }
    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  glfwTerminate();

  return 0;
}
