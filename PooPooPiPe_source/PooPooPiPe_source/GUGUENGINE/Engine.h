#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Engine.h
 *Engine to run game
 */
#include<vector>
#include <chrono>
#include "Sound.h"

class System;
class Engine
{
public:
	Engine();
	~Engine();

	void Init();

	void GameLoop();

	void Quit();

	void AddSystem(System* system);
	bool GAMERUN;
	double dt;
private:
	std::vector<System*> Systems; 
	 

	std::chrono::system_clock::time_point lastTick;
	std::chrono::system_clock::time_point fpsCalcTime;
	int frameCount;

	static constexpr double Target_FPS = 40.0;
	static constexpr int FPS_IntervalSec = 5;
	static constexpr int FPS_IntervalFrameCount = static_cast<int>(FPS_IntervalSec * Target_FPS);
	bool checkWindow = true;
	Sound* sound = nullptr;

};
extern Engine* ENGINE;