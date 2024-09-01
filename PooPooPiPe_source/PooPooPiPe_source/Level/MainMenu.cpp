
#include "MainMenu.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"

int check0 = 0;
int moveCheck0 = 0;
int moveCheck0_2 = 0;
int moveCheck0_3 = 0;

float volume = 0.3f;

extern bool mainMenu;

void MainMenu::Init()
{
	clickCredit = false;
	main = false;
	mainMenu = false;
	
	isPlaying = false;
	

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

	quitButton = OBJECT_FACTORY->CreateEmptyObject();
	quitButton_pressed = OBJECT_FACTORY->CreateEmptyObject();

	quitButton->AddComponent(new Mesh());
	quitButton->Init();
	quitButton_pressed->AddComponent(new Mesh());
	quitButton_pressed->Init();

	quitButton->mesh->setTransform({ 0.f, -340.f });
	quitButton->mesh->SetMeshType(MESHTYPE::rectangle);
	quitButton->mesh->InitializeTextureMesh(280.f, 70.f);
	quitButton_pressed->mesh->setTransform({ 5000.f, -340.f });
	quitButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	quitButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);


	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	for(int i = 0;  i < 5; i++)
	{
		UI[i] = false;
	}
	
	startButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();
	optionButton = OBJECT_FACTORY->CreateEmptyObject();
	creditsButton = OBJECT_FACTORY->CreateEmptyObject();

	startButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	optionButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	creditsButton_pressed = OBJECT_FACTORY->CreateEmptyObject();

	test = OBJECT_FACTORY->CreateEmptyObject();
	test2 = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildTextureShader();
	startButton->AddComponent(new Mesh());
	startButton->AddComponent(new CollisionCheck());
	startButton->Init();
	startButton_pressed->AddComponent(new Mesh());
	startButton_pressed->AddComponent(new CollisionCheck());
	startButton_pressed->Init();

	startButton->mesh->setTransform({ 0.f,-20.f });
	startButton->mesh->SetMeshType(MESHTYPE::rectangle);
	startButton->mesh->InitializeTextureMesh(280.f, 70.f);
	startButton_pressed->mesh->setTransform({ 1000.f,-20.f });
	startButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	startButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	tutorialButton->AddComponent(new Mesh());
	tutorialButton->Init();
	tutorialButton_pressed->AddComponent(new Mesh());
	tutorialButton_pressed->Init();

	tutorialButton->mesh->setTransform({ 0.0f,-100.f });
	tutorialButton->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton->mesh->InitializeTextureMesh(350.f, 70.f);
	tutorialButton_pressed->mesh->setTransform({ 1000.0f,-100.f });
	tutorialButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	optionButton->AddComponent(new Mesh());
	optionButton->Init();
	optionButton_pressed->AddComponent(new Mesh());
	optionButton_pressed->Init();
	optionButton->mesh->setTransform({ 0.0f,-180.f });
	optionButton->mesh->SetMeshType(MESHTYPE::rectangle);
	optionButton->mesh->InitializeTextureMesh(280.f, 70.f);
	optionButton_pressed->mesh->setTransform({ 0.0f,-180.f });
	optionButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	optionButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	checking = false;

	creditsButton->AddComponent(new Mesh());
	creditsButton->Init();
	creditsButton_pressed->AddComponent(new Mesh());
	creditsButton_pressed->Init();
	creditsButton->mesh->setTransform({ 0.0f,-260.f });
	creditsButton->mesh->SetMeshType(MESHTYPE::rectangle);
	creditsButton->mesh->InitializeTextureMesh(350.f, 70.f);
	creditsButton_pressed->mesh->setTransform({ 0.0f,-260.f });
	creditsButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	creditsButton_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	credit1 = OBJECT_FACTORY->CreateEmptyObject();
	credit1->AddComponent(new Mesh());
	credit1->AddComponent(new CollisionCheck());
	credit1->Init();
	credit1->mesh->setTransform({ 5000.f,100.f });
	credit1->mesh->SetMeshType(MESHTYPE::rectangle);
	credit1->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	credit2 = OBJECT_FACTORY->CreateEmptyObject();
	credit2->AddComponent(new Mesh());
	credit2->AddComponent(new CollisionCheck());
	credit2->Init();
	credit2->mesh->setTransform({ 5000.f,100.f });
	credit2->mesh->SetMeshType(MESHTYPE::rectangle);
	credit2->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	credit3 = OBJECT_FACTORY->CreateEmptyObject();
	credit3->AddComponent(new Mesh());
	credit3->AddComponent(new CollisionCheck());
	credit3->Init();
	credit3->mesh->setTransform({ 5000.f,100.f });
	credit3->mesh->SetMeshType(MESHTYPE::rectangle);
	credit3->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	next = OBJECT_FACTORY->CreateEmptyObject();
	next->AddComponent(new Mesh());
	next->AddComponent(new CollisionCheck());
	next->Init();
	next->mesh->setTransform({ 5000.f,100.f });
	next->mesh->SetMeshType(MESHTYPE::rectangle);
	next->mesh->InitializeTextureMesh(350.f, 288.f);

	menuInput.InitCallback(APPLICATION->getMyWindow());
	
	//this->sound->Play("assets\\BGM_new.flac", -1);
}

void MainMenu::Update()
{
	this->sound->Update();
	cursor0 = menuInput.Cursor;
	if(main == false)
	{
		main = true;
		if (this->sound->soundCheck("BGM_another.wav") == true)
		{
			this->sound->StopSound("BGM_another.wav");
			this->sound->Play("assets\\BGM_new.flac", -1);
		}
		else if (this->sound->soundCheck("BGM_theother.wav") == true)
		{
			this->sound->StopSound("BGM_theother.wav");
			this->sound->Play("assets\\BGM_new.flac", -1);
		}
	}
	
	if(menuInput.IsPressed(KEY::LEFT))
	{
		if(checking == false)
		{
			this->sound->Play("assets\\click.wav", 1);
			checking = true;
		}
	}
	else
	{
		if(checking == true)
		{
			checking = false;
		}
	}
	
	if (menuInput.IsPressed(KEY::ESCAPE))
	{
		INPUT->setInput(KEY::ESCAPE);
		STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
	}

	if (menuInput.IsKeyDown(KEY::F) == true)
	{
		//std::cout << "F Key" << std::endl;
		menuInput.setInput(KEY::F);

		APPLICATION->SetFullScreen();
	}

	//keyboard volume
	/*if (menuInput.IsPressed(KEY::UP))
	{
		std::cout << "Up Key" << std::endl;

		if (volume < 1.0f)
		{
			volume += 0.1f;
			this->sound->SetVolume(volume);
			menuInput.setInput(KEY::UP);
			std::cout << volume << std::endl;
		}
	}
	if (menuInput.IsPressed(KEY::DOWN))
	{
		std::cout << "Down Key" << std::endl;

		if (volume > 0.0f)
		{
			volume -= 0.1f;
			this->sound->SetVolume(volume);
			menuInput.setInput(KEY::DOWN);

			std::cout << volume << std::endl;
		}
	}*/

	if (menuInput.IsPressed(KEY::A) == true)
	{
		INPUT->setInput(KEY::A);
		STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
	}
	
	if (isPlaying == false)
	{
		this->sound->Play("assets\\BGM_new.flac", -1);
		isPlaying = true;
	}

	if (startButton->collision->Point2BoxCollision(cursor0, startButton->mesh) && clickCredit == false && quitCheck == false)
	{
		if(UI[0] == false)
		{
			UI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		startButton_pressed->mesh->setTransform(startButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
		}
	}
	else
	{
		UI[0] = false;
		startButton_pressed->mesh->setTransform({1000.f, 1000.f});
	}


	if (tutorialButton->collision->Point2BoxCollision(cursor0, tutorialButton->mesh) && clickCredit == false && quitCheck == false)
	{
		if (UI[1] == false)
		{
			UI[1] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		tutorialButton_pressed->mesh->setTransform(tutorialButton->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST1);
		}
	}
	else
	{
		UI[1] = false;
		tutorialButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (optionButton->collision->Point2BoxCollision(cursor0, optionButton->mesh) && clickCredit == false && quitCheck == false)
	{
		if (UI[2] == false)
		{
			UI[2] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		optionButton_pressed->mesh->setTransform(optionButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			mainMenu = true;
			INPUT->setInput(KEY::LEFT);
			if(this->sound->IsMute_() == false)
			{
				this->sound->ToggleMute();
			}
			STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
		}
	}
	else
	{
		UI[2] = false;
		optionButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	//
	if (creditsButton->collision->Point2BoxCollision(cursor0, creditsButton->mesh) && clickCredit == false && quitCheck == false)
	{
		if (UI[3] == false)
		{
			UI[3] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		
		creditsButton_pressed->mesh->setTransform(creditsButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			clickCredit = true;
			credit1->mesh->setTransform({ 0.f,0.f });
			next->mesh->setTransform({ 770.f,480.f });
		}

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
		}
	}
	else
	{
		UI[3] = false;
		creditsButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (quitButton->collision->Point2BoxCollision(cursor0, quitButton->mesh) && clickCredit == false && quitCheck == false)
	{
		if (UI[4] == false)
		{
			UI[4] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		quitButton_pressed->mesh->setTransform(quitButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (quitCheck == false)
			{
				quitCheck = true;
				QuitAskBack->mesh->setTransform({ 0.f, 0.f });
				QuitAsk->mesh->setTransform({ 0.f, 0.f });
				Yes->mesh->setTransform({ -100.f, -50.f });
				No->mesh->setTransform({ 100.f, -50.f });
			}
		}
	}
	else
	{
		UI[4] = false;
		quitC = false;
		quitButton_pressed->mesh->setTransform({ 2000.f, 2000.f });
	}

	if (Yes->collision->Point2BoxCollision(cursor0, Yes->mesh))
	{
		Yes_p->mesh->setTransform(Yes->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			realQuit = true;
		}
	}
	else
	{
		Yes_p->mesh->setTransform({ -1000.f, -1000.f });
	}

	if (No->collision->Point2BoxCollision(cursor0, No->mesh))
	{
		No_p->mesh->setTransform(No->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			realQuit = false; quitCheck = false;
			QuitAskBack->mesh->setTransform({ -2000.f, -2000.f });
			QuitAsk->mesh->setTransform({ -2000.f, -2000.f });
			Yes->mesh->setTransform({ -2000.f, -2000.f });
			No->mesh->setTransform({ -2000.f, -2000.f });
		}
	}
	else
	{
		No_p->mesh->setTransform({ -2000.f, -2000.f });
	}

	if (quitCheck == true && realQuit == true)
	{
		glfwTerminate();
		ENGINE->Quit();
	}

	if (next->collision->Point2BoxCollision(cursor0, next->mesh) == true && clickCredit == true)
	{
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (input[1] == false)
			{
				input[1] = true;
				if (cut[0] == false && cut[1] == false)
				{
					cut[0] = true;
					credit2->mesh->setTransform({ 0.f, 0.f });
				}
			}
			else if (cut[0] == true && cut[1] == false)
			{
				cut[1] = true;
				credit3->mesh->setTransform({ 0.f, 0.f });
			}
			else if (cut[0] == true && cut[1] == true)
			{
				clickCredit = false;
				input[1] = false;
				cut[0] = false;
				cut[1] = false;
				credit1->mesh->setTransform({ -2000.f, -2000.f });
				credit2->mesh->setTransform({ -2000.f, -2000.f });
				credit3->mesh->setTransform({ -2000.f, -2000.f });
				next->mesh->setTransform({ -2000.f, -2000.f });
			}
		}
	}


	background->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::title));
	startButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::start));
	tutorialButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::tutorial));
	optionButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionL));
	creditsButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit));

	startButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::startP));
	tutorialButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::tutorialP));
	optionButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionLP));
	creditsButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::creatP));

	quitButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitL));
	quitButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitLp));


	credit1->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit1));
	credit2->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit2));
	credit3->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit3));

	next->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::nextd));

	QuitAskBack->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));
	QuitAsk->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::QUITCHECK));
	Yes->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES));
	No->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::no));
	Yes_p->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES_P));
	No_p->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::NO_P));

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void MainMenu::Close()
{
	mShader.Delete();
	mMesh.Delete();
	OBJECT_FACTORY->DestroyAllObjects();
}
