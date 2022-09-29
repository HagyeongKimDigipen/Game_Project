/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Object.cpp
 *to make object
 */
#include"Object.h"
#include <iostream>
#include "ObjectManager.h"
#include <cassert>

Object::Object()
{
	objectID = 0;
	transform = nullptr;
	mesh = nullptr;
	pipe = nullptr;
	coor = nullptr;
	collision = nullptr;
}

Object::~Object()
{
}

void Object::Init()
{
	if (transform != nullptr)
		transform->Init();

	if (mesh != nullptr)
		mesh->Init();
	
	if (pipe != nullptr)
		pipe->Init();

	if (coor != nullptr)
		coor->Init();

	if (collision != nullptr)
		collision->Init();
}

void Object::Destroy(Object* obj)
{
	OBJECT_FACTORY->Destroy(obj);
}

bool Object::AddComponent(Component* component)
{
	component->SetOwner(this);
	switch (component->GetComponentType())
	{
	case ComponentType::COMPONENTTYPE_MESH:
		mesh = dynamic_cast<Mesh*>(component);
		return true;
	case ComponentType::COMPONENTTYPE_TRANSFORM:
		transform = dynamic_cast<Transform*>(component);
		return true;
	case ComponentType::COMPONENTTYPE_PIPE:
		pipe = dynamic_cast<PuzzleComponent*>(component);
		return true;
	case ComponentType::COMPONENTTYPE_COORDINATES:
		coor = dynamic_cast<HexCoordinates*>(component);
		return true;
	case ComponentType::COMPONENTTYPE_COLLISIONCHECK:
		collision = dynamic_cast<CollisionCheck*>(component);
		return true;

	default:
		assert(!"Can't add an unknown component");
		break;
	}
	return false;
}



