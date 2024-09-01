#pragma once

#include "Option.h"
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE//CollisionCheck.h"
#include "../GUGUENGINE/glfwInput.h"
#include "../GUGUENGINE/limitedRotate.h"
#include "../GUGUENGINE/MovePooPoo.h"

class sound;

class Level6 : public LevelManager
{
public:
	Level6()
	{
		background = nullptr;

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

		puzzle13 = nullptr;
		puzzle14 = nullptr;
		puzzle15 = nullptr;
		puzzle16 = nullptr;
		puzzle17 = nullptr;

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		blackPuzzle3 = nullptr;

		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;
		
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;
		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		pooCharacter = nullptr;
		leftCount = nullptr;
		leftnumberTen = nullptr;
		leftnumber = nullptr;
		fail = nullptr;
		win = nullptr;

		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST6;
	}

private:
	Object* background;
	Object* startPuzzle, * endPuzzle;

	bool failS[2] = { false };
	bool Nos[2] = { false };
	bool Cur[3] = { false };
	bool checking = false;
	bool SUI[2] = { false };
	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12, * puzzle13, * puzzle14, * puzzle15, * puzzle16, * puzzle17;

	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;

	bool quitCheck = false;
	bool realQuit = false;
	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;
	Object* Levelsel, * Levelsel_pressed;
	Object* pooCharacter;
	Object* playUI, * quitUI, * optionUI, * restartUI;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;
	Object* win;
	GLint textureWin;
	bool skip = false;
	int current;
	Object* levelImage, * numberImage, * leftCount, *leftnumberTen, *leftnumber, *fail;
	Object* button;
	Object* clear;
	MovePooPoo mPooPoo;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	LimitRotate rotTime;
	Input mInput;
	bool rot[6] = { false };
	bool poopooCheck = false;

	Vector2<float> cursor6;
	bool UI[5] = { false };

	int coorcheck6 = 0;
	int connectMove6 = 0;

	float degree6 = DegreeToRadian(60.f);
	float degree6_2 = DegreeToRadian(-60.f);
	float degree6_3 = DegreeToRadian(120.f);
	float degree6_4 = DegreeToRadian(180.f);
	float degree6_5 = DegreeToRadian(-180.f);
	float degree6_6 = DegreeToRadian(-120.f);

	bool rotrot = true;

	int chekNext6 = 0;


	bool conecTcheck6_1 = false;
	bool conecTcheck6_2 = false;
	bool conecTcheck6_3 = false;
	bool conecTcheck6_4 = false;
	bool conecTcheck6_5 = false;

	LevelOption opt;

	double timer;
	double timer2;
	double timer3;
};
