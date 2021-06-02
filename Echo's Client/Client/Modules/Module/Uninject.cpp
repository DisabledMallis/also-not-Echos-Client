#include "Uninject.h"
#include "../../Client.h"
#include <MinHook.h>

void Uninject::onEnable() {
	client->isRunning = false;
	MH_DisableHook(MH_ALL_HOOKS);
	Sleep(1000);
	MH_Uninitialize();
	Sleep(1000);
	FreeLibraryAndExitThread(client->hModule, 0);
}