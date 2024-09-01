#include "startCutscene.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"
#include "../GUGUENGINE/Sound.h"

void startCut::Init()
{
	mShader.BuildTextureShader();
	for(int i = 0; i < 3; i++)
	{
		sound_[i] = false;
		soundeffect[i] = false;
	}

	startCut1 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f,  0.f });

	startCut1->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width)-444.f, static_cast<float>(APPLICATION->height) - 250.f);

	startCut2 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });

	startCut2->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width)-444.f, static_cast<float>(APPLICATION->height) - 250.f);
	
	startCut3 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });

	startCut3->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width)-444.f, static_cast<float>(APPLICATION->height)-250.f);

	skip = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.f,  450.f });

	skip->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	skip->mesh->InitializeTextureMesh(200.f, 200.f);

	next = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 780.f,  -450.f });

	next->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	next->mesh->InitializeTextureMesh(247.f, 200.f);


	mInput.InitCallback(APPLICATION->getMyWindow());
}

void startCut::Update()
{
	timer += ENGINE->dt;
	cursor__ = mInput.Cursor;
	if (mInput.IsPressed(KEY::A) == true)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
	}

	if (mInput.IsPressed(KEY::F))
	{
		INPUT->setInput(KEY::F);
		APPLICATION->SetFullScreen();
	}


	if (mInput.IsPressed(KEY::ESCAPE))
	{
		glfwTerminate();
		ENGINE->Quit();
	}

	
	if(soundeffect[2] == true)
	{
		if(timer>0.8)
		{
			soundeffect[2] = false;
			if (input[0] == false)
			{
				input[0] = true;
				STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
			}
		}
	}
	if (skip->collision->Point2BoxCollision({ cursor__.x,cursor__.y }, skip->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			soundeffect[2] = true;
			timer = 0;
			this->sound->Play("assets\\skip.wav", 1);
			
		}
		else
		{
			input[0] = false;
		}
	}
	
	if(sound_[0] == false)
	{
		sound_[0] = true;
		this->sound->Play("assets\\footprint.mp3", 1);
	}

	if(soundeffect[0] == true)
	{
		if (timer > 0.8)
		{
			soundeffect[0] = false;

			this->sound->Play("assets\\flushing.wav", 1);
		}
	}
	if(soundeffect[1] == true)
	{
		if (timer > 0.8)
		{
			soundeffect[1] = false;

			this->sound->Play("assets\\heaven.mp3", 1);
		}
	}
	if (next->collision->Point2BoxCollision({ cursor__.x,cursor__.y }, next->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (input[1] == false)
			{
				input[1] = true;
				if(cut[0] == false && cut[1] == false)
				{
					cut[0] = true;
					timer = 0;

					if(sound_[1] == false)
					{
						sound_[1] = true;
						this->sound->Play("assets\\paper.wav", 1);
						soundeffect[0] = true;	
					}
					startCut2->mesh->setTransform({ 0.f, 0.f });
				}
				else if(cut[0] == true && cut[1] == false)
				{
					cut[1] = true;
					timer = 0;
					if(sound_[2] == false)
					{
						sound_[2] = true;
						soundeffect[1] = true;
						this->sound->Play("assets\\paper.wav", 1);
					}
					startCut3->mesh->setTransform({ 0.f, 0.f });
				}
				else if(cut[0] == true && cut[1] == true)
				{
					STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
				}
			}
		}
		else
		{
			input[1] = false;
		}
	}
	else
	{
		input[1] = false;
	}
	skip->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::SKIP));
	next->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::nextd));
	startCut1->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::STARTCUT1));
	startCut2->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::STARTCUT2));
	startCut3->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::STARTCUT3));

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}

void startCut::Close()
{

	mShader.Delete();
	sound->StopEffectSound();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();

}
