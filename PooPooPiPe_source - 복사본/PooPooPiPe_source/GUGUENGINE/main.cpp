#ifdef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:console")
#else
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "../GUGUENGINE/Engine.h"

int main(void)
{
	Engine* GUGUengine = new Engine();

	GUGUengine->Init();
	GUGUengine->GameLoop();

	delete GUGUengine;
	return 0;
}
