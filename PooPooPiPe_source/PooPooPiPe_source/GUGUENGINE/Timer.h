#pragma once

#include <chrono>

class Timer {

public:

	Timer();
	~Timer();

	void start(void);
	void stop(void);

	void SetTime(void);
	double GetDT(void);
	double GetTime(void);

private:

	std::chrono::time_point<std::chrono::system_clock> startTime;
	std::chrono::time_point<std::chrono::system_clock> previousTime;
	std::chrono::time_point<std::chrono::system_clock> currentTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;

	bool  IsRunning = false;
};
