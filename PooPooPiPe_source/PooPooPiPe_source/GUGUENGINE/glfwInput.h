#pragma once
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

enum KEY
{
	IGNORE,
	IGNORE2,
	SPACE,
	A,
	ESCAPE,
	TAB,
	LEFT,
	RIGHT,
	F, 
	ENTER, 
	UP, 
	DOWN, 
	SIZE
};

class Input
{
public:
	Input();
	~Input() {};

	void InitCallback(GLFWwindow* window);
	void Update();
	bool IsPressed(KEY k);
	bool IsKeyDown(KEY k);
	void setInput(KEY k);
	Vector2<float> Cursor;

private:
	bool Key[KEY::SIZE];
	bool WasKey[KEY::SIZE];
	
	friend static void key_callback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/);
	friend static  void cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos);
	friend static  void  mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/);

};
extern Input* INPUT;





