#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.12.2019
 *digipen.hagyeong@gmail.com
 *LevelManager.cpp
 *for manage level
 */

#include "../GUGUENGINE/Sound.h"

enum class GameLevels
{

	DIGIPENLOGO,
	FMODLOGO,
	GUGULOGO,
	LOAD1,
	CUTSCENE,
	ENDINGCUTS,
	MAINMENU,
	OPTION,
	LV_TEST1,
	LV_TEST2,
	LV_TEST3,
	LV_TEST4,
	LV_TEST5,
	LV_TEST6,
	LV_TEST8,
	LV_TEST9,
	LV_TEST10,
	LV_TEST11,
	LV_TEST12,
	LV_TEST13,
	LV_TEST14,
	LV_SELECT,
	MOVINGCHECK,
	CREDITS

};

class LevelManager
{
public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
    virtual GameLevels GetCurrLevel() = 0;
	void SetNextLevel(GameLevels myLevel) { nextLevel = myLevel; }
	virtual ~LevelManager()	{}

	Sound* sound = nullptr;
	GameLevels nextLevel = GameLevels::MAINMENU;
private:
};
