#pragma once

#include"System.h"
#include<map>
#include<vector>
#include <string>

#include "Mathematics/Vector2.hpp"

class Object;
using ObjectID = unsigned;

enum class Type
{
	Puzzle,
	MovePuzzle,
	BlackPuzzle,
	DirPuzzle,
	shape_rec,
};

class ObjectFactory : public System
{
public:
	ObjectFactory();
	~ObjectFactory();

	void Init() override {}
	void Update() override;

	void Destroy(Object* gameObject);

	void GiveObjectID(Object* gameObject);

	Object* CreateEmptyObject();

	void DestroyAllObjects();

	Object* FindObjectwithName(std::string& name) const;
	Object* FindObjectwithID(ObjectID id) const;

	Object* CreateObject(Type archetype, Vector2<float> transform, float degree = 0,
												float dir1 = 0, float dir2 = 0, float dir3 = 0, float dir4 = 0, float dir5 = 0, float dir6 = 0);

private:
	ObjectID last_objectID;

	std::map<ObjectID, Object*> ObjectIDMap;
	std::vector<Object*> ObjectsToBeDeleted;
};

extern ObjectFactory* OBJECT_FACTORY;
