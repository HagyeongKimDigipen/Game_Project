#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"
class sound;

class LevelSelect : public LevelManager
{
public:
	LevelSelect()
	{
		backgroundLv = nullptr;

		Level1 = nullptr;
		Level1_pressed = nullptr;
		
		Level2 = nullptr;
		Level2_pressed = nullptr;
		Level2_lock = nullptr;
		
		Level3 = nullptr;
		Level3_pressed = nullptr;
		Level3_lock = nullptr;

		Level4 = nullptr;
		Level4_pressed = nullptr;
		Level4_lock = nullptr;

		Level5 = nullptr;
		Level5_pressed = nullptr;
		Level5_lock = nullptr;

		Level6 = nullptr;
		Level6_pressed = nullptr;
		Level6_lock = nullptr;

		Level7 = nullptr;
		Level7_pressed = nullptr;
		Level7_lock = nullptr;

		Level8 = nullptr;
		Level8_pressed = nullptr;
		Level8_lock = nullptr;

		Level9 = nullptr;
		Level9_pressed = nullptr;
		Level9_lock = nullptr;

		Level10 = nullptr;
		Level10_pressed = nullptr;
		Level10_lock = nullptr;

		Level11 = nullptr;
		Level11_pressed = nullptr;
		Level11_lock = nullptr;
		
		currentLevel = 0;
	}
	int currentLevel;
	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_SELECT;
	}
private:
	int getLevNum = 0;

	Object* backgroundLv;
	Shader mShader, mShader2;
	Object* Level1;
	Object* Level1_pressed;

	Object* Level2;
	Object* Level2_pressed;
	Object* Level2_lock;
	bool checking;
	Object* Level3;
	Object* Level3_pressed;
	Object* Level3_lock;

	Object* Level4;
	Object* Level4_pressed;
	Object* Level4_lock;

	Object* Level5;
	Object* Level5_pressed;
	Object* Level5_lock;

	Object* Level6;
	Object* Level6_pressed;
	Object* Level6_lock;

	Object* Level7;
	Object* Level7_pressed;
	Object* Level7_lock;
	
	Object* Level8;
	Object* Level8_pressed;
	Object* Level8_lock;

	Object* Level9;
	Object* Level9_pressed;
	Object* Level9_lock;

	Object* Level10;
	Object* Level10_pressed;
	Object* Level10_lock;

	Object* Level11;
	Object* Level11_pressed;
	Object* Level11_lock;
	bool UI[11] = { false };
	Input levelInput;
};
