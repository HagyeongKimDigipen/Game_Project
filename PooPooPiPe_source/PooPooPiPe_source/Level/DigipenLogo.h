#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"

class sound;
class DigipenLogo : public LevelManager
{
public:
	DigipenLogo()
	{
		digipenLogo = nullptr;
		textureDigipenLogo = 0;
		timer = 0;

	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::DIGIPENLOGO;
	}

private:
	Object* digipenLogo;
	Shader mShader;
	GLuint textureDigipenLogo;
	double timer;

	Vector2<float> cursor0;
	Input mInput;
	bool check = false;
};


