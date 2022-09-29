#pragma once
/*
 *uijin.lee
 *4.13.2020
 *digipen.uijin.lee@gmail.com
 *this is limit rotation header
 */
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