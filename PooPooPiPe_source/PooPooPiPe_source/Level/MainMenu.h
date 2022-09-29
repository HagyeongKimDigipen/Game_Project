#pragma once
/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *MainMenu.h
 *this is mainmenu
 */
#include "Option.h"
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/Sound.h"
#include "..//GUGUENGINE/MovePooPoo.h"
#include "../GUGUENGINE/glfwInput.h"
class Sound;

class MainMenu : public LevelManager
{
public:
	MainMenu()
	{
		background = nullptr;
		startButton = nullptr;
		tutorialButton = nullptr;
		startButton_pressed = nullptr;
		tutorialButton_pressed = nullptr;
		optionButton = nullptr;
		optionButton_pressed = nullptr;
		test = nullptr;
		test2 = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::MAINMENU;
	}
private:
	Object* background;
	Object* startButton;
	Object* tutorialButton;
	Object* optionButton;
	Object* creditsButton;
	Object* quitButton;
	bool checking = false;
	Object* startButton_pressed;
	Object* tutorialButton_pressed;
	Object* optionButton_pressed;
	Object* creditsButton_pressed;
	Object* quitButton_pressed;
	
	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;

	bool quitCheck = false;
	bool realQuit = false;
	bool quitC = false;

	Object* credit1, * credit2, * credit3;
	Object* next;

	Object* test;
	Object* test2;
	
	bool UI[5] = { false };


	bool clickCredit = false;
	bool input[2] = { false, false };
	bool cut[2] = { false, false };


	int key;
	//MovePooPoo getDirectionPooPoo;
	bool main;
	Mesh mMesh;
	Shader mShader;
	Shader testNDCShader;//it will be deleted when NDC function is completed
	bool isPlaying = false;
	Input menuInput;
	Vector2<float> cursor0;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };
	Vector3<float> getOrigin3 = { 0, 0, 0 };

};
