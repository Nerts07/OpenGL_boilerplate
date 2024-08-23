#include <GLFW/glfw3.h>
#include <string>

#include "events.h"

uint Events::_current = 0;
uint* Events::_frames;
bool* Events::_keys;
double Events::deltaX = 0.0f;
double Events::deltaY = 0.0f;
double Events::x = 0.0f;
double Events::y = 0.0f;
bool Events::_cursor_locked = false;
bool Events::_cursor_started = false;


#define MOUSE_BUTTONS 1024

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (Events::_cursor_locked)
	{
		Events::deltaX += xpos - Events::x;
		Events::deltaY += ypos - Events::y;
	}
	else
	{
		Events::_cursor_started = true;
	}
	Events::x = xpos;
	Events::y = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode) 
{
	if (action == GLFW_PRESS)
	{
		Events::_keys[MOUSE_BUTTONS + button] = true;  //mouse buttons starts from 1024, other 1024 only for keyboard input
		Events::_frames[MOUSE_BUTTONS + button] = Events::_current;
	}
	else if (action == GLFW_RELEASE)
	{
		Events::_keys[MOUSE_BUTTONS + button] = false;
		Events::_frames[MOUSE_BUTTONS + button] = Events::_current;
	}

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		Events::_keys[key] = true;
		Events::_frames[key] = Events::_current;
	}
	else if (action == GLFW_RELEASE)
	{
		Events::_keys[key] = false;
		Events::_frames[key] = Events::_current;
	}
}

int Events::initialize() 
{
	GLFWwindow* window = Window::window;
	_keys = new bool[1032]; //1024 for keyboard, other 12 for mouse input
	_frames = new uint[1032];

	memset(_keys, false, 1032 * sizeof(bool));
	memset(_frames, 0, 1032 * sizeof(uint));

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	return 0;
}

bool Events::pressed(int keycode)
{
	if (keycode<0 || keycode >= MOUSE_BUTTONS)
	{
		return false;
	}
	else
	{
		return _keys[keycode];
	}
}

bool Events::justPressed(int keycode)
{
	if (keycode < 0 || keycode >= MOUSE_BUTTONS)
	{
		return false;
	}
	else
	{
		return _keys[keycode] && _frames[keycode] == _current;
	}
}

bool Events::clicked(int button)
{
	int index = MOUSE_BUTTONS + button;
	return _keys[index];
}

bool Events::justClicked(int button)
{
	int index = MOUSE_BUTTONS + button;
	return _keys[index] && _frames[index] == _current;
}

void Events::pullEvents() 
{
	_current++;
	deltaX = 0.0f;
	deltaY = 0.0f;
	glfwPollEvents();

}