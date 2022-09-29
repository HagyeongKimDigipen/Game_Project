/*
 *hakyung.kim
 *uijin.lee
 *11.14.2019
 *digipen.hagyeong@gmail.com
 *StateManager.cpp
 *to manage stage
 *we can change level
 */
#include "StateManager.h"
#include "DigipenLogo.h"
#include "startCutscene.h"
#include "endingcut.h"
#include "Option.h"
#include "Loading.h"
#include "FmodLogo.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "MainMenu.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include "Level8.h"
#include "Level9.h"
#include "Level10.h"
#include "Level11.h"
#include "Level12.h"
#include "Level13.h"
#include "Level14.h"
#include "LevelSelect.h"
#include "99.h"

StateManager* STATE_MANAGER = nullptr;

StateManager::StateManager()
{
	STATE_MANAGER = this;

	sound = new Sound();

	currGameState = nullptr;
	nextGameState = nullptr;
	before = nullptr;
	currentLV = 0;
	state = State::START;
	current = GameLevels::DIGIPENLOGO;
}

StateManager::~StateManager()
{
}

void StateManager::Init()
{
	current = GameLevels::DIGIPENLOGO;


	levels.push_back(new DigipenLogo());
	levels.push_back(new FmodLogo());
	levels.push_back(new GUGULOGO);
	levels.push_back(new Loading());
	levels.push_back(new startCut());
	levels.push_back(new endingCut());
	levels.push_back(new MainMenu());
	levels.push_back(new LevelOption());
	levels.push_back(new Level1());
	levels.push_back(new Level2());
	levels.push_back(new Level3());
	levels.push_back(new Level4());
	levels.push_back(new Level5());
	levels.push_back(new Level6());
	levels.push_back(new Level8());
	levels.push_back(new Level9());
	levels.push_back(new Level10());
	levels.push_back(new Level11());
	levels.push_back(new Level12());
	levels.push_back(new Level13());
	levels.push_back(new Level14());
	levels.push_back(new LevelSelect());
	
	levels.at(static_cast<int>(current))->Init();

	for (auto i: levels)
	{
		i->sound = sound;
	}
}

void StateManager::Update()
{
	sound->Update();

	switch (state) {
	case State::START:
		nextGameState = levels[static_cast<int>((current))];
		state = State::LOAD;
		break;
	case State::LOAD:
		currGameState = nextGameState;
		currGameState->Init();
		state = State::RUNNING;
		break;
	case State::RUNNING:
		if (currGameState != nextGameState) {
			if (nextGameState->GetCurrLevel() == GameLevels::OPTION)
			{
				before = currGameState;
			}
			state = State::UNLOAD;
		}
		else {
			if (currGameState->GetCurrLevel() == GameLevels::OPTION)
			{
				currGameState->SetNextLevel(before->GetCurrLevel());
			}
			currGameState->Update();
		}
		break;
	case State::UNLOAD:
		currGameState->Close();
		if (nextGameState == nullptr) {
			state = State::SHUTDOWN;
			break;
		}
		state = State::LOAD;
		break;
	case State::SHUTDOWN:
		state = State::EXIT;
		break;
	case State::EXIT:
		break;
	}
}

void StateManager::Shutdown()
{
	state = State::UNLOAD;
	nextGameState = nullptr;
}

void StateManager::ReloadState()
{
	state = State::UNLOAD;
}

void StateManager::ChangeLevel(GameLevels changeLV)
{
	nextGameState = levels[static_cast<int>(changeLV)];
}

void StateManager::setCurrentLV(int i)
{
	currentLV = i;
}

int StateManager::GetCurrentLV()
{
	return currentLV;
}


