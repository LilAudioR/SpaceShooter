#if _DEBUG
#pragma comment(lib, "SFML-system-d")
#pragma comment(lib, "SFML-graphics-d")
#pragma comment(lib, "SFML-window-d")
#else
#pragma comment(lib, "SFML-system")
#pragma comment(lib, "SFML-graphics")
#pragma comment(lib, "SFML-window")
#endif

#include "Game.h"

int main()
{
	CGame GameLoop;
	GameLoop.Run();

	return 0;
}