/*
 *uijin.lee
 *4.13.2020
 *digipen.uijin.lee@gmail.com
 *this is limit rotation
 */
#include "limitedRotate.h"

int LimitRotate::getLimitTime()
{
	return limitTime;
}

void LimitRotate::Update() //general
{
	--limitTime;
}

void LimitRotate::IncLimit() //color pipe
{
	limitTime += 5;
}

void LimitRotate::DecLimit() //color pipe
{
	limitTime -= 5;
}

void LimitRotate::setRotate(int i)
{
	limitTime = i;
}
