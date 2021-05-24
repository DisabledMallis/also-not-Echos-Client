#include "ClientInstance.h"
#include "../../../Client/Client.h"

typedef void(__thiscall* CInstance)(ClientInstance*, void*);
CInstance _CInstance;

Client* cClientI;

void CInstance_Callback(ClientInstance* i, void* a2) {
	Minecraft::ClientInstance(i);
	for (auto C : cClientI->categories) {
		for (auto M : C->modules) {
			M->instance = i;
			//M->player = i->GetLocalPlayer();
		}
	}
	_CInstance(i, a2);
}

void CInstance_Hook::init() {
	cClientI = client;
	Utils::DebugLogF("Preparing to hook onto the Client Instance");
	uintptr_t sigAddr = Utils::FindSig("48 8B 89 ? ? ? ? 48 85 C9 ? ? 33 C0 48 8B 5C ? ?");
	if (!sigAddr) return;
	PLH::x64Detour* detour = new PLH::x64Detour(sigAddr, (const uintptr_t)&CInstance_Callback, &_CInstance, cClientI->getDis());
	if (detour->hook()) {
		Utils::DebugLogF("Successfully completed Client Instance Hook!");
	}
	else {
		Utils::DebugLogF("Failed to create Client Instance Hook :/");
	}
}