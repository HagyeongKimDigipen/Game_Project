
#include "Level1.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

extern bool getOpt;

void Level1::Init()
{
	timer = 0;
	levelCheck = false;
	spaceCheck = false;
	background = OBJECT_FACTORY->CreateEmptyObject();

	getOpt = false;

	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	puzzleLeft = OBJECT_FACTORY->CreateEmptyObject();
	puzzleRight = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();
	mouse = OBJECT_FACTORY->CreateEmptyObject();
	win = OBJECT_FACTORY->CreateEmptyObject();

	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 200.f,280.f });
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->mesh->InitializeTextureMesh();

	blackPuzzle->AddComponent(new Mesh());
	blackPuzzle->Init();
	blackPuzzle->mesh->setTransform({ 0.0f, 120.f });
	blackPuzzle->mesh->InitializeTextureMesh();

	puzzleLeft->AddComponent(new Mesh());
	puzzleLeft->Init();
	puzzleLeft->mesh->setTransform({ -136.f - 40.f, 120.f });
	puzzleLeft->mesh->setRotation(DegreeToRadian(60.f));
	puzzleLeft->mesh->InitializeTextureMesh();

	puzzleRight->AddComponent(new Mesh());
	puzzleRight->Init();
	puzzleRight->mesh->setTransform({ 136.f + 40.f, 120.f });
	puzzleRight->mesh->InitializeTextureMesh();

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -200.f });
	spacePress->mesh->SetMeshType(MESHTYPE::rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(560.f, 80.f);

	mouse->AddComponent(new Mesh());
	mouse->mesh->setTransform({ 650.f, 200.f });
	mouse->mesh->SetMeshType(MESHTYPE::rectangle);
	mouse->Init();
	mouse->mesh->InitializeTextureMesh(550.f, 300.f);
	checking = false;
	win->AddComponent(new Mesh());
	win->mesh->setTransform({ -2000.0f, -2000.0f });
	win->mesh->SetMeshType(MESHTYPE::rectangle);
	win->Init();
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	cur = false;


	opt.Init();
	opt.getInput(&mInput, (this->sound));

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level1::Update()
{
	if (getOpt == true)
	{
		opt.Update();
	}
	else
	{
		cursor = mInput.Cursor;
		if (mInput.IsPressed(KEY::LEFT))
		{
			if (checking == false)
			{
				this->sound->Play("assets\\click.wav", 1);
				checking = true;
			}
		}
		else
		{
			if (checking == true)
			{
				checking = false;
			}
		}




		if (mInput.IsPressed(KEY::F) == true)
		{
			APPLICATION->SetFullScreen();
			mInput.setInput(KEY::F);
		}

		if (movePuzzle->collision->Point2HexagonCollision(cursor, movePuzzle->mesh))
		{
			if (cur == false && mInput.IsPressed(KEY::LEFT) == true)
			{
				cur = true;
			}
		}

		if (cur == true)
		{
			movePuzzle->mesh->setTransform(cursor);
			movable = true;
		}
		if (blackPuzzle->collision->Point2HexagonCollision({ movePuzzle->mesh->GetTransform().x , movePuzzle->mesh->GetTransform().y }, blackPuzzle->mesh))
		{
			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				movable = true;
			}
		}

		if (movable == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				cur = false;
				if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh)))
				{
					{
						if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh))
						{
							this->sound->Play("assets\\fit.flac", 1);

							movePuzzle->mesh->setTransform({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y });
							movable = false;
							levelCheck = true;
							spaceCheck = true;
						}
					}
				}
			}
		}

		if (spaceCheck == true)
		{
			timer += ENGINE->dt;
			//std::cout << timer << std::endl;

			win->mesh->setTransform({ 0,0 });

			if (timer > 2.f)
			{
				STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST2);
			}
		}


		background->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::background1));
		blackPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		puzzleLeft->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzleRight->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		movePuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		mouse->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::clickLeft));
		win->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::next));

		if (mInput.IsPressed(KEY::ESCAPE) == true)
		{
			INPUT->setInput(KEY::ESCAPE);
			getOpt = true;
			if (this->sound->IsMute_() == false)
			{
				this->sound->ToggleMute();
			}
		}

		glfwSwapBuffers(APPLICATION->getMyWindow());

		glClearColor(0.f, 0.f, 0.f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
	}


}

void Level1::Close()
{
	mShader.Delete();
	mMesh.Delete();
	getOpt = false;
	opt.Close();

	OBJECT_FACTORY->DestroyAllObjects();
}