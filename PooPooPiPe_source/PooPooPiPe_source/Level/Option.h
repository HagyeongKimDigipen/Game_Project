#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/glfwInput.h"

class Sound;

class LevelOption : public LevelManager
{
public:
	LevelOption()
	{
		background = nullptr;
		option = nullptr;
		music = nullptr;
		arrowRight = nullptr;
		arrowLeft = nullptr;
		bar0 = nullptr;
		goToMain = nullptr;
		goToMain_pressed = nullptr;
		key = 0;
		fullScreen = nullptr;
		fullScreenFalse = nullptr;
		fullScreenTrue = nullptr;
		quitButton = nullptr;
		quitButton_pressed = nullptr;
		backtomain = nullptr;
		backtomain_pressed = nullptr;
		controls = nullptr;

		credit1 = nullptr;
		credit2 = nullptr;
		credit3 = nullptr;

		next = nullptr;
		back = nullptr;

		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;
		soundBar = nullptr;
		mInput = nullptr;

	}

	void Init() override;
	void Update() override;
	void Close() override;
	void getInput(Input* m, Sound* ms);
	
	GameLevels GetCurrLevel() override
	{
		return GameLevels::OPTION;
	}

private:
	Object* background, * option, * music, * arrowRight, * arrowLeft, * bar0;
	Object* goToMain, *goToMain_pressed, * fullScreen, * fullScreenFalse, * fullScreenTrue;
	Object* quitButton, * quitButton_pressed, * backtomain, * backtomain_pressed;
	Object* creditsButton, * creditsButton_pressed, * tutorialButton, * tutorialButton_pressed;
	Object* controls;
	Object* credit1, *credit2, *credit3;

	Object* next;
	Object* back;
	
	bool checking;
	int key;
	bool clickCredit;
	bool clickControls;
	bool input[2] = { false, false };
	bool cut[2] = { false, false };
	bool SSUI[2] = { false };
	bool nextSound[3] = { false };
	bool fullscreenS = false;
	Mesh mMesh;
	Shader mShader;
	
	bool fullcheck = false;
	bool quitC = false;
	
	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;
	Object* soundBar;

	bool quitCheck = false;
	bool realQuit = false;

	bool UI[5] = { false };
	bool SUI = false;
	
	Vector2<float> cursor;
	GameLevels goback;
	
	Input* mInput;
	int prevLev = 0;
};