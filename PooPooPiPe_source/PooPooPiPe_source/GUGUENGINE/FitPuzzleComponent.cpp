#include "FitPuzzleComponent.h"
/*
 *hakyung.kim
 *uijin.lee
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *FitPuzzleComponent.cpp
 *for add component to pipe
 */
void PuzzleComponent::Update()
{
	bool temp = dirArray1[0];
	
	for(int i = 0; i < 6; i++)
	{
		dirArray1[i] = dirArray1[i + 1];
		if(i == 5)
		{
			dirArray1[i] = temp;
		}
		//std::cout << dirArray1[i];
	}
	//std::cout << std::endl;
}

void PuzzleComponent::SetDirection(bool a, bool b, bool c, bool d, bool e, bool f)
{
	dirArray1[0] = a;
	dirArray1[1] = b;
	dirArray1[2] = c;
	dirArray1[3] = d;
	dirArray1[4] = e;
	dirArray1[5] = f;
}

bool PuzzleComponent::GetDirValue(PuzzleDirection index)
{
	return this->dirArray1[index];
}


