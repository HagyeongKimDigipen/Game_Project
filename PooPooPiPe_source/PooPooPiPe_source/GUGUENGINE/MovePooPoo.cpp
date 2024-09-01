#include "ObjectManager.h"
#include "MovePooPoo.h"
#include "Texture.h"
#include "HexagonElements.h"

static unsigned int PuzzleID = 0;
static int OriginID = 0;

MovePooPoo::MovePooPoo() :
	startD({ 0.f, 0.f }), endD({ 50.f, 0.f }), speed(180.f) {

	Init();

};

MovePooPoo::MovePooPoo(Vector2<float> startDirection, Vector2<float> endDirection, int Speed) :
	startD(startDirection), endD(endDirection), speed(static_cast<float>(Speed)) {

	Init();

};
void MovePooPoo::Init()
{
	SetStartD(-700.f, -700.f);
	SetEndD(-700.f, -700.f);
	direction = { -700.f, -700.f };
	realEndD = { -700.f, -700.f };
	setDelta();

	this->isFinish = false;
	this->isSuccess = false;
	this->isHidden = true;

	myAngles.clear();
	coor.clear();

}

void MovePooPoo::SetSpeed(int Speed)
{
	speed = static_cast<float>(Speed);
}
void MovePooPoo::SetStartD(float startX, float startY)
{
	startD = { startX, startY };
	setDelta();
}
void MovePooPoo::SetStartD(Vector2<float> startDirection)
{
	startD = startDirection;
	setDelta();
}
void MovePooPoo::SetEndD(float endX, float endY)
{
	endD = { endX, endY };
	setDelta();
}
void MovePooPoo::SetEndD(Vector2<float> endDirection)
{
	endD = endDirection;
	setDelta();
}
Vector2<float> MovePooPoo::GetEndD()
{
	return endD;
}
Vector2<float> MovePooPoo::GetStartD()
{
	return startD;
}
void MovePooPoo::SetIsSuccess(bool success)
{
	isSuccess = success;
}
void MovePooPoo::Clear()
{
	OriginID = 0;
	PuzzleID = 0;
	SetStartD(-700.f, -700.f);
	SetEndD(-700.f, -700.f);
	direction = { -700.f, -700.f };
	realEndD = { -700.f, -700.f };
}
void MovePooPoo::setDelta()
{
	distance = startD.magnitude({ endD.x - startD.x, endD.y - startD.y });
	direction = startD.normalize({ endD.x - startD.x, endD.y - startD.y });
	betweenDelta = { endD.x - startD.x, endD.y - startD.y };
}

Vector2<float> MovePooPoo::MoveInPuzzle(Vector2<float> nowPosition)
{
	Vector2<float> returnValue = { -700.f, -700.f };
	if (myAngles.size() ==PuzzleID)
	{
		isFinish = true;
		OriginID = 0;
		PuzzleID = 0;
		return { -700.f,-700.f };
	}

	origin = coor[OriginID];
	HexagonCoordinates myCoordinates(origin);
	if (isFirst == true)
	{
		SetStartD(myCoordinates.GetEdgeCenterCoordinates(myAngles[PuzzleID]));
		SetEndD(origin);
	}
	else if (isFirst == false)
	{
		//isSuccess = true;
		SetEndD(myCoordinates.GetEdgeCenterCoordinates(myAngles[PuzzleID]));
		SetStartD(origin);
	}


	if (startD == endD)
	{
		isSuccess = false;
	}

	if (isSuccess == true)
	{

		if (isHidden == true)
		{
			isHidden = false;
			returnValue = startD;
		}
		returnValue = { nowPosition.x+direction.x* speed* elapse, nowPosition.y+direction.y* speed* elapse};
		if (startD.magnitude({ returnValue.x- startD.x,returnValue.y - startD.y }) >= distance)
		{
			isFirst = PuzzleID % 2;
			PuzzleID += 1;

			if (isFirst == true)
			{
				OriginID++;
			}
			returnValue = endD;
		}
	}
	return returnValue;

}
