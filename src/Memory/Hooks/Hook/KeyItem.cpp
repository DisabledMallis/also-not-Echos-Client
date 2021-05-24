#include "KeyItem.h"
#include "../../../Client/Client.h"

typedef void(__thiscall* AVKeyItem)(uint64_t, bool);
AVKeyItem _AVKeyItem;

Client* kClient = nullptr;

void callback(uint64_t key, bool isDown) {
	bool cancel = false;
	kClient->keyMap[key] = isDown;

	for (auto C : kClient->categories) {
		for (auto M : C->modules) {
			M->onKey(key, isDown, &cancel);
		}
	}
	if (!cancel) _AVKeyItem(key, isDown);
}

void KeyItem_Hook::init() {
	kClient = client;
	uintptr_t sigAddr = Utils::FindSig("48 89 5C 24 ? 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA");
	if (!sigAddr) return;
	Utils::DebugLogF("Preparing Key Hook!");
	if (MH_CreateHook((void*)sigAddr, &callback, reinterpret_cast<LPVOID*>(&_AVKeyItem)) == MH_OK) {
		MH_EnableHook((void*)sigAddr);
		Utils::DebugLogF("Successfully completed Key Hook!");
	}
	else {
		Utils::DebugLogF("Failed to create Key Hook :/");
	}
}