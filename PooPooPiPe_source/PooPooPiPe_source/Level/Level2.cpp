/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level2.cpp
 *this is level2
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level2.h"
#include "../GUGUENGINE/Sound.h"

Sound se2;

extern bool getOpt;

void Level2::Init()
{
	timer = 0;
	timer2 = 0;
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();

	getOpt = false;

	degree = 0;
	checkToPipe = 0;
	spaceCheck = false;
	click = 0;

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	puzzleUp = OBJECT_FACTORY->CreateEmptyObject();
	puzzleDown = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();
	mouse = OBJECT_FACTORY->CreateEmptyObject();
	playbutton = OBJECT_FACTORY->CreateEmptyObject();
	pressPlay1 = OBJECT_FACTORY->CreateEmptyObject();
	pressPlay2 = OBJECT_FACTORY->CreateEmptyObject();
	playPressButton = OBJECT_FACTORY->CreateEmptyObject();
	win = OBJECT_FACTORY->CreateEmptyObject();

	se2.Init();
	se2.LoadMusic("assets\\coin.wav");

	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->AddComponent(new PuzzleComponent());
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 160.0f, 280.0f });
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->pipe->SetDirection(false, false, true, false, false, true);
	movePuzzle->mesh->SetMeshType(MESHTYPE::hexagon);
	movePuzzle->mesh->InitializeTextureMesh();

	blackPuzzle->AddComponent(new Mesh());
	blackPuzzle->mesh->SetMeshType(MESHTYPE::hexagon);
	blackPuzzle->Init();
	blackPuzzle->mesh->setTransform({ 0.0f, 120.0f });
	blackPuzzle->mesh->InitializeTextureMesh();

	puzzleUp->AddComponent(new Mesh());
	puzzleUp->AddComponent(new PuzzleComponent());
	puzzleUp->Init();
	puzzleUp->mesh->setTransform({ -85.f, 228.8f + 40.f });
	puzzleUp->mesh->setRotation(DegreeToRadian(180.f));
	puzzleUp->pipe->SetDirection(true, false, false, true, false, false);
	puzzleUp->mesh->SetMeshType(MESHTYPE::hexagon);
	puzzleUp->mesh->InitializeTextureMesh();

	puzzleDown->AddComponent(new Mesh());
	puzzleDown->AddComponent(new PuzzleComponent());
	puzzleDown->Init();
	puzzleDown->mesh->setTransform({ 72.f + 10.f, 10.f - 40.f });
	puzzleDown->mesh->setRotation(DegreeToRadian(180.f));
	puzzleDown->pipe->SetDirection(true, false, true, false, false, false);
	puzzleDown->mesh->SetMeshType(MESHTYPE::hexagon);
	puzzleDown->mesh->InitializeTextureMesh();

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -160.f });
	spacePress->mesh->SetMeshType(MESHTYPE::rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(560.f, 80.f);

	mouse->AddComponent(new Mesh());
	mouse->mesh->setTransform({ 550.f, 200.f });
	mouse->mesh->SetMeshType(MESHTYPE::rectangle);
	mouse->Init();
	mouse->mesh->InitializeTextureMesh(550.f, 300.f);

	playbutton->AddComponent(new Mesh());
	playbutton->AddComponent(new PuzzleComponent());
	playbutton->mesh->setTransform({ -2000, -2000.f });
	playbutton->Init(); 
	playbutton->mesh->SetMeshType(MESHTYPE::hexagon);
	playbutton->mesh->InitializeTextureMesh(400.f,400.f);

	playPressButton->AddComponent(new Mesh());
	playPressButton->AddComponent(new PuzzleComponent());
	playPressButton->mesh->setTransform({ -2000, -2000.f });
	playPressButton->Init();
	playPressButton->mesh->SetMeshType(MESHTYPE::hexagon);
	playPressButton->mesh->InitializeTextureMesh(400.f, 400.f);

	pressPlay1->AddComponent(new Mesh());
	pressPlay1->mesh->setTransform({ -2000.f, -2000.f });
	pressPlay1->mesh->SetMeshType(MESHTYPE::rectangle);
	pressPlay1->Init();
	pressPlay1->mesh->InitializeTextureMesh(500.f, 250.f);

	pressPlay2->AddComponent(new Mesh());
	pressPlay2->mesh->setTransform({ -2000.f, -2000.f });
	pressPlay2->mesh->SetMeshType(MESHTYPE::rectangle);
	pressPlay2->Init();
	pressPlay2->mesh->InitializeTextureMesh(500.f,350.f);
	checking = false;
	win->AddComponent(new Mesh());
	win->mesh->setTransform({ -2000.0f, -2000.0f });
	win->mesh->SetMeshType(MESHTYPE::rectangle);
	win->Init();
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	cur = false;
	fit = false;

	opt.Init();
	opt.getInput(&mInput, (this->sound));


	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level2::Update()
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

		se2.Update();


		if (movePuzzle->collision->Point2HexagonCollision({ cursor.x,cursor.y }, movePuzzle->mesh) == true)
		{
			if (cur == false && mInput.IsPressed(KEY::LEFT) == true)
			{
				cur = true;

			}

			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot = true;
			}
			if (rot == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					movePuzzle->pipe->Update();

					degree += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle->mesh->setRotation(degree + DegreeToRadian(60.f));
					this->sound->Play("assets\\coin.wav", 1);

					rot = false;
				}
			}
		}
		if (cur == true)
		{
			movePuzzle->mesh->setTransform({ cursor.x, cursor.y });
		}

		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			cur = false;
			if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh)))
			{
				{
					if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						if (fit == false)
						{
							fit = true;
							this->sound->Play("assets\\fit.flac", 1);
						}

						movePuzzle->mesh->setTransform({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y });
					}
				}
			}
			else
			{
				fit = false;
			}
		}

		if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh) == true)
		{
			if (movePuzzle->pipe->GetDirValue(SE) && movePuzzle->pipe->GetDirValue(NW))
			{
				checkToPipe = 1;
			}
			else
			{
				checkToPipe = 0;
			}
		}

		if (checkToPipe)
		{
			timer += ENGINE->dt;
			if (timer > 0.5f)
			{
				pressPlay1->mesh->setTransform({ 550.f,100.f });
				playbutton->mesh->setTransform({ 500.f,300.f });
				mouse->mesh->setTransform({ -2000.f,-2000.f });
				pressPlay2->mesh->setTransform({ 550.f,-150.f });

				if (playbutton->collision->Point2HexagonCollision({ cursor.x,cursor.y }, playbutton->mesh) == true)
				{
					playPressButton->mesh->setTransform({ 500.f,300.f });

					if (mInput.IsPressed(KEY::LEFT) == true && !click)
					{
						mInput.setInput(KEY::LEFT);
						spaceCheck = true;
						click = true;
					}
					else
					{
						click = false;
					}
				}
				else
				{
					playPressButton->mesh->setTransform({ -2000.f,-200.f });
				}
			}
		}

		if (spaceCheck)
		{
			timer2 += ENGINE->dt;
			//std::cout << timer << std::endl;

			win->mesh->setTransform({ 0,0 });

			if (timer2 > 2.f)
			{
				STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
			}
		}

		se2.Update();

		background->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::background1));
		blackPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		puzzleUp->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzleDown->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		movePuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		mouse->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::clickRight));
		playbutton->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::playUI));
		pressPlay1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::clickPlayButton));
		pressPlay2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::clickPlayButton2));
		playPressButton->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::playUI_2));

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

void Level2::Close()
{
	mShader.Delete();
	mMesh.Delete();
	getOpt = false;
	opt.Close();

	OBJECT_FACTORY->DestroyAllObjects();
}
