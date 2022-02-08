//#include <fstream>
//#include "MyEngine.h"
//#include "Floor.h"
//#include "Player.h"
//#include "Wall.h"
//#include "Goal.h"
#include <iostream>
#include "SDL.h"
#include <vector>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")


using namespace std;

//class Test
//{
//public:
//	Test() { Count++; }
//	virtual ~Test() { Count--; }
//	static void PrintA();
//
//
//	static int Count;
//};
//
//int Test::Count = 0;
//
//void Test::PrintA()
//{
//	std::cout << Test::Count << std::endl;
//}
//
//int main()
//{
//	Test* A = new Test();
//	Test* B = new Test();
//	Test* C = new Test();
//	Test* D = new Test();
//
//	delete B;
//	delete C;
//
//	
//	Test::PrintA();
//
//
//	return 0;
//}
//int main()
//{
//
//	MyEngine* PlayEngine = new MyEngine();
//
//	//**********
//	PlayEngine->SpawnActor(new Wall(0, 0));
//	PlayEngine->SpawnActor(new Wall(1, 0));
//	PlayEngine->SpawnActor(new Wall(2, 0));
//	PlayEngine->SpawnActor(new Wall(3, 0));
//	PlayEngine->SpawnActor(new Wall(4, 0));
//	PlayEngine->SpawnActor(new Wall(5, 0));
//	PlayEngine->SpawnActor(new Wall(6, 0));
//	PlayEngine->SpawnActor(new Wall(7, 0));
//	PlayEngine->SpawnActor(new Wall(8, 0));
//	PlayEngine->SpawnActor(new Wall(9, 0));
//
//	//*       *
//	PlayEngine->SpawnActor(new Wall(0, 1));
//	PlayEngine->SpawnActor(new Wall(9, 1));
//
//	PlayEngine->SpawnActor(new Wall(0, 2));
//	PlayEngine->SpawnActor(new Wall(9, 2));
//	PlayEngine->SpawnActor(new Wall(0, 3));
//	PlayEngine->SpawnActor(new Wall(9, 3));
//	PlayEngine->SpawnActor(new Wall(0, 4));
//	PlayEngine->SpawnActor(new Wall(9, 4));
//	PlayEngine->SpawnActor(new Wall(0, 5));
//	PlayEngine->SpawnActor(new Wall(9, 5));
//	PlayEngine->SpawnActor(new Wall(0, 6));
//	PlayEngine->SpawnActor(new Wall(9, 6));
//	PlayEngine->SpawnActor(new Wall(0, 7));
//	PlayEngine->SpawnActor(new Wall(9, 7));
//	PlayEngine->SpawnActor(new Wall(0, 8));
//	PlayEngine->SpawnActor(new Wall(9, 8));
//
//	//**********
//	PlayEngine->SpawnActor(new Wall(0, 9));
//	PlayEngine->SpawnActor(new Wall(1, 9));
//	PlayEngine->SpawnActor(new Wall(2, 9));
//	PlayEngine->SpawnActor(new Wall(3, 9));
//	PlayEngine->SpawnActor(new Wall(4, 9));
//	PlayEngine->SpawnActor(new Wall(5, 9));
//	PlayEngine->SpawnActor(new Wall(6, 9));
//	PlayEngine->SpawnActor(new Wall(7, 9));
//	PlayEngine->SpawnActor(new Wall(8, 9));
//	PlayEngine->SpawnActor(new Wall(9, 9));
//
////	PlayEngine->SpawnActor(new Floor(1, 1));
//
//	PlayEngine->SpawnActor(new Player(1, 1));
//	PlayEngine->SpawnActor(new Goal(8, 8));
//
//
//	PlayEngine->SaveLevel("Level02.map");
//
//	delete PlayEngine;
//	PlayEngine = nullptr;
//
//	return 0;
//}
////참조자, Reference
//void SwapInt(int& A, int& B)
//{
//	int Temp = A;
//	A = B;
//	B = Temp;
//}
int SDL_main(int argc, char* argv[])
{
	//	MyEngine* PlayEngine = new MyEngine();
	//
	//	PlayEngine->LoadLevel("Level02.map");
	//	PlayEngine->SaveLevel("Level03.map");
	//
	////	PlayEngine->Run();
	//
	//	delete PlayEngine;
	//	PlayEngine = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL_INIT_VIDEO :" << SDL_GetError() << endl;
		return -1;
	}

	SDL_Window* MyWindow = SDL_CreateWindow("First SDL Exmple", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Event MyEvent;

	//그림물감통 준비
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	if (MyRenderer == nullptr)
	{
		cout << "can't Create renderer : " << SDL_GetError() << endl;
		return -1;
	}

	bool bIsRunning = true;

	while (bIsRunning)
	{
		
		//Input
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;
		case SDL_KEYDOWN:
			cout << SDL_GetKeyName( MyEvent.key.keysym.sym) << " 키 눌러짐" << endl;
			switch (MyEvent.key.keysym.sym)
			{
			case SDLK_q :
				bIsRunning = false;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN: 
			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) << " 키 눌러짐" << endl;
			cout << "(" << MyEvent.button.x << ", " << MyEvent.button.y << ")" << endl;
		}

		
		//Renderer(그릴 준비, 그릴 물체 배치)
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(MyRenderer);
		
		//빨간색 선 그리기
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0x00, 0x00, 256);
		SDL_RenderDrawLine(MyRenderer, 100, 100, 200, 200);

		//Render(그리기 시작)
		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	return 0;
}