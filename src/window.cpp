#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.h"

GLFWwindow* Window::window = nullptr;

Window::Window()
{

}

int Window::initialize(int width, int height, const char* title) 
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) 
    {
        std::cerr << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, width, height);

    return 0;
}

bool Window::isShouldClose() 
{
    return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool flag) 
{
    glfwSetWindowShouldClose(window, flag);
}

void Window::swapBuffers() 
{
    glfwSwapBuffers(window);
}

