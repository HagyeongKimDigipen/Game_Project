#pragma once

#include<vector>
#include "../GUGUENGINE/System.h"
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Sound.h"

//define enum for level


class StateManager : public System
{
public:
	StateManager();
	~StateManager();
	void Init() override;
	void Update() override;
	void Shutdown();
	void ReloadState();
	//change level
	void ChangeLevel(GameLevels changeLV);
	void setCurrentLV(int i);
	int GetCurrentLV();

private:
	enum class State {
		START,
		LOAD,
		RUNNING,
		UNLOAD,
		SHUTDOWN,
		EXIT,
	};
	//Store the current level.
	GameLevels current;

	//Store the levels.
	std::vector<LevelManager*> levels;
	State state;
	LevelManager* currGameState;
	LevelManager* nextGameState;
	LevelManager* before;
	Sound* sound;

	int currentLV;
};
extern StateManager* STATE_MANAGER;
