#pragma once

#include "LevelSelect.h"
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/glfwInput.h"

#include "Option.h"

class Sound;

class Level1 : public LevelManager
{
public:
	Level1()
	{
		background = nullptr;
		movePuzzle = nullptr;
		blackPuzzle = nullptr;
		puzzleLeft = nullptr;
		puzzleRight = nullptr;
		spacePress = nullptr;
		mouse = nullptr;
		key = 0;
		levelCheck = 0;
		spaceCheck = 0;
		win = nullptr;
		timer = 0;
		checking = false;
	}
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST1;
	}
	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* movePuzzle, * blackPuzzle, * puzzleLeft, * puzzleRight, *mouse;
	bool cur = false;
	bool checking;
	Object* spacePress;
	Input mInput;
	bool movable = false;
	Vector2<float> cursor;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };

	Object* win;


	bool levelCheck;
	bool spaceCheck;
	double timer;

	LevelOption opt;

};