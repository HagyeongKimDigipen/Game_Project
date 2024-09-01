#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/glfwInput.h"
#include "Option.h"

class sound;

class Level2 : public LevelManager
{
public:
	Level2()
	{
		background = 0;
		movePuzzle = nullptr;
		blackPuzzle = nullptr;
		puzzleUp = nullptr;
		puzzleDown = nullptr;
		spacePress = nullptr;
		mouse = nullptr;
		playbutton = nullptr;
		key = 0;
		win = nullptr;
		pressPlay1 = nullptr;
		pressPlay2 = nullptr;
		playPressButton = nullptr;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST2;
	}
private:
	Object* background;
	Object* movePuzzle, * blackPuzzle, * puzzleUp, * puzzleDown, * spacePress, * mouse, * playbutton, * pressPlay1, * pressPlay2, * playPressButton;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	Input mInput;
	Vector2<float> cursor;

	Object* win;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };
	bool spaceCheck = false;
	bool rot = false;
	float degree = 0;
	int checkToPipe = 0;
	bool click = 0;
	bool cur = false;
	bool checking;
	bool fit = false;
	double timer;
	double timer2;

	LevelOption opt;
};