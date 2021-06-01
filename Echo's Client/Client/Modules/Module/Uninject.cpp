#include "Uninject.h"
#include "../../Client.h"
#include <MinHook.h>

void Uninject::onEnable() {
	MH_DisableHook(MH_ALL_HOOKS);
	Sleep(100);
	MH_Uninitialize();
	FreeLibraryAndExitThread(client->hModule, 0);
}