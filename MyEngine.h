#pragma once
#include <string>

class World;

class MyEngine
{
public:
	MyEngine();
	virtual ~MyEngine();

	void Run();

	void Stop();

	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

protected:
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool bIsRunning = true;
	World* CurrentWorld;
};

