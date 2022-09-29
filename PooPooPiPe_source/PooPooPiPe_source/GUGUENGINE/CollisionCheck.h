/*
 *juhye.son
 *3.3.2020
 *juhye.son990902@gmail.com
 *CollisionChek.h
 *for make collision check box
 */
#pragma once
#include "Component.h"
#include "Mathematics/Vector2.hpp"
#include "Mesh.h"


class CollisionCheck :public Component{
public:

	CollisionCheck() :Component(ComponentType::COMPONENTTYPE_COLLISIONCHECK) {};

	bool Box2BoxCollision(Mesh* boxA, Mesh* boxB);
	bool Point2BoxCollision(Vector2<float> point, Mesh* box);
	bool Point2HexagonCollision(Vector2<float> point, Mesh* hexagon);

	float GetDeterminant(Vector2<float>::Edge edge, Vector2<float> point);
	float ShortestDistanceSqr(Vector2<float>& p, Vector2<float>::Edge& edge);

	Vector2<float> GetMin(Mesh* mBox);   // bottom-left
	Vector2<float> GetMax(Mesh* mBox);  // top-right
	
private:
	bool isLive = false;
	bool isCollide = false;
};



