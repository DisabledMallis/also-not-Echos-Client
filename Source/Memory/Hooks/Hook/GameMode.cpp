#include "GameMode.h"
#include "../../../Client/Client.h"

Client* clientI;

uint64_t _GM_Tick;

void GMTick_Callback(GameMode* GM) {
	for (auto C : clientI->categories) {
		for (auto M : C->modules) {
			M->player = GM->player;
			M->onGmTick(GM);
		}
	}
	PLH::FnCast(_GM_Tick, &GMTick_Callback)(GM);
}

void GameMode_Hook::init() {
	clientI = client;

	Utils::DebugLogF("Preparing GameMode Hook");

	uintptr_t sigAddr = Utils::FindSig("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 8B FA 48 8B 89 ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 10 48 8B 8B");
	if (!sigAddr) return;
	int offset = *reinterpret_cast<int*>(sigAddr + 3);
	uintptr_t** VTable = reinterpret_cast<uintptr_t**>(sigAddr + offset + 7);
	//Must heap allocate the hook so the stack doesn't pop it.
	//Polyhook unhooks when a hook is deleted from memory
	PLH::x64Detour* detour = new PLH::x64Detour((uintptr_t)VTable[10], (uintptr_t)&GMTick_Callback, &_GM_Tick, *clientI->getDis());
	if (detour->hook()) {
		Utils::DebugLogF("Successfully completed GameMode Hook!");
	}
	else {
		Utils::DebugLogF("Failed to create GameMode Hook :/");
	}
}