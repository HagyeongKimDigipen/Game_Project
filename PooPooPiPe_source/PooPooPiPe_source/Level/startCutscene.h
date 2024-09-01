#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"

class sound;
class startCut : public LevelManager
{
public:
	startCut()
	{
		startCut1 = nullptr;
		startCut2 = nullptr;
		startCut3 = nullptr;

		texturestartCut1 = 0;
		texturestartCut2 = 0;
		texturestartCut2 = 0;
		texturestartCut3 = 0;

		next = nullptr;
		skip = nullptr;
		texturestartNext = 0;
		texturestartSkip = 0;
		timer = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::CUTSCENE;
	}
private:
	Input mInput;
	Object* startCut1;
	GLuint texturestartCut1;
	Object* startCut2;
	GLuint texturestartCut2;
	Object* startCut3;
	GLuint texturestartCut3;
	Shader mShader;
	Object* next;
	Object* skip;
	GLuint texturestartNext;
	GLuint texturestartSkip;
	Vector2<float> cursor__;
	bool input[2] = { false, false };
	bool cut[2] = { false, false };
	float dt = 0.f;
	bool sound_[3] = { false };
	double timer;
	bool soundeffect[3] = { false };
};
