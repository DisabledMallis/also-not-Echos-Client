#include "KeyItem.h"
#include "../../../Client/Client.h"

uintptr_t _AVKeyItem;

Client* kClient = nullptr;

void callback(uint64_t key, bool isDown) {
	bool cancel = false;
	kClient->keyMap[key] = isDown;

	for (auto C : kClient->categories) {
		for (auto M : C->modules) {
			M->onKey(key, isDown, &cancel);
		}
	}
	if (!cancel) PLH::FnCast(_AVKeyItem, &callback)(key, isDown);
}

void KeyItem_Hook::init() {
	kClient = client;
	uintptr_t sigAddr = Utils::FindSig("48 89 5C 24 ? 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA");
	if (!sigAddr) return;
	Utils::DebugLogF("Preparing Key Hook!");
	PLH::x64Detour* detour = new PLH::x64Detour((uintptr_t)sigAddr, (uintptr_t)&callback, &_AVKeyItem, *kClient->getDis());
	if (detour->hook()) {
		Utils::DebugLogF("Successfully completed Key Hook!");
	}
	else {
		Utils::DebugLogF("Failed to create Key Hook :/");
	}
}