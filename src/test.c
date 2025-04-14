#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void resize(GLFWwindow* win, int width, int height){}

GLFWwindow *makeWindow(const int *dim, const char *name){
  GLFWwindow *win = glfwCreateWindow(dim[0], dim[1], name, NULL, NULL);

  glfwMakeContextCurrent(win);
  glfwSetFramebufferSizeCallback(win, resize); 

  return win;
}

void initGLFW(const int *ver){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ver[0]);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,ver[1]);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int main(){
  const int ver[] = {3, 3};
  const int dim[] = {800, 600};
  const char name[] = "testingggg";

  initGLFW(ver);
  GLFWwindow *window = makeWindow(dim, name);



  while(!glfwWindowShouldClose(window)){
    glfwSwapBuffers(window);
    glfwPollEvents();    
  }

  return 0;
}
