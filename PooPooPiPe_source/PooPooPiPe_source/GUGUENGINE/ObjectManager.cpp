
#include "ObjectManager.h"
#include <cassert>
#include "Object.h"
#include <iostream>


extern ObjectFactory* OBJECT_FACTORY = nullptr;

ObjectFactory::ObjectFactory()
{
	//std::cout << "ObjectFactory constructor called" << std::endl;
	assert(OBJECT_FACTORY == nullptr && "ObjectFactory is already created");
	OBJECT_FACTORY = this;
	last_objectID = 0;
}

ObjectFactory::~ObjectFactory()
{}

void ObjectFactory::Update()
{

	for (auto obj : ObjectsToBeDeleted)
	{
		if (obj == nullptr)
			continue;

		auto delete_objID = ObjectIDMap.find(obj->objectID);

		if (delete_objID != ObjectIDMap.end())
		{
			delete obj;
			ObjectIDMap.erase(delete_objID);
		}
	}
	ObjectsToBeDeleted.clear();
}

void ObjectFactory::Destroy(Object* obj)
{
	ObjectsToBeDeleted.push_back(obj);
}

void ObjectFactory::GiveObjectID(Object* obj)
{
	++last_objectID;
	obj->objectID = last_objectID;

	ObjectIDMap[last_objectID] = obj;
}

Object* ObjectFactory::CreateEmptyObject()
{
	Object* obj = new Object();

	GiveObjectID(obj);

	return obj;
}

void ObjectFactory::DestroyAllObjects()
{
	Update();
	for (auto gugu : ObjectIDMap)
		delete gugu.second;

	ObjectIDMap.clear();
}

Object* ObjectFactory::FindObjectwithName(std::string& name) const
{
	for (const auto obj : ObjectIDMap)
	{
		if (obj.second->objName == name)
			return obj.second;
	}
	return nullptr;
}
Object* ObjectFactory::FindObjectwithID(ObjectID id) const
{
	for (const auto obj : ObjectIDMap)
	{
		if (obj.second->GetObjectID() == id)
			return obj.second;
	}
	return nullptr;
}

Object* ObjectFactory::CreateObject(Type archetype, Vector2<float> transform, float degree,
	float dir1, float dir2, float dir3, float dir4, float dir5, float dir6)//does not have ''SetDirection" and "SetAngle"
{
	Object* obj;
	obj = OBJECT_FACTORY->CreateEmptyObject();

	switch (archetype)
	{
	case Type::Puzzle:
	{
		obj->AddComponent(new Mesh());
		obj->AddComponent(new PuzzleComponent());
		obj->pipe->SetDirection(dir1, dir2, dir3, dir4, dir5, dir6);
		obj->Init();
		obj->mesh->setTransform({ transform.x, transform.y });
		obj->mesh->setRotation(DegreeToRadian(degree));
		obj->mesh->InitializeTextureMesh();
		break;
	}
	case Type::MovePuzzle: //have to write down 'SetDirection' in every level
	{
		obj->AddComponent(new Mesh());
		obj->AddComponent(new PuzzleComponent());
		obj->pipe->SetDirection(dir1, dir2, dir3, dir4, dir5, dir6);
		obj->mesh->SetMeshType(MESHTYPE::hexagon);
		obj->Init();
		obj->mesh->setTransform({ transform.x, transform.y });
		obj->mesh->setRotation(DegreeToRadian(degree));
		obj->mesh->InitializeColorMesh();
		break;
	}
	case Type::DirPuzzle: //have to write down 'SetDirection' in every level
	{
		obj->AddComponent(new Mesh());
		obj->AddComponent(new PuzzleComponent());
		obj->pipe->SetDirection(dir1, dir2, dir3, dir4, dir5, dir6);
		obj->Init();
		obj->mesh->setTransform({ transform.x, transform.y });
		obj->mesh->setRotation(DegreeToRadian(degree));
		obj->mesh->InitializeTextureMesh();
		break;
	}
	case Type::BlackPuzzle:
	{
		obj->AddComponent(new Mesh());
		obj->AddComponent(new PuzzleComponent());
		obj->pipe->SetDirection(dir1, dir2, dir3, dir4, dir5, dir6);
		obj->Init();
		obj->mesh->setTransform({ transform.x, transform.y });
		obj->mesh->setRotation(DegreeToRadian(degree));
		obj->mesh->InitializeTextureMesh();
		break;
	}
	case Type::shape_rec:
	{
		obj->AddComponent(new Mesh());
		obj->mesh->setTransform({ transform.x, transform.y });
		obj->mesh->SetMeshType(MESHTYPE::rectangle);
		obj->Init();
		break;
	}
	}

	
	return obj;
}