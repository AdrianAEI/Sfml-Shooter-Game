#define _CRTDBG_MAP_ALLOC
#include "Game.h"
#include <iostream>
#include <time.h>// random 

int main()
{
	srand(time(NULL));
	//no memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game game;
	game.run();
	//memory leaks tester
	//int* leaksMaker = new int();
	return 0;
}
