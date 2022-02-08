#include <iostream>
#include "MyEngine.h"
#include "SDL.h"


#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	MyEngine* PlayEngine = new MyEngine("Maze Game", "Level01.Map", 800, 600);

	PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;


	//bool bIsRunning = true;

	



	return 0;
}