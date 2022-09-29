#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Object.h
 *this is object header 
 */
#include<string>
#include "Transform.h"
#include "Mesh.h"
#include "FitPuzzleComponent.h"
#include "HexCoordinates.h"
#include "CollisionCheck.h"
#include "Mathematics/MathFunctions.hpp"
using ObjectID = unsigned;

class ObjectFactory;
class Component;

class Object
{
public:
	friend class ObjectFactory;

	Object();
	~Object();

	void Init();
	void Destroy(Object* obj);

	bool AddComponent(Component* component);

	ObjectID GetObjectID()
	{
		return objectID;
	}
	void SetObjectID(ObjectID objID)
	{
		objectID = objID;
	}
	void SetName(const std::string& name)
	{
		objName = name;
	}
	std::string GetName() const
	{
		return objName;
	}
	std::string objName = "";

	ObjectID objectID;
	Transform* transform;
	Mesh* mesh;
	PuzzleComponent* pipe;
	HexCoordinates* coor;
	CollisionCheck* collision;
};
