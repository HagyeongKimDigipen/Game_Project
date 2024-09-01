
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level5.h"
#include "../GUGUENGINE/Sound.h"

extern int MaxLevel;
extern bool getOpt;

void Level5::Init()
{
	current = 5;
	getOpt = false;
	one = false;
	if (MaxLevel <= 5)
	{
		MaxLevel = 5;
	}

	timer = 0;
	timer2 = 0;
	timer3 = 0;

	skip = false;
	failS = false;
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
	PUT[0] = false;
	PUT[1] = false;
	PUT[2] = false;
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

	chekNext5 = 0;

	conecTcheck5_1 = false;
	conecTcheck5_2 = false;
	conecTcheck5_3 = false;

	degree5 = 0;
	degree5_2 = 0;
	degree5_3 = 0;

	blCheck5 = false;
	blCheck5_2 = false;
	blCheck5_3 = false;

	blCheck6 = false;
	blCheck6_2 = false;
	blCheck6_3 = false;

	blCheck7 = false;
	blCheck7_2 = false;
	blCheck7_3 = false;

	movePuzzleCheck5 = true;

	Yellow = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	Yellow->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	yellowS = false;

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	mini = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 330.f, 200.f });
	mini->mesh->InitializeTextureMesh(500.f, 500.f);

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

	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

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

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	mShader2.BuildTextureShader();
	yShader.BuildTextureShader();

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f - 250.f, 280.f });
	movePuzzle->pipe->SetDirection(false, false, false, true, false, true);

	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f - 250.f, 120.f });
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);

	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f - 250.f, 0.0f });
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 280.f + 50.f });
	startPuzzle->pipe->SetDirection(true, false, false, true, false, false);
	startPuzzle->mesh->setRotation(DegreeToRadian(-120.f));

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, -300);
	endPuzzle->pipe->SetDirection(false, false, false, true, false, true);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 280.f + 50.f }, 60.f);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 72.f - 430.f, 280.f + 50.f });

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 180.f);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, 160.f + 22.f });

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f }, 60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f }, 0);//0
	puzzle7->pipe->SetDirection(true, false, true, false, false, true);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f });

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f }, 180.f);
	puzzle9->pipe->SetDirection(false, false, true, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, -80.f - 32.f }, -60.f);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f });

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	puzzle12->pipe->SetDirection(false, true, true, false, false, false);

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -132.f - 482.f, 160.f + 22.f });

	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 4.0f - 448.f, 160.f + 22.f });

	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -132.f - 482.f, -80.0f - 32.f });

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	button->mesh->InitializeTextureMesh(300.f, 300.f);

	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	clear->mesh->InitializeTextureMesh(380.f, 150.f);


	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });

	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::NE_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle11->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, endPuzzle->mesh->GetTransform());
	siren = false;

	opt.Init();
	opt.getInput(&mInput, (this->sound));
	if (current >= 5)
	{
		current = 4;
		if (this->sound->soundCheck("BGM_new.flac") == true)
		{
			this->sound->StopSound("BGM_new.flac");
			this->sound->Play("assets\\BGM_another.wav", -1);
		}
		else if (this->sound->soundCheck("BGM_theother.wav") == true)
		{
			this->sound->StopSound("BGM_theother.wav");
			this->sound->Play("assets\\BGM_another.wav", -1);
		}
	}
	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level5::Update()
{

	if (getOpt == true)
	{
		opt.Update();
	}
	else
	{
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

		if (yellowS == false)
		{
			if (siren == false)
			{
				siren = true;
				this->sound->Play("assets\\siren.wav", 1);
			}
			yellowS = true;
			Yellow->mesh->setTransform({ 0.f, 0.f });
		}

		timer += ENGINE->dt;

		if (timer >= 3.f)
		{
			siren = false;
			Yellow->mesh->setTransform({ -2000.f, -2000.f });
		}

		cursor5 = mInput.Cursor;

		if (mInput.IsPressed(KEY::F) == true)
		{
			APPLICATION->SetFullScreen();
			mInput.setInput(KEY::F);
		}

		if (Levelsel->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, Levelsel->mesh) == true)
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
					INPUT->setInput(KEY::LEFT);
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
		
		if (movePuzzle->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, movePuzzle->mesh))
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

					degree5 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle->mesh->setRotation(degree5);

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
			movePuzzle->mesh->setTransform({ cursor5.x, cursor5.y });
			movable[0] = true;
		}

		if (blCheck5)
		{
			if (blCheck6_2)
			{
				if ((movePuzzle->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle->pipe->GetDirValue(E) == movePuzzle2->pipe->GetDirValue(W)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_1 = true;
				}
				else
				{
					conecTcheck5_1 = false;
					//std::cout << "Not connect\n";
				}
			}
			else if (blCheck7_2)
			{
				if ((movePuzzle->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle->pipe->GetDirValue(E) == movePuzzle3->pipe->GetDirValue(W)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_1 = true;
				}
				else
				{
					conecTcheck5_1 = false;
					//std::cout << "Not connect\n";
				}
			}
		}
		if (blCheck5_2)
		{
			if (blCheck6)
			{
				if ((movePuzzle->pipe->GetDirValue(W) == movePuzzle2->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_1 = true;
				}
				else
				{
					conecTcheck5_1 = false;
					//std::cout << "Not connect\n";
				}
			}
			else if (blCheck7)
			{
				if ((movePuzzle->pipe->GetDirValue(W) == movePuzzle3->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_1 = true;
				}
				else
				{
					conecTcheck5_1 = false;
					//std::cout << "Not connect\n";
				}
			}
		}
		if (blCheck5_3)
		{
			if ((movePuzzle->pipe->GetDirValue(E) && puzzle9->pipe->GetDirValue(W)) && (movePuzzle->pipe->GetDirValue(SW) == puzzle12->pipe->GetDirValue(NE)))
			{
				conecTcheck5_1 = true;
				//std::cout << "pipe connect\n";
			}
			else
			{
				conecTcheck5_1 = false;
				//std::cout << "Not connect\n";
			}
		}

		if (movePuzzle2->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, movePuzzle2->mesh))
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

					degree5_2 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle2->mesh->setRotation(degree5_2);

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
			movePuzzle2->mesh->setTransform({ cursor5.x, cursor5.y });
			movable[1] = true;
		}
		if (blCheck6)
		{
			if (blCheck5_2)
			{
				if ((movePuzzle2->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(E) == movePuzzle->pipe->GetDirValue(W)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_2 = true;
				}
				else
				{
					conecTcheck5_2 = false;
					//std::cout << "Not connect\n";
				}
			}
			if (blCheck7_2)
			{
				if ((movePuzzle2->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(E) == movePuzzle3->pipe->GetDirValue(W)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_2 = true;
				}
				else
				{
					conecTcheck5_2 = false;
					//std::cout << "Not connect\n";
				}
			}
		}
		if (blCheck6_2)
		{
			if (blCheck5)
			{
				if ((movePuzzle2->pipe->GetDirValue(W) == movePuzzle->pipe->GetDirValue(E)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_2 = true;
				}
				else
				{
					conecTcheck5_2 = false;
					//std::cout << "Not connect\n";
				}
			}
			if (blCheck7)
			{
				if ((movePuzzle2->pipe->GetDirValue(W) == movePuzzle3->pipe->GetDirValue(E)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_2 = true;
				}
				else
				{
					conecTcheck5_2 = false;
					//std::cout << "Not connect\n";
				}
			}
		}

		if (blCheck6_3)
		{
			if ((movePuzzle2->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (movePuzzle2->pipe->GetDirValue(SW) == puzzle12->pipe->GetDirValue(NE)))
			{
				conecTcheck5_2 = true;
				//std::cout << "pipe connect\n";
			}
			else
			{
				conecTcheck5_2 = false;
				//std::cout << "Not connect\n";
			}
		}

		if (movePuzzle3->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, movePuzzle3->mesh))
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
					{
						movePuzzle3->pipe->Update();
						degree5_3 += static_cast<float>(DegreeToRadian(60.f));
						movePuzzle3->mesh->setRotation(degree5_3);

						this->sound->Play("assets\\coin.wav", 1);

						rot[2] = false;
					}
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
			movePuzzle3->mesh->setTransform({ cursor5.x, cursor5.y });
			movable[2] = true;
		}

		if (blCheck7)
		{
			if (blCheck5_2)
			{
				if ((movePuzzle3->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(E) == movePuzzle->pipe->GetDirValue(W)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_3 = true;
				}
				else
				{
					conecTcheck5_3 = false;
					//std::cout << "Not connect\n";
				}
			}
			else if (blCheck6_2)
			{
				if ((movePuzzle3->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(E) == movePuzzle2->pipe->GetDirValue(W)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_3 = true;
				}
				else
				{
					conecTcheck5_3 = false;
					//std::cout << "Not connect\n";
				}
			}
		}
		if (blCheck7_2)
		{
			if (blCheck5)
			{
				if ((movePuzzle3->pipe->GetDirValue(W) == movePuzzle->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_3 = true;
				}
				else
				{
					conecTcheck5_3 = false;
					//std::cout << "Not connect\n";
				}
			}
			else if (blCheck6)
			{
				if ((movePuzzle3->pipe->GetDirValue(W) == movePuzzle2->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
				{
					//std::cout << "pipe connect\n";
					conecTcheck5_3 = true;
				}
				else
				{
					conecTcheck5_3 = false;
					//std::cout << "Not connect\n";
				}
			}
		}
		if (blCheck7_3)
		{
			if ((movePuzzle3->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (movePuzzle3->pipe->GetDirValue(SW) == puzzle12->pipe->GetDirValue(NE)))
			{
				conecTcheck5_3 = true;
				//std::cout << "pipe connect\n";
			}
			else
			{
				conecTcheck5_3 = false;
				//std::cout << "Not connect\n";
			}
		}

		//
		if (movable[0] == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				Cur[0] = false;
				if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))
				{
					{
						if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh))
						{
							if (PUT[0] == false)
							{
								this->sound->Play("assets\\fit.flac", 1);
								PUT[0] = true;
							}
							movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
							movable[0] = false;
							blCheck5 = true;
							blCheck5_2 = false;
							blCheck5_3 = false;
						}
						else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
						{
							if (PUT[0] == false)
							{
								this->sound->Play("assets\\fit.flac", 1);
								PUT[0] = true;
							}
							movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
							movable[0] = false;
							blCheck5 = false;
							blCheck5_2 = true;
							blCheck5_3 = false;
						}
						else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
						{
							if (PUT[0] == false)
							{
								this->sound->Play("assets\\fit.flac", 1);
								PUT[0] = true;
							}
							movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
							movable[0] = false;
							blCheck5 = false;
							blCheck5_2 = false;
							blCheck5_3 = true;
						}
					}
				}
			}
			else
			{
				PUT[0] = false;
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
						if (PUT[1] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[1] = true;
						}
						movePuzzle2->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
						movable[1] = false;
						blCheck6 = true;
						blCheck6_2 = false;
						blCheck6_3 = false;
					}
					else if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						if (PUT[1] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[1] = true;
						}
						movePuzzle2->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						movable[1] = false;
						blCheck6 = false;
						blCheck6_2 = true;
						blCheck6_3 = false;
					}
					else if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						if (PUT[1] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[1] = true;
						}
						movePuzzle2->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						movable[1] = false;
						blCheck6 = false;
						blCheck6_2 = false;
						blCheck6_3 = true;
					}
				}
			}
			else
			{
				PUT[1] = false;
			}
		}

		if (movable[2] == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				Cur[2] = false;
				if ((movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh)))
				{
					if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						if (PUT[2] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[2] = true;
						}
						movePuzzle3->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
						movable[2] = false;
						blCheck7 = true;
						blCheck7_2 = false;
						blCheck7_3 = false;
					}
					else if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						if (PUT[2] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[2] = true;
						}
						movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						movable[2] = false;
						blCheck7 = false;
						blCheck7_2 = true;
						blCheck7_3 = false;
					}
					else if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						if (PUT[2] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[2] = true;
						}
						movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						movable[2] = false;
						blCheck7 = false;
						blCheck7_2 = false;
						blCheck7_3 = true;
					}
				}
			}
			else
			{
				PUT[2] = false;
			}
		}


		if (playUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, playUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[0] == false)
				{
					UI[0] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				//std::cout << "1: " << conecTcheck5_1 << "2: " << conecTcheck5_2 << "3: " << conecTcheck5_2 << std::endl;
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

			connectMove5 = 0;
		}

		if (poopooCheck == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				if (movePuzzleCheck5)
				{
					puzzle7->pipe->Update();

					if (one == false)
					{
						puzzle7->mesh->setRotation(static_cast<float>(DegreeToRadian(300.f)));
						puzzle7->pipe->SetDirection(true, true, false, true, false, false);
						one = true;
					}

					this->sound->Play("assets\\coin.wav", 1);

					movePuzzleCheck5 = false;
				}

				if (conecTcheck5_1 && conecTcheck5_2 && conecTcheck5_3)
				{
					//std::cout << "if 3" << std::endl;
					clear->mesh->setTransform({ 350.f, -240.f });
					chekNext5 = 1;
					//std::cout << "clear" << std::endl;
					mPooPoo.SetIsSuccess(true);
					connectMove5 = 0;

					this->sound->Play("assets\\flushing.wav", 1);

					poopooCheck = false;
				}
				else {
					if (failS == false)
					{
						this->sound->Play("assets\\fart.mp3", 1);
						failS = true;
					}
					timer2 += ENGINE->dt;
					if (timer2 > 1.5)
					{
						Nos[0] = true;
						fail->mesh->setTransform({ 0,0 });
						failS = false;
						poopooCheck = false;
					}
				}
			}
		}

		if (fail->collision->Point2BoxCollision({ cursor5.x,cursor5.y }, fail->mesh))
		{
			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				INPUT->setInput(KEY::LEFT);
				Nos[0] = false;
				fail->mesh->setTransform({ -2000.f,-2000.f });
				STATE_MANAGER->ReloadState();
			}
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
			timer3 += ENGINE->dt;
			if (timer3 > 1.5)
			{
				STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST9);
			}
		}
		if (restartUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, restartUI->mesh))
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


		if (optionUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, optionUI->mesh))
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

		if (quitUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, quitUI->mesh))
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
		if (Yes->collision->Point2BoxCollision(cursor5, Yes->mesh))
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

		if (No->collision->Point2BoxCollision(cursor5, No->mesh))
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

		if (quitCheck == true && realQuit == true)
		{
			glfwTerminate();
			ENGINE->Quit();
		}

		background->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::background2));
		puzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle4->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle5->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle6->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		puzzle7->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::movePuzzle));		//a block which it will move when the player presses 'start'

		puzzle8->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle9->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::threePuzzle));
		puzzle10->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));
		puzzle11->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::threePuzzle));
		puzzle12->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));

		blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));

		startPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::lineStart));
		endPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageEnd));

		movePuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));
		movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));
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
		numberImage->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::num5));
		pooCharacter->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::character));

		mini->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::mini));

		win->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::next));
		fail->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::failScreen));

		Yellow->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::yellow));

		if (mPooPoo.IsFinish() == false)
		{
			pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));

		}

		if (mInput.IsPressed(KEY::A) == true)
		{
			INPUT->setInput(KEY::A);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST9);
		}

		if (mInput.IsPressed(KEY::ESCAPE) == true) {
			INPUT->setInput(KEY::ESCAPE);
			getOpt = true;
			if (this->sound->IsMute_() == false)
			{
				this->sound->ToggleMute();
			}
		}

		QuitAskBack->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));
		QuitAsk->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::QUITCHECK));
		Yes->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES));
		No->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::no));
		Yes_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES_P));
		No_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::NO_P));


		glfwSwapBuffers(APPLICATION->getMyWindow());

		glClearColor(0.f, 0.f, 0.f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

	}
}

void Level5::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	getOpt = false;
	opt.Close();
	OBJECT_FACTORY->DestroyAllObjects();
}
