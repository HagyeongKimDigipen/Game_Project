/*
 *juhye.son
 *9.10.2019
 *juhye.son990902@gmail.com
 *Timer.cpp
 *for check time
 */
#include "Timer.h"

Timer::Timer()
{
	startTime = std::chrono::system_clock::now();
	endTime = std::chrono::system_clock::now();
	currentTime = std::chrono::system_clock::now();
	previousTime = std::chrono::system_clock::now();
	
};
Timer::~Timer(){};

void Timer::start(void)
{
	startTime = std::chrono::system_clock::now();
	IsRunning = true;
}

void Timer::stop(void)
{
	endTime = std::chrono::system_clock::now();
	IsRunning = false;
}

void Timer::SetTime(void)
{
	startTime = std::chrono::system_clock::now();
	endTime = std::chrono::system_clock::now();
	currentTime = std::chrono::system_clock::now();
	previousTime = std::chrono::system_clock::now();
}

double Timer::GetDT(void)
{
	currentTime = std::chrono::system_clock::now();

	std::chrono::duration<double> DT = currentTime - previousTime;

	previousTime = std::chrono::system_clock::now();

	return DT.count();
}

double Timer::GetTime(void)
{

	currentTime = std::chrono::system_clock::now();

	std::chrono::duration<double> time = currentTime - startTime;

	return time.count();

}
