#pragma once

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
