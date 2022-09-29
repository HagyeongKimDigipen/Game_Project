#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Mathematics/MathFunctions.hpp"
#include "Mathematics/Vector2.hpp"

enum class DirAngle
{
	NE_,
	N_,
	NW_,
	SW_,
	S_,
	SE_,
};

class [[nodiscard]] HexCoordinates : public Component
{
public:
	HexCoordinates() : Component(ComponentType::COMPONENTTYPE_COORDINATES){}
	~HexCoordinates() override{}

	bool checking();
	void SetAngle(){}
	//void Update();
	Vector2<float> ReturnPuzzleCoor(Vector2<float> center,  DirAngle direction, float radius);

private:
	float CoorAngle[6] = { 30.f, 90.f, 150.f, -150.f, -90.f, -30.f}; // for hex	
};

