#pragma once
/*
 *hakyung.kim
 *1.10.2020
 *digipen.hagyeong@gmail.com
 *Level5.cpp
 *this is level5 header
 */
#include "Option.h"
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE//CollisionCheck.h"
#include "../GUGUENGINE/glfwInput.h"
#include "../GUGUENGINE/MovePooPoo.h"

class sound;

class Level5 : public LevelManager
{
public:
	Level5()
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
		puzzle11 = nullptr;
		puzzle12 = nullptr;

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		blackPuzzle3 = nullptr;
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;

		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;
		
		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;
		win = nullptr;

		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		pooCharacter = nullptr;
		fail = nullptr;
		mini = nullptr;
		Yellow = nullptr;
		
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST5;
	}
private:
	bool failS = false;
	bool siren = false;
	Object* Yellow;

	bool yellowS = false;
	bool Nos[2] = { false };
	bool Cur[3] = { false };
	bool checking = false;
	bool SUI[5] = { false };
	bool PUT[3] = { false };
	int current;

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

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12;

	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;
	Object* pooCharacter;
	Object* playUI, * quitUI, * optionUI, * restartUI, *fail;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;
	Object* win;

	Object* Levelsel, * Levelsel_pressed;
	Object* mini;

	Object* button;
	Object* clear;

	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	Shader yShader;
	MovePooPoo mPooPoo;
	Input mInput;
	bool rot[3] = { false };
	bool movable[3] = { false };
	bool move[3] = { false };
	bool poopooCheck = false;
	
	bool skip = false;
	
	Vector2<float> cursor5;

	int coorcheck5 = 0;
	int connectMove5 = 0;

	float degree5 = 0;
	float degree5_2 = 0;
	float degree5_3 = 0;

	int chekNext5 = 0;

	bool movePuzzleCheck5 = true;


	bool blCheck5 = false;
	bool blCheck5_2 = false;
	bool blCheck5_3 = false;

	bool blCheck6 = false;
	bool blCheck6_2 = false;
	bool blCheck6_3 = false;

	bool blCheck7 = false;
	bool blCheck7_2 = false;
	bool blCheck7_3 = false;

	bool conecTcheck5_1 = false;
	bool conecTcheck5_2 = false;
	bool conecTcheck5_3 = false;
	
	bool UI[5] = { false };
	LevelOption opt;

	double timer;
	double timer2;
	double timer3;
	bool one;
};