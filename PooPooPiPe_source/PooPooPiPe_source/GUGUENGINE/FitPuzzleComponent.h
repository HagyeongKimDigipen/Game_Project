#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *FitPuzzleComponent.h
 *this is headerflie for fit puzzle component
 */
#include "Component.h"
#include "Mesh.h"


enum PuzzleDirection
{
	NW,
	NE,
	E,
	SE,
	SW,
	W,
};

class [[nodiscard]] PuzzleComponent : public Component
{
public:
	PuzzleComponent() : Component(ComponentType::COMPONENTTYPE_PIPE)
	{
		dirArray1[0] = false;  
		dirArray1[1] = false;
		dirArray1[2] = true;
		dirArray1[3] = false;
		dirArray1[4] = false;
		dirArray1[5] = true;				
	}
	~PuzzleComponent() override
	{
	}
	void Update();
	void SetDirection(bool a, bool b, bool c, bool d, bool e, bool f);
	bool GetDirValue(PuzzleDirection index);
private:
	
	bool dirArray1[6]; // for hex	
	int clickCount = 0;
};

//etc,,,