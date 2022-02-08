#include "MyEngine.h"
#include "World.h"
#include <fstream>
#include "Wall.h"
#include "Player.h"
#include "Goal.h"
#include <iostream>

//MyEngine::MyEngine()
//{
//	CurrentWorld = new World();
//	bIsRunning = true;
//}

MyEngine::MyEngine(std::string Title, std::string LevelName, int Width, int Height)
{
	CurrentWorld = new World();
	bIsRunning = true;

	LoadLevel(LevelName);

	Init(Title, Width, Height);
}

MyEngine::~MyEngine()
{
	delete CurrentWorld;
	CurrentWorld = nullptr;
	bIsRunning = false;

	Term();
}

void MyEngine::Init(std::string Title, int Width, int Height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL_Init Error :" << SDL_GetError() << std::endl;
	}

	SDL_Window* MyWindow = SDL_CreateWindow(Title.c_str(), 100, 100, Width, Height, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	if (MyRenderer == nullptr)
	{
		std::cout << "can't Create renderer :" << SDL_GetError() << std::endl;
	}
}

void MyEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

void MyEngine::Run()
{
	BeginPlay();
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void MyEngine::Stop()
{
	bIsRunning = false;
}

void MyEngine::SpawnActor(Actor* NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}

void MyEngine::DestroyActor(Actor* DestroyActor)
{
	CurrentWorld->DestroyActor(DestroyActor);
}

void MyEngine::LoadLevel(std::string LoadMapName)
{
	std::ifstream MapFile(LoadMapName);
	int X = 0;
	int Y = 0;

	while (!MapFile.eof())
	{
		char ReadData = MapFile.get();
		switch (ReadData)
		{
		case '\n':
			X = 0;
			Y++;
			continue;
		case '*':
			SpawnActor(new Wall(X, Y));
			break;
		case 'P':
			SpawnActor(new Player(X, Y));
			break;
		case 'G':
			SpawnActor(new Goal(X, Y));
			break;
		}

		X++;
	}

	MapFile.close();
}

void MyEngine::SaveLevel(std::string SaveMapName)
{
	std::ofstream WriteFile(SaveMapName);

	int MaxX = -99999;
	int MaxY = -99999;

	std::vector<Actor*> ActorList = CurrentWorld->GetActorList();


	//제일 큰 좌표값 저장 하기
	for (auto SelectedActor : ActorList)
	{
		if (MaxX <= SelectedActor->GetX())
		{
			MaxX = SelectedActor->GetX();
		}

		if (MaxY <= SelectedActor->GetY())
		{
			MaxY = SelectedActor->GetY();
		}
	}

	bool bIsWrite = false;

	for (int Y = 0; Y <= MaxY; ++Y)
	{
		for (int X = 0; X <= MaxX; ++X)
		{
			//객체 저장
			for (auto SelectedActor : ActorList)
			{
				if (SelectedActor->GetX() == X && SelectedActor->GetY() == Y)
				{
					WriteFile.put(SelectedActor->GetShape());
					bIsWrite = true;
					break;
				}
			}

			//빈칸 저장
			if (bIsWrite == false)
			{
				WriteFile.put(' ');
			}

			bIsWrite = false;
		}
		//줄 바꿈
		WriteFile.put('\n');
	}

	WriteFile.close();
}

void MyEngine::BeginPlay()
{
	CurrentWorld->BeginPlay();
}

void MyEngine::Tick()
{
	//엔진에서 기본 처리 하는 이벤트
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		bIsRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_q:
			bIsRunning = false;
			break;
		}
		break;
	}


	CurrentWorld->Tick();
}

void MyEngine::Render()
{
	//그릴 리스트 준비
//PreRender(그릴 준비, 그릴 물체 배치)

	CurrentWorld->Render();

	//GPU야 그려라
//Render
	SDL_RenderPresent(MyRenderer);
}

void MyEngine::Input()
{
	//Input
	SDL_PollEvent(&MyEvent);

	CurrentWorld->Input();
}
