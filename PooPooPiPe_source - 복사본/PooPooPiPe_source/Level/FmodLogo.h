#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"


class FmodLogo : public LevelManager
{
public:
	FmodLogo()
	{
		fmodLogo = nullptr;
		textureFmod=0;
		timer = 0;

	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::FMODLOGO;
	}
private:
	Object* fmodLogo;
	GLuint textureFmod;
	Shader mShader;
	double timer;

	Input mInput;
};


