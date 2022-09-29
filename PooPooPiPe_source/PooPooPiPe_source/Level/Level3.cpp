/*
 *hakyung.kim
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *Level3.cpp
 *if you want to check pipe connect, you can remove "//"pipe connect
 *this is level3
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level3.h"

#include "../GUGUENGINE/Sound.h"

extern int MaxLevel;
extern bool getOpt;

void Level3::Init()
{
	current = 1;

	getOpt = false;

	timer = 0;
	timer2 = 0;

	if (MaxLevel <= 1)
	{
		MaxLevel = 1;
	}
	Nos[0] = false;
	Nos[1] = false;

	Cur[0] = false;
	Cur[1] = false;
	Cur[2] = false;
	
	SUI[0] = false;
	SUI[1] = false;
	SUI[2] = false;
	SUI[3] = false;
	SUI[4] = false;
	checking = false;

	mInput.setInput(KEY::LEFT);

	QuitAskBack = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	QuitAskBack->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	QuitAsk = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	QuitAsk->mesh->InitializeTextureMesh(700.f, 500.f);

	Yes = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	Yes->mesh->InitializeTextureMesh(140.f, 70.f);

	No = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	No->mesh->InitializeTextureMesh(140.f, 70.f);

	Yes_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	Yes_p->mesh->InitializeTextureMesh(140.f, 70.f);

	No_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	No_p->mesh->InitializeTextureMesh(140.f, 70.f);


	quitCheck = false;
	realQuit = false;

	chekNext = 0;

	skip = false;
	failS = false;

	conecTcheck1 = false;
	conecTcheck2 = false;
	conecTcheck3 = false;

	degree2 = 0;
	degree2_2 = 0;
	degree2_3 = 0;

	blCheck1 = false;
	blCheck1_2 = false;

	blCheck2 = false;
	blCheck2_2 = false;

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 0,
		false, false, false, true, false, true);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);

	playUI_p = OBJECT_FACTORY->CreateEmptyObject();
	playUI_p->AddComponent(new Mesh());
	playUI_p->Init();

	playUI_p->mesh->setTransform({ 1713.5f, 300.f });
	playUI_p->mesh->InitializeTextureMesh(173.f, 200.f);

	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->InitializeTextureMesh(173.f, 200.f);

	quitUI_p = OBJECT_FACTORY->CreateEmptyObject();
	quitUI_p->AddComponent(new Mesh());
	quitUI_p->Init();

	quitUI_p->mesh->setTransform({ 1800.f, 150.f });
	quitUI_p->mesh->InitializeTextureMesh(173.f, 200.f);

	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);

	optionUI_p = OBJECT_FACTORY->CreateEmptyObject();
	optionUI_p->AddComponent(new Mesh());
	optionUI_p->Init();
	optionUI_p->mesh->setTransform({ 1713.5f, 0.f });
	optionUI_p->mesh->InitializeTextureMesh(173.f, 200.f);

	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->InitializeTextureMesh(173.f, 200.f);

	restartUI_p = OBJECT_FACTORY->CreateEmptyObject();
	restartUI_p->AddComponent(new Mesh());
	restartUI_p->Init();
	restartUI_p->mesh->setTransform({ 1800.f, -150.f });
	restartUI_p->mesh->InitializeTextureMesh(173.f, 200.f);

	mPooPoo.Init();
	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 280.f + 50.f }, 60.f);
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 280.f + 50.f });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 180.f);
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 482.f, 160.f + 22.f });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, 160.f + 22.f }, 120.f);
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f }, 240.f);
	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 482.f, -80.0f - 32.f });
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, -80.f - 32.f }, 60.f);
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, -80.f - 32.f }, 60.f);
	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 60.f);
	puzzle12 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, -200.f - 62.f });

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 140.f - 415.f, 160.f + 22.f });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -64.f - 465.f, 40.f - 5.f });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -268.f - 519.f, -80.f - 32.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 280.f + 50.f }, -240.f);
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f });

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });

	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });

	//se3.Init();
	//se3.LoadSE("assets\\coin.wav");

	//playSE3.Init();
	//playSE3.LoadSE("assets\\flushing.wav");

	mShader2.BuildTextureShader();
	mShader.BuildTextureShader();

	movePuzzle2->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);
	endPuzzle->pipe->SetDirection(true, false, false, false, false, false);
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);
	puzzle6->pipe->SetDirection(false, false, true, false, true, false);
	puzzle7->pipe->SetDirection(false, true, false, false, false, true);


	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));


	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SW_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle6->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, endPuzzle->mesh->GetTransform());

	opt.Init();
	opt.getInput(&mInput, (this->sound));

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level3::Update()
{
	if(current < 5)
	{
		current = 5;

		if(this->sound->soundCheck("BGM_another.wav") == true)
		{
			this->sound->StopSound("BGM_another.wav");
			this->sound->Play("assets\\BGM_new.flac", -1);
		}
		else if (this->sound->soundCheck("BGM_theother.wav") == true)
		{
			this->sound->StopSound("BGM_theother.mpe");
			this->sound->Play("assets\\BGM_new.flac", -1);
		}
	}
	
	if (getOpt == true)
	{
		opt.Update();
	}
	else
	{
		cursor3 = mInput.Cursor;

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

		if (Levelsel->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, Levelsel->mesh) == true)
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[4] == false)
				{
					UI[4] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
				{
					//std::cout << "check" << std::endl;
					STATE_MANAGER->ChangeLevel(GameLevels::LV_SELECT);
				}
			}
		}
		else
		{
			UI[4] = false;
			Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
		}

		if (movePuzzle->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle->mesh) == true)
		{
			if (SUI[0] == false && Cur[0] == false && Cur[1] == false && Cur[2] == false)
			{
				SUI[0] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}

			if (Cur[0] == false && mInput.IsPressed(KEY::LEFT) == true && !movable[1] && !movable[2])
			{
				Cur[0] = true;
			}

			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[0] = true;
			}
			if (rot[0] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					movePuzzle->pipe->Update();
					degree2 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle->mesh->setRotation(degree2);
					this->sound->Play("assets\\coin.wav", 1);
					rot[0] = false;
				}
			}
		}
		else
		{
			SUI[0] = false;
			movable[0] = false;
		}

		if (Cur[0] == true)
		{
			movePuzzle->mesh->setTransform({ cursor3.x, cursor3.y });
			movable[0] = true;
		}

		if (blCheck1)
		{
			if ((movePuzzle->pipe->GetDirValue(NW) == 1 && puzzle2->pipe->GetDirValue(SE) == 1) && (movePuzzle->pipe->GetDirValue(SW) == 1 && puzzle7->pipe->GetDirValue(NE) == 1))
			{
				//std::cout << "pipe connect\n";
				conecTcheck1 = true;
			}
			else
			{
				conecTcheck1 = false;
				//std::cout << "Not connect\n";
			}
		}
		if (blCheck1_2)
		{
			if ((movePuzzle->pipe->GetDirValue(NE) == 1 && puzzle6->pipe->GetDirValue(SW) == 1) && (movePuzzle->pipe->GetDirValue(SE) == 1 && endPuzzle->pipe->GetDirValue(NW) == 1))
			{
				conecTcheck1 = true;
				//std::cout << "pipe connect\n";
			}
			else
			{
				conecTcheck1 = false;
				//std::cout << "Not connect\n";
			}
		}

		if (movePuzzle2->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle2->mesh) == true)
		{
			if (SUI[1] == false && Cur[0] == false && Cur[1] == false && Cur[2] == false)
			{
				SUI[1] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}
			if (Cur[1] == false && mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[2])
			{
				Cur[1] = true;

			}
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[1] = true;
			}
			if (rot[1] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					movePuzzle2->pipe->Update();

					degree2_2 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle2->mesh->setRotation(degree2_2);
					this->sound->Play("assets\\coin.wav", 1);
					rot[1] = false;
				}
			}

		}
		else
		{
			SUI[1] = false;
			movable[1] = false;
		}
		if (Cur[1] == true)
		{
			movePuzzle2->mesh->setTransform({ cursor3.x, cursor3.y });
			movable[1] = true;
		}
		if ((movePuzzle2->pipe->GetDirValue(E) == puzzle7->pipe->GetDirValue(W)) && (movePuzzle2->pipe->GetDirValue(W) == puzzle6->pipe->GetDirValue(E)))
		{
			conecTcheck2 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck2 = false;
			//std::cout << "Not connect\n";
		}

		if (movePuzzle3->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle3->mesh) == true)
		{
			if (SUI[2] == false && Cur[0] == false && Cur[1] == false && Cur[2] == false)
			{
				SUI[2] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}
			if (Cur[2] == false && mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1])
			{
				Cur[2] = true;

			}
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[2] = true;
			}
			if (rot[2] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					movePuzzle3->pipe->Update();
					degree2_3 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle3->mesh->setRotation(degree2_3);
					this->sound->Play("assets\\coin.wav", 1);
					rot[2] = false;
				}
			}
		}
		else
		{
			SUI[2] = false;
			movable[2] = false;
		}

		if (Cur[2] == true)
		{
			movePuzzle3->mesh->setTransform({ cursor3.x, cursor3.y });
			movable[2] = true;
		}

		if (blCheck2)
		{
			if ((movePuzzle3->pipe->GetDirValue(NW) == puzzle2->pipe->GetDirValue(SE)) && (movePuzzle3->pipe->GetDirValue(SW) == puzzle7->pipe->GetDirValue(NE)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck3 = true;
			}
			else
			{
				conecTcheck3 = false;
				//std::cout << "Not connect\n";
			}
		}
		if (blCheck2_2)
		{
			if ((movePuzzle3->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(SE) == endPuzzle->pipe->GetDirValue(NW)))
			{
				conecTcheck3 = true;
				//std::cout << "pipe connect\n";
			}
			else
			{
				conecTcheck3 = false;
				//std::cout << "Not connect\n";
			}
		}
		if (movable[0] == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				Cur[0] = false;

				if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))
				{
					if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
						movable[0] = false;
						blCheck1 = true;
						blCheck1_2 = false;
					}
					else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						movable[0] = false;
						blCheck1_2 = false;
						blCheck1 = false;
					}
					else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						movable[0] = false;
						blCheck1_2 = true;
						blCheck1 = false;
					}
				}
			}
			else
			{
				conecTcheck1 = false;
			}
		}
		if (movable[1] == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				Cur[1] = false;
				if ((movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh)))
				{
					if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle2->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
						movable[1] = false;
					}
					if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle2->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						movable[1] = false;
					}
					if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle2->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						movable[1] = false;
					}
				}
			}
			else
			{
				conecTcheck2 = false;
			}
		}
		if (movable[2] == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				Cur[2] = false;
				{
					if ((movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh)))
						if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh))
						{
							this->sound->Play("assets\\fit.flac", 1);
							movePuzzle3->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
							movable[2] = false;
							blCheck2 = true;
							blCheck2_2 = false;
						}
					if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						movable[2] = false;

						blCheck2 = false;
						blCheck2_2 = false;
					}
					if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						this->sound->Play("assets\\fit.flac", 1);
						movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						movable[2] = false;
						blCheck2 = false;
						blCheck2_2 = true;
					}
				}
			}
			else
			{
				conecTcheck3 = false;
			}
		}

		if (playUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, playUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[0] == false)
				{
					UI[0] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				playUI_p->mesh->setTransform(playUI->mesh->GetTransform());
				if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
				{
					INPUT->setInput(KEY::LEFT);
					poopooCheck = true;

				}
			}
		}
		else
		{
			UI[0] = false;
			playUI_p->mesh->setTransform({ 1000.f, 1000.f });
			connectMove = 0;
		}

		if (poopooCheck == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				INPUT->setInput(KEY::LEFT);

				if (conecTcheck1 && conecTcheck2 && conecTcheck3)
				{
					//std::cout << "if 3" << std::endl;
					clear->mesh->setTransform({ 350.f, -240.f });
					chekNext = 1;
					//std::cout << "clear" << std::endl;
					connectMove = 0;
					mPooPoo.SetIsSuccess(true);

					this->sound->Play("assets\\flushing.wav", 1);
					poopooCheck = false;

				}
				else
				{
					if (failS == false)
					{
						this->sound->Play("assets\\fart.mp3", 1);
						failS = true;
					}
					timer += ENGINE->dt;
					if (timer > 1.5)
					{
						Nos[0] = true;
						fail->mesh->setTransform({ 0,0 });
						failS = false;
						poopooCheck = false;

					}
				}
			}

		}

		if (fail->collision->Point2BoxCollision({ cursor3.x,cursor3.y }, fail->mesh))
		{
			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				INPUT->setInput(KEY::LEFT);
				Nos[0] = true;
				fail->mesh->setTransform({ -2000.f,-2000.f });
				STATE_MANAGER->ReloadState();
			}
		}

		if (restartUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, restartUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[1] == false)
				{
					UI[1] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				restartUI_p->mesh->setTransform(restartUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
				{
					INPUT->setInput(KEY::LEFT);
					STATE_MANAGER->ReloadState();
				}
			}
		}
		else
		{
			UI[1] = false;
			restartUI_p->mesh->setTransform({ 1700.f, 1000.f });
		}

		if (optionUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, optionUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[2] == false)
				{
					UI[2] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				optionUI_p->mesh->setTransform(optionUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
				{
					INPUT->setInput(KEY::LEFT);
					getOpt = true;
					if (this->sound->IsMute_() == false)
					{
						this->sound->ToggleMute();
					}
				}
			}
		}
		else
		{
			UI[2] = false;
			optionUI_p->mesh->setTransform({ 1000.f, 1000.f });
		}

		if (quitUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, quitUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[3] == false)
				{
					UI[3] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				quitUI_p->mesh->setTransform(quitUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
				{
					
					INPUT->setInput(KEY::LEFT);
					if (quitCheck == false)
					{
						if (mPooPoo.GetIsSuccess() == true)
						{
							this->sound->pauseSound("assets\\flushing.wav");
							mPooPoo.SetIsSuccess(false);
						}
						Nos[1] = true;
						quitCheck = true;
						QuitAskBack->mesh->setTransform({ 0.f, 0.f });
						QuitAsk->mesh->setTransform({ 0.f, 0.f });
						Yes->mesh->setTransform({ -100.f, -50.f });
						No->mesh->setTransform({ 100.f, -50.f });
						
					}
				}
			}
		}
		else
		{
			UI[3] = false;
			
			quitUI_p->mesh->setTransform({ 1000.f, 1000.f });
		}

		if (Yes->collision->Point2BoxCollision(cursor3, Yes->mesh))
		{
			if (SUI[3] == false)
			{
				SUI[3] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}
			Yes_p->mesh->setTransform(Yes->mesh->GetTransform());
			if (mInput.IsPressed(KEY::LEFT))
			{
				INPUT->setInput(KEY::LEFT);
				realQuit = true;
			}
		}
		else
		{
			SUI[3] = false;
			Yes_p->mesh->setTransform({ -1000.f, -1000.f });
		}

		if (No->collision->Point2BoxCollision(cursor3, No->mesh))
		{
			if (SUI[4] == false)
			{
				SUI[4] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}
			No_p->mesh->setTransform(No->mesh->GetTransform());
			if (mInput.IsPressed(KEY::LEFT))
			{
				if (mPooPoo.GetIsHidden() == false)
				{
					this->sound->resumeSound("assets\\flushing.wav");
					mPooPoo.SetIsSuccess(true);
				}
				INPUT->setInput(KEY::LEFT);
				quitCheck = false;
				realQuit = false;
				Nos[1] = false;
				QuitAsk->mesh->setTransform({ -2000.f, -2000.f });
				QuitAskBack->mesh->setTransform({ -2000.f, -2000.f });
				Yes->mesh->setTransform({ -2000.f, -2000.f });
				No->mesh->setTransform({ -2000.f, -2000.f });
			}
		}
		else
		{
			SUI[4] = false;
			No_p->mesh->setTransform({ -1000.f, -1000.f });
		}

		if (mPooPoo.IsFinish() == false)
		{
			pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
		}

		if (quitCheck == true && realQuit == true)
		{
			glfwTerminate();
			ENGINE->Quit();
		}

		Vector2<float> pooCoor = pooCharacter->mesh->GetTransform();
		Vector2<float> endCoor = endPuzzle->mesh->GetTransform();

		if (pooCoor.x == endCoor.x && pooCoor.y == endCoor.y)
		{
			if (skip == false)
			{
				this->sound->Play("assets\\yeah.wav", 1);
			}
			skip = true;
			win->mesh->setTransform({ 0,0 });
		}


		if (skip == true)
		{
			timer2 += ENGINE->dt;

			if (timer2 > 1.5)
			{
				STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST4);
			}
		}


		background->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::background1));
		puzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle4->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle5->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle6->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle7->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		puzzle8->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle9->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle10->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle11->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle12->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));

		startPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageStart));
		endPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageEnd));

		movePuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));
		movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::image01));
		movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));

		button->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::character));
		clear->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::clear));
		Levelsel->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::levelButton));
		Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::levelButton_2));
		playUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::playUI));
		quitUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitUI));
		optionUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionUI));
		restartUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::restartUI));
		restartUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::restartUI_2));
		playUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::playUI_2));
		quitUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitUI_2));
		optionUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionUI_2));
		levelImage->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::level));
		numberImage->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::num1));

		pooCharacter->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::character));

		win->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::next));
		fail->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::failScreen));

		QuitAskBack->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));
		QuitAsk->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::QUITCHECK));
		Yes->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES));
		No->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::no));
		Yes_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES_P));
		No_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::NO_P));

		if (mInput.IsPressed(KEY::A) == true)
		{
			INPUT->setInput(KEY::A);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST4);
		}

		if (mInput.IsPressed(KEY::ESCAPE) == true) {
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

void Level3::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	sound->StopEffectSound();
	getOpt = false;
	opt.Close();

	OBJECT_FACTORY->DestroyAllObjects();
}


