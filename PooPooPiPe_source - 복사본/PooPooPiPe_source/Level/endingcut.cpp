#include "endingcut.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"
#include "../GUGUENGINE/Sound.h"

void endingCut::Init()
{
	mShader.BuildTextureShader();
	for (int i = 0; i < 3; i++)
	{
		sound_[i] = false;
		soundeffect[i] = false;
	}
	ending = false;
	endCut1 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f,  0.f });
	endCut1->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width)-444.f, static_cast<float>(APPLICATION->height) - 250.f);

	endCut2 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	endCut2->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width)-444.f, static_cast<float>(APPLICATION->height) - 250.f);

	skip = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.f,  450.f });
	skip->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width)-444.f, static_cast<float>(APPLICATION->height));
	skip->mesh->InitializeTextureMesh(200.f, 200.f);

	next = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 780.f,  -450.f });
	next->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	next->mesh->InitializeTextureMesh(247.f, 200.f);

	mInput.InitCallback(APPLICATION->getMyWindow());

	SOUND->StopSound("BGM");
}

void endingCut::Update()
{
	timer += ENGINE->dt;

	if(ending == false)
	{
		ending = true;
		if (this->sound->soundCheck("BGM_another.wav") == true)
		{
			this->sound->StopSound("BGM_another.wav");
		}
		else if(this->sound->soundCheck("BGM_new.flac") == true)
		{
			this->sound->StopSound("BGM_new.flac");
		}
		else if(this->sound->soundCheck("BGM_theother.wav") == true)
		{
			this->sound->StopSound("BGM_theother.wav");
		}
	}
	cursor__ = mInput.Cursor;
	if (mInput.IsPressed(KEY::A) == true)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
	}

	if (mInput.IsPressed(KEY::LEFT) == true)
	{
		std::cout << "CURSOR:" << cursor__.x << "," << cursor__.y << std::endl;
	}

	if (mInput.IsPressed(KEY::F))
	{
		INPUT->setInput(KEY::F);
		APPLICATION->SetFullScreen();
	}
	if (soundeffect[2] == true)
	{
		if (timer > 0.8)
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

	if (sound_[0] == false)
	{
		sound_[0] = true;
		this->sound->Play("assets\\rain.wav", 1);
	}


	if (next->collision->Point2BoxCollision({ cursor__.x,cursor__.y }, next->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (input[1] == false)
			{
				input[1] = true;
				if (cut[0] == false && cut[1] == false)
				{
					cut[0] = true;

					if (sound_[1] == false)
					{
						sound_[1] = true;
						this->sound->Play("assets\\paper.wav", 1);
					}
					endCut2->mesh->setTransform({ 0.f, 0.f });
				}

				else if (cut[0] == true /*&& cut[1] == true*/)
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
	endCut1->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::ending1));
	endCut2->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::ending2));

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}

void endingCut::Close()
{
	mShader.Delete();
	SOUND->StopEffectSound();
	OBJECT_FACTORY->DestroyAllObjects();

}
