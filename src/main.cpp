#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "events.h"

int WIDTH = 1280;
int HEIGHT = 720;

int main() 
{
    Events* event = new Events;
    Window* windo = new Window;

    windo->initialize(WIDTH, HEIGHT, "Minecraft 1.5.2");
    event->initialize();

    glClearColor(0, 0, 1, 1);

    while (!Window::isShouldClose())
    {

        windo->swapBuffers();
        event->pullEvents();

        if (event->justPressed(GLFW_KEY_ESCAPE))
        {
            windo->setShouldClose(true);
        }
        if (event->justClicked(GLFW_MOUSE_BUTTON_1))
        {
            glClearColor(1, 0, 1, 1);
        }

        glClear(GL_COLOR_BUFFER_BIT);
    }

	return 0;
}