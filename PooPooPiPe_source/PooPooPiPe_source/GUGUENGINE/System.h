#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *System.h
 *Systems that run all cpp
 */
class System
{
public:
	//Initialize
	virtual void Init() = 0;

	//All Systems update
	virtual void Update()= 0;

	virtual ~System()
	{
	}
};
