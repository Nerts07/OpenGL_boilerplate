#include "window.h"

typedef unsigned int uint;

class Events
{
public:
	static bool* _keys;
	static uint* _frames;
	static uint _current;

	//cursor coords
	static double deltaX;
	static double deltaY;
	static double x;
	static double y;

	static bool _cursor_locked;
	static bool _cursor_started;

	static int initialize();
	static void pullEvents();

	static bool pressed(int keycode);
	static bool justPressed(int keycode);

	static bool clicked(int button);
	static bool justClicked(int button);
private:

};
