#ifndef WINDOW_WINDOW_H_
#define WINDOW_WINDOW_H_

#include <iostream>

class Window {
public:
	Window();
	static GLFWwindow* window;
	static int initialize(int width, int height, const char* title);
	static void terminate();

	static bool isShouldClose();
	static void setShouldClose(bool flag);
	static void swapBuffers();
};

#endif /* WINDOW_WINDOW_H_ */
