
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level4.h"
#include "../GUGUENGINE/Sound.h"

 //Sound se4;
 //Sound playSE4;
extern int MaxLevel;
extern bool getOpt;

void Level4::Init()
{
	current = 2;
	getOpt = false;

	if (MaxLevel <= 2)
	{
		MaxLevel = 2;
	}
	
	timer = 0;
	timer2 = 0;

	skip = false;
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

	chekNext4 = 0;
	failS = false;
	conecTcheck4_1 = false;
	conecTcheck4_2 = false;
	conecTcheck4_3 = false;

	degree4 = DegreeToRadian(60.f);
	degree4_2 = 0;
	degree4_3 = 0;

	blCheck3 = false;
	blCheck3_2 = false;

	blCheck4 = false;
	blCheck4_2 = false;

	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

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

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 60.f);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -526.795f, 330.f });
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -353.59f, 330.f });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -613.397f, 180.f });
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -266.987f, 180.f });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -526.795f, 30.f }, 60.f);
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -353.59f, 30.f }, 300.f);
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -180.385f, 30.f }, 240.f);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -266.987f, -120.f }, 60.f);
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -93.782f,-120.f }, 60.f);
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -353.59f,-270.f }, 180.f);

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -440.192f, 180.f });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -440.192f, -120.f });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -180.385f, -270.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -700.f, 330.f }, 120.f);
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -7.18f, -270.f }, 60.f);
	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });


	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });

	mShader2.BuildTextureShader();

	movePuzzle->pipe->SetDirection(false, false, true, false, false, true);
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle3->pipe->SetDirection(true, false, false, true, false, false);
	endPuzzle->pipe->SetDirection(false, false, false, false, false, true);
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);
	puzzle6->pipe->SetDirection(true, false, false, false, true, false);
	puzzle10->pipe->SetDirection(true, false, true, false, false, false);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle6->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);

	opt.Init();
	opt.getInput(&mInput, (this->sound));
	
	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level4::Update()
{
	if (current < 5)
	{
		current = 5;

		if (this->sound->soundCheck("BGM_another.wav") == true)
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

		cursor4 = mInput.Cursor;

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

		if (Levelsel->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, Levelsel->mesh) == true)
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

		if (movePuzzle->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle->mesh))
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

					degree4 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle->mesh->setRotation(degree4);

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
			movePuzzle->mesh->setTransform({ cursor4.x, cursor4.y });
			movable[0] = true;
		}

		if (blCheck3)
		{
			if ((movePuzzle->pipe->GetDirValue(NW) == 1) && (movePuzzle->pipe->GetDirValue(SE) == 1))
			{
				conecTcheck4_1 = true;
			}
			else
			{
				conecTcheck4_1 = false;
			}
		}

		if (blCheck3_2)
		{
			if ((movePuzzle->pipe->GetDirValue(W) == 1) && (movePuzzle->pipe->GetDirValue(E) == 1))
			{
				//std::cout << "pipe connect" << std::endl;
				conecTcheck4_1 = true;
			}
			else
			{
				conecTcheck4_1 = false;
			}
		}

		if (movePuzzle2->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle2->mesh))
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
					degree4_2 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle2->mesh->setRotation(degree4_2);

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
			movePuzzle2->mesh->setTransform({ cursor4.x, cursor4.y });
			movable[1] = true;
		}

		if ((movePuzzle2->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle10->pipe->GetDirValue(NW)))
		{
			conecTcheck4_2 = true;
		}
		else
		{
			conecTcheck4_2 = false;
		}

		if (movePuzzle3->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle3->mesh))
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
					degree4_3 += static_cast<float>(DegreeToRadian(60.f));

					movePuzzle3->mesh->setRotation(degree4_3);

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
			movePuzzle3->mesh->setTransform({ cursor4.x, cursor4.y });
			movable[2] = true;
		}

		if (blCheck4)
		{
			if ((movePuzzle3->pipe->GetDirValue(NW) == 1) && (movePuzzle3->pipe->GetDirValue(SE) == 1))
			{
				conecTcheck4_3 = true;
			}
			else
			{
				conecTcheck4_3 = false;
			}
		}
		if (blCheck4_2)
		{
			if ((movePuzzle3->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
			{
				conecTcheck4_3 = true;
			}
			else
			{
				conecTcheck4_3 = false;
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
						if (PUT[0] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[0] = true;
						}

						movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
						blCheck3 = true;
						blCheck3_2 = false;
					}

					else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						if (PUT[0] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[0] = true;
						}
						movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						blCheck3 = false;
						blCheck3_2 = false;
					}

					else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						if (PUT[0] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[0] = true;
						}
						movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						blCheck3 = false;
						blCheck3_2 = true;
					}
				}
			}
			else
			{
				PUT[0] = false;
				conecTcheck4_1 = false;
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
					}
					if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						if (PUT[1] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[1] = true;
						}
						movePuzzle2->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					}
					if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh))
					{
						if (PUT[1] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[1] = true;
						}
						movePuzzle2->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					}
				}
			}
			else
			{
				PUT[1] = false;
				conecTcheck4_2 = false;
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
						blCheck4 = true;
						blCheck4_2 = false;
						//std::cout << "4 "<< blCheck4 << std::endl;
					}
					if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						if (PUT[2] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[2] = true;
						}
						movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						blCheck4 = false;
						blCheck4_2 = false;
					}
					if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
					{
						if (PUT[2] == false)
						{
							this->sound->Play("assets\\fit.flac", 1);
							PUT[2] = true;
						}
						movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						blCheck4 = false;
						blCheck4_2 = true;
						//std::cout << "4_2 " << blCheck4 << std::endl;

					}
				}
			}
			else
			{
				PUT[2] = false;
				conecTcheck4_3 = false;
			}
		}

		if (playUI->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, playUI->mesh))
		{
			//std::cout << "1:  " << conecTcheck4_1 << "  2:  " << conecTcheck4_2 << "  1:  " << conecTcheck4_3 << std::endl;

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
					poopooCheck = true;
				}
			}
		}
		else
		{
			UI[0] = false;
			playUI_p->mesh->setTransform({ 1000.f, 1000.f });

			connectMove4 = 0;
		}
		if (poopooCheck == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				INPUT->setInput(KEY::LEFT);

				if (conecTcheck4_1 && conecTcheck4_2 && conecTcheck4_3)
				{
					clear->mesh->setTransform({ 350.f, -240.f });
					chekNext4 = 1;
					//std::cout << "clear" << std::endl;
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
				STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST6);
			}
		}
		if (fail->collision->Point2BoxCollision({ cursor4.x,cursor4.y }, fail->mesh))
		{
			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				INPUT->setInput(KEY::LEFT);
				Nos[0] = false;
				fail->mesh->setTransform({ -2000.0f, -2000.0f });
				STATE_MANAGER->ReloadState();
			}
		}
		if (restartUI->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, restartUI->mesh))
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

		if (optionUI->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, optionUI->mesh))
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

		if (quitUI->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, quitUI->mesh))
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

		if (Yes->collision->Point2BoxCollision(cursor4, Yes->mesh))
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

		if (No->collision->Point2BoxCollision(cursor4, No->mesh))
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


		background->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::background1));
		puzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle4->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle5->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle6->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle7->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		puzzle8->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle9->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle10->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));

		blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));
		blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::blackPuzzle));

		startPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageStart));
		endPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageEnd));
		Levelsel->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::levelButton));
		Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::levelButton_2));
		movePuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::image01));
		movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));
		movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::image01));
		button->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::character));
		clear->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::clear));


		if (mPooPoo.IsFinish() == false)
		{
			pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
		}
		playUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::playUI));
		quitUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitUI));
		optionUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionUI));
		restartUI->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::restartUI));
		restartUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::restartUI_2));
		playUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::playUI_2));
		quitUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitUI_2));
		optionUI_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionUI_2));

		levelImage->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::level));
		numberImage->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::num2));

		pooCharacter->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::character));

		win->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::next));
		fail->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::failScreen));


		if ((mInput.IsPressed(KEY::A) == true))
		{
			INPUT->setInput(KEY::A);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST6);
		}

		QuitAskBack->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));
		QuitAsk->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::QUITCHECK));
		Yes->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES));
		No->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::no));
		Yes_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES_P));
		No_p->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::NO_P));

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

void Level4::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	getOpt = false;
	opt.Close();

	OBJECT_FACTORY->DestroyAllObjects();
}
