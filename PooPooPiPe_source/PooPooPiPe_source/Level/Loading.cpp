/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *DigipenLogo.h
 *this is digipen logo
 */
#include "Loading.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

int LOADINGCOUNT = 0;

void Loading::Init()
{
	check = false;

	digipenLogo = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f, 0.f });
	digipenLogo->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	textureDigipenLogo = TEXTURE->CreateTexture("assets\\loading1.png", 0);
	textureDigipenLogo2 = TEXTURE->CreateTexture("assets\\loading2.png", 0);
	textureDigipenLogo3 = TEXTURE->CreateTexture("assets\\loading3.png", 0);
	textureDigipenLogo4 = TEXTURE->CreateTexture("assets\\loading4.png", 0);

	mShader.BuildTextureShader();

	mInput.InitCallback(APPLICATION->getMyWindow());

}

void Loading::Update()
{
	cursor0 = mInput.Cursor;
	
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


	switch (LOADINGCOUNT)
	{
	case 0:
		digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo);
		TEXTURE->Load1();
		break;
	case 1:
		digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo2);
		
		TEXTURE->Load2();
		break;
	case 2:
		digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo3);
		TEXTURE->Load3();
		break;
	case 3:
		TEXTURE->Load4();
		digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo4);
		STATE_MANAGER->ChangeLevel(GameLevels::CUTSCENE);
		break;
	}


	LOADINGCOUNT++;

	if (mInput.IsPressed(KEY::ESCAPE))
	{
		glfwTerminate();
		ENGINE->Quit();
	}


	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}

void Loading::Close()
{
	mShader.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();

}