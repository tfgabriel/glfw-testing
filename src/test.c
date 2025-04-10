#include <stdio.h>
#include <GLFW/glfw3.h>

int main(){
  glfwInit();
  GLFWwindow* window;
  window = glfwCreateWindow(400, 600, "ts pmo", NULL, NULL);

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
