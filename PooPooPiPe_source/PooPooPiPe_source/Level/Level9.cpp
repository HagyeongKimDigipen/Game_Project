/*
 *hakyung.kim
 *4.1.2020
 *digipen.hagyeong@gmail.com
 *Level9.cpp
 *this is level9
 */
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level9.h"
#include "../GUGUENGINE/Sound.h"


extern int MaxLevel;
extern bool getOpt;

bool SoundCheck = false;
void Level9::Init()
{
	one = false;
	current = 6;
	getOpt = false;
	poopooCheck = false;
	SoundCheck = false;
	if (MaxLevel <= 6)
	{
		MaxLevel = 6;
	}

	timer = 0;
	timer2 = 0;

	skip = false;

	failS = false;

	Nos[0] = false;
	Nos[1] = false;

	Cur[0] = false;
	Cur[1] = false;
	Cur[2] = false;
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

	autoRot = true;

	chekNext9 = 0;

	conecTcheck9_1 = false;
	conecTcheck9_2 = false;
	conecTcheck9_3 = false;

	degree9 = 0;
	degree9_2 = DegreeToRadian(60.f);
	degree9_3 = DegreeToRadian(-60.f);
	degree9_4 = DegreeToRadian(60.f);
	degree9_5 = 0;
	degree9_6 = DegreeToRadian(-180.f);
	degree9_7 = DegreeToRadian(120.f);
	degree9_rot = DegreeToRadian(-120.f);

	mini = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 330.f, 200.f });
	mini->mesh->InitializeTextureMesh(500.f, 500.f);

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));


	mShader2.BuildTextureShader();


	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

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


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->InitializeTextureMesh(173.f, 200.f);
	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 280.f + 50.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 280.f + 50.f });
	puzzle1->pipe->SetDirection(false, false, false, false, true, true);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 280.f + 50.f });
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 120.f);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f }, -120.f);
	puzzle4->pipe->SetDirection(false, true, false, true, false, true);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f }, -60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);
	puzzle6->pipe->SetDirection(true, false, false, true, false, false);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 40.f - 5.f }, 60.f);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 180.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f });
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, -80.f - 32.f }, -240.f);
	puzzle10->pipe->SetDirection(true, false, true, true, false, false);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 60.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, 120.f);
	puzzle12->pipe->SetDirection(false, true, false, true, false, false);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 280.f + 50.f });
	puzzle13->pipe->SetDirection(false, true, true, false, false, false);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 276.f - 376.f, 160.f + 22.f }, -60);

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 40.f - 5.f });
	puzzle15->pipe->SetDirection(true, false, false, true, false, false);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, -80.f - 32.f }, -180.f);
	puzzle16->pipe->SetDirection(false, true, true, false, false, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, -200.f - 62.f }, -60.f);
	puzzle17->pipe->SetDirection(true, false, false, false, false, true);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, 160.f + 22.f }, -60.f);
	puzzle18->pipe->SetDirection(true, false, false, true, false, true);

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, 160.f + 22.f }, 60.f);
	puzzle19->pipe->SetDirection(true, false, true, false, false, false);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, -80.0f - 32.f });
	puzzle20->pipe->SetDirection(false, false, false, true, false, true);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });

	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);


	quitUI_p = OBJECT_FACTORY->CreateEmptyObject();
	quitUI_p->AddComponent(new Mesh());
	quitUI_p->Init();

	quitUI_p->mesh->setTransform({ 1800.f, 150.f });
	quitUI_p->mesh->InitializeTextureMesh(173.f, 200.f);


	optionUI_p = OBJECT_FACTORY->CreateEmptyObject();
	optionUI_p->AddComponent(new Mesh());
	optionUI_p->Init();
	optionUI_p->mesh->setTransform({ 1713.5f, 0.f });
	optionUI_p->mesh->InitializeTextureMesh(173.f, 200.f);


	restartUI_p = OBJECT_FACTORY->CreateEmptyObject();
	restartUI_p->AddComponent(new Mesh());
	restartUI_p->Init();
	restartUI_p->mesh->setTransform({ 1800.f, -150.f });
	restartUI_p->mesh->InitializeTextureMesh(173.f, 200.f);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle13->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle15->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle16->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle17->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::NW_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle20->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	opt.Init();
	opt.getInput(&mInput, (this->sound));

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level9::Update()
{
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
		cursor9 = mInput.Cursor;
		if (mInput.IsPressed(KEY::F) == true)
		{
			APPLICATION->SetFullScreen();
			mInput.setInput(KEY::F);
		}


		if (Levelsel->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, Levelsel->mesh) == true)
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[4] == false)
				{
					UI[4] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());
				if (mInput.IsPressed(KEY::LEFT) == true)
				{
					INPUT->setInput(KEY::LEFT);
					STATE_MANAGER->ChangeLevel(GameLevels::LV_SELECT);
				}
			}
		}
		else
		{
			UI[4] = false;
			Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
		}
		if (puzzle1->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle1->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[0] = true;
			}
			if (rot[0] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle1->pipe->Update();

					degree9 += static_cast<float>(DegreeToRadian(60.f));
					puzzle1->mesh->setRotation(degree9);

					this->sound->Play("assets\\coin.wav", 1);

					rot[0] = false;
				}
			}
		}


		if (puzzle19->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle19->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[1] = true;
			}
			if (rot[1] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle19->pipe->Update();

					degree9_2 += static_cast<float>(DegreeToRadian(60.f));
					puzzle19->mesh->setRotation(degree9_2);

					this->sound->Play("assets\\coin.wav", 1);

					rot[1] = false;
				}
			}
		}


		if (puzzle14->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle14->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[2] = true;
			}
			if (rot[2] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle14->pipe->Update();

					degree9_3 += static_cast<float>(DegreeToRadian(60.f));
					puzzle14->mesh->setRotation(degree9_3);

					this->sound->Play("assets\\coin.wav", 1);

					rot[2] = false;
				}
			}
		}

		if (puzzle6->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle6->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[3] = true;
			}
			if (rot[3] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle6->pipe->Update();

					degree9_4 += static_cast<float>(DegreeToRadian(60.f));
					puzzle6->mesh->setRotation(degree9_4);


					this->sound->Play("assets\\coin.wav", 1);

					rot[3] = false;

				}

			}
		}

		if (puzzle20->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle20->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[4] = true;
			}
			if (rot[4] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle20->pipe->Update();

					degree9_5 += static_cast<float>(DegreeToRadian(60.f));
					puzzle20->mesh->setRotation(degree9_5);

					this->sound->Play("assets\\coin.wav", 1);

					rot[4] = false;
				}
			}
		}

		if (puzzle16->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle16->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[5] = true;
			}
			if (rot[5] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle16->pipe->Update();

					degree9_6 += static_cast<float>(DegreeToRadian(60.f));
					puzzle16->mesh->setRotation(degree9_6);

					this->sound->Play("assets\\coin.wav", 1);

					rot[5] = false;
				}
			}
		}

		if (puzzle12->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle12->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[6] = true;
			}
			if (rot[6] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle12->pipe->Update();

					degree9_7 += static_cast<float>(DegreeToRadian(60.f));
					puzzle12->mesh->setRotation(degree9_7);

					this->sound->Play("assets\\coin.wav", 1);

					rot[6] = false;
				}

			}
		}

		if ((puzzle15->pipe->GetDirValue(SE) == 1 && puzzle16->pipe->GetDirValue(NW) == 1))
		{
			conecTcheck9_1 = true;
		}
		else
		{
			conecTcheck9_1 = false;
		}

		if ((puzzle12->pipe->GetDirValue(E) == 1 && puzzle17->pipe->GetDirValue(W) == 1) && (puzzle12->pipe->GetDirValue(NW) == 1 && puzzle9->pipe->GetDirValue(SE) == 1))
		{

			conecTcheck9_2 = true;
		}
		else
		{
			conecTcheck9_2 = false;
		}

		if ((puzzle20->pipe->GetDirValue(E) == 1 && puzzle9->pipe->GetDirValue(W) == 1) && (puzzle20->pipe->GetDirValue(SW) == 1 && endPuzzle->pipe->GetDirValue(NE) == 1))
		{

			conecTcheck9_3 = true;
		}
		else
		{
			conecTcheck9_3 = false;
		}

		if (playUI->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, playUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[0] == false)
				{
					UI[0] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				playUI_p->mesh->setTransform(playUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true)
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
			connectMove9 = 0;
		}

		if (poopooCheck == true)
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				if (autoRot)
				{
					puzzle4->pipe->Update();

					if (one == false)
					{
						degree9_rot += static_cast<float>(DegreeToRadian(-120.f));
						puzzle4->mesh->setRotation(degree9_rot);
						one = true;
					}


					this->sound->Play("assets\\coin.wav", 1);

					autoRot = false;

					if (!conecTcheck9_1 || !conecTcheck9_2 || !conecTcheck9_3)
					{
						if (failS == false)
						{
							this->sound->Play("assets\\fart.mp3", 1);
							failS = true;
						}
					}
				}

				if (failS == true)
				{
					timer += ENGINE->dt;
					if (timer > 1.5)
					{
						Nos[0] = true;
						fail->mesh->setTransform({ 0,0 });

						poopooCheck = false;
					}
				}

				if (conecTcheck9_1 && conecTcheck9_2 && conecTcheck9_3)
				{
					//std::cout << "if 3" << std::endl;
					clear->mesh->setTransform({ 350.f, -240.f });
					chekNext9 = 1;
					//std::cout << "clear" << std::endl;
					mPooPoo.SetIsSuccess(true);
					connectMove9 = 0;

					if (SoundCheck == false)
					{
						SoundCheck = true;
						this->sound->Play("assets\\flushing.wav", 1);
					}
					
				}
			}
		}

		if (fail->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, fail->mesh))
		{
			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				INPUT->setInput(KEY::LEFT);
				failS = false;
				Nos[0] = false;
				fail->mesh->setTransform({ -2000.0f, -2000.0f });
				STATE_MANAGER->ReloadState();
			}
		}

		if (restartUI->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, restartUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[1] == false)
				{
					UI[1] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				restartUI_p->mesh->setTransform(restartUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true)
				{
					INPUT->setInput(KEY::LEFT);
					STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST9);

				}
			}
		}
		else
		{
			UI[1] = false;
			restartUI_p->mesh->setTransform({ 1700.f, 1000.f });
		}

		if (optionUI->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, optionUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[2] == false)
				{
					UI[2] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				optionUI_p->mesh->setTransform(optionUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true)
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


		if (quitUI->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, quitUI->mesh))
		{
			if (Nos[0] == false && Nos[1] == false)
			{
				if (UI[3] == false)
				{
					UI[3] = true;
					this->sound->Play("assets\\UI.wav", 1);
				}
				quitUI_p->mesh->setTransform(quitUI->mesh->GetTransform());

				if (mInput.IsPressed(KEY::LEFT) == true)
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
		if (Yes->collision->Point2BoxCollision(cursor9, Yes->mesh))
		{
			if (SUI[0] == false)
			{
				SUI[0] = true;
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
			SUI[0] = false;

			Yes_p->mesh->setTransform({ -1000.f, -1000.f });
		}

		if (No->collision->Point2BoxCollision(cursor9, No->mesh))
		{
			if (SUI[1] == false)
			{
				SUI[1] = true;
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
			SUI[1] = false;

			No_p->mesh->setTransform({ -1000.f, -1000.f });
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
			if (timer2 > 2)
			{
				STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST10);
			}
		}

		background->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::background2));
		puzzle1->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::VPuzzle2));
		puzzle2->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle3->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));
		puzzle4->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::yellowPuzzle));
		puzzle5->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle6->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::image01));
		puzzle7->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));

		puzzle8->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle9->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle10->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));
		puzzle11->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curvePuzzle));
		puzzle12->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));

		puzzle13->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));
		puzzle14->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));
		puzzle15->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::linePuzzle));
		puzzle16->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::VPuzzle2));
		puzzle17->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));

		puzzle18->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::vPuzzle));
		puzzle19->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));
		puzzle20->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::curve2Puzzle));

		startPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageStart));
		endPuzzle->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::imageEnd));

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
		numberImage->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::num6));
		pooCharacter->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::character));
		mini->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::mini));

		win->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::next));
		fail->mesh->Update(mShader2.GetShaderHandler(), TEXTURE->GetTexture(Textures::failScreen));



		if (mPooPoo.IsFinish() == false)
		{
			pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
		}


		if (mInput.IsPressed(KEY::A) == true)
		{
			INPUT->setInput(KEY::A);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST10);
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

void Level9::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	getOpt = false;
	opt.Close();
	OBJECT_FACTORY->DestroyAllObjects();
}
