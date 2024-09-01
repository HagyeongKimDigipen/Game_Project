#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/MovePooPoo.h"
#include  "../GUGUENGINE/glfwInput.h"
#include "Option.h"

//class sound;

class Level4 : public LevelManager
{
public:
	Level4()
	{
		background = nullptr;
		movePuzzle = nullptr;
		movePuzzle2 = nullptr;
		movePuzzle3 = nullptr;

		startPuzzle = nullptr;
		endPuzzle = nullptr;
		puzzle1 = nullptr;
		puzzle2 = nullptr;
		puzzle3 = nullptr;
		puzzle4 = nullptr;
		puzzle5 = nullptr;
		puzzle6 = nullptr;
		puzzle7 = nullptr;

		puzzle8 = nullptr;
		puzzle9 = nullptr;
		puzzle10 = nullptr;

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		blackPuzzle3 = nullptr;

		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;
		
		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;
		
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		
		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		pooCharacter = nullptr;
		fail = nullptr;
		win = nullptr;
		
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST4;
	}

private:
	bool failS = false;

	bool Nos[2] = { false };
	bool Cur[3] = { false };
	bool checking = false;
	bool SUI[5] = { false };
	bool PUT[3] = { false };
	
	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;

	bool quitCheck = false;
	bool realQuit = false;

	
	Object* background;
	Object* movePuzzle, * movePuzzle2, * movePuzzle3, * startPuzzle, * endPuzzle;
	Object* levelImage, * numberImage;
	
	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5;
	Object* puzzle6, * puzzle7, * puzzle8, * puzzle9, * puzzle10;

	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;

	Object* playUI, * quitUI, * optionUI, * restartUI;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;

	Object* Levelsel, * Levelsel_pressed;
	Object* pooCharacter;
	Object* button;
	Object* clear;
	Object* fail;
	Object* win;
	
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	MovePooPoo mPooPoo;

	bool skip = false;

	Input mInput;
	
	bool rot[3] = { false };
	bool movable[3] = { false };
	bool move[3] = { false };
	bool UI[5] = { false };

	bool poopooCheck = false;
	
	Vector2<float> cursor4;

	int connectMove4 = 0;

	float degree4 = 0;
	float degree4_2 = 0;
	float degree4_3 = 0;


	int chekNext4 = 0;
	
	bool conecTcheck4_1 = false;
	bool conecTcheck4_2 = false;
	bool conecTcheck4_3 = false;

	bool blCheck3 = false;
	bool blCheck3_2 = false;

	bool blCheck4 = false;
	bool blCheck4_2 = false;

	double timer;
	double timer2;
	int current;

	LevelOption opt;
};