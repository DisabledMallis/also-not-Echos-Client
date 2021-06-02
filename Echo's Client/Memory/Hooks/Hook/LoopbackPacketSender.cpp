#include "LoopbackPacketSender.h"
#include "../../../Client/Client.h"

typedef void(__thiscall* Loopback)(LoopbackPacketSender*, Packet*);
Loopback _Loopback;

Client* lClient;

void callback(LoopbackPacketSender* _this, Packet* packet) {
	bool cancel = false;
	for (auto C : lClient->categories) {
		for (auto M : C->modules)
			if (M->isEnabled) M->onPacket(packet, &cancel);
	}
	if(!cancel) _Loopback(_this, packet);
}

void Loopback_Hook::init() {
	lClient = client;
	Utils::DebugLogF("Preparing to hook onto the Loopback sendToServer");
	uintptr_t sigAddr = Utils::FindSig("48 8B 41 10 4C 8B 09 4C 8B 40 48 41 80 B8 ? ? ? ? ? 74 04 49 FF 61 30 ");
	if (!sigAddr) return;
	if (MH_CreateHook((void*)sigAddr, &callback, reinterpret_cast<LPVOID*>(&_Loopback)) == MH_OK) {
		MH_EnableHook((void*)sigAddr);
		Utils::DebugLogF("Successfully completed Loopback Hook!");
	}
	else {
		Utils::DebugLogF("Failed to create Loopback Hook :/");
	}
}