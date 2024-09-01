#pragma once

class LimitRotate
{
public:
	LimitRotate() : limitTime(15) {}
	~LimitRotate(){}

	int getLimitTime();

	void Update();
	
	void IncLimit();
	void DecLimit();
	void setRotate(int i);
	
private:
	int limitTime;
};