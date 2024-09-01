
#include "DigipenLogo.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

void DigipenLogo::Init()
{
	check = false;

	digipenLogo = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f, 0.f });
	digipenLogo->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width/2), static_cast<float>(APPLICATION->height/4));
	textureDigipenLogo = TEXTURE->CreateTexture("assets\\DigiPen_WHITE_1024px.png", 0);
	mShader.BuildTextureShader();

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void DigipenLogo::Update()
{

	cursor0 = mInput.Cursor;
	if(check == false)
	{
		this->sound->Play("assets\\logo.wav", 1);
	}
	
	if (mInput.IsPressed(KEY::F))
	{
		INPUT->setInput(KEY::F);
		APPLICATION->SetFullScreen();
	}

	digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo);
	timer += ENGINE->dt;
	if(timer > 2)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::FMODLOGO);
	}

	if (mInput.IsPressed(KEY::ESCAPE))
	{
		glfwTerminate();
		ENGINE->Quit();
	}

    glfwSwapBuffers(APPLICATION->getMyWindow());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
}

void DigipenLogo::Close()
{
	mShader.Delete();
	OBJECT_FACTORY->DestroyAllObjects();
	
}
