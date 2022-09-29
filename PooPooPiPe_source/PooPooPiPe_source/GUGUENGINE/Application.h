#pragma once
/*
 *juhye.son
 *9.17.2019
 *juhye.son990902@gmail.com
 *Application.h
 *this is applicaiotn header
 */
#include "Application.h"
#include  "Shader.h"
#include "../GLFW/glfw3.h"
#include "System.h"

class Application : public System
{
public:
	Application();
	~Application();
	
	bool IsGameRunning() const { return isGameRunning; }
	
	void Init() override;
	void Update() override;
	bool IsFullScreen() { return isFullScreen; }
	void SetIsFullScreen(bool isFull) { isFullScreen = isFull; }
	void SetFullScreen();
	
	void setMyWindow(GLFWwindow& m);
	GLFWwindow* getMyWindow();


	int height = 1920;
	int width = 1080;


	int framebufferWidth, framebufferHeight;

private:
	bool isGameRunning = false;
	int sizeX = 300;
	int sizeY = 400;
	bool isFullScreen = false;
	int mouse_X;
	int mouse_Y;
	Shader mShader;
	GLFWwindow* Mywindow;

	int tempx=1200, tempy=900;
	int tx=50, ty=50;

};
extern Application* APPLICATION;
