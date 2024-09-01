#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"

class sound;
class GUGULOGO : public LevelManager
{
public:
	GUGULOGO()
	{
		gugulogo = nullptr;
		timer = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::GUGULOGO;
	}
private:
	Object* gugulogo;
	Shader mShader;

	bool check[2] = { false };
	double timer;
	Input mInput;
};
