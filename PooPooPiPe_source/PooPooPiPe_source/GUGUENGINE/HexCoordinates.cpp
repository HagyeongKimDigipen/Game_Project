#include "HexCoordinates.h"

Vector2<float> HexCoordinates::ReturnPuzzleCoor(Vector2<float> center, DirAngle direction, float radius)
{
	Vector2<float>PuzzleCoor = center;
	float angle = 0;

	switch (direction)
	{
	case DirAngle::NE_:
		angle = 0.f;
		break;
	case DirAngle::N_:
		angle = 60.f;
		break;
	case DirAngle::NW_:
		angle = 120.f;
		break;
	case DirAngle::SW_:
		angle = 180.f;
		break;
	case DirAngle::S_:
		angle = -120.f;
		break;
	case DirAngle::SE_:
		angle = -60.f;
		break;
	default:
		break;
	}

	float r = radius;
	angle = DegreeToRadian(angle);

	PuzzleCoor.x = r * cos(angle) + PuzzleCoor.x;
	PuzzleCoor.y = r * sin(angle) + PuzzleCoor.y;

	return PuzzleCoor;
}

bool HexCoordinates::checking()
{
	return true;
}