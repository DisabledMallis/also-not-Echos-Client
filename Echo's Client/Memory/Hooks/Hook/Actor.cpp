#include "Actor.h"
#include "../../../Client/Client.h"

void Actor_Hook::init() {
	//Utils::DebugLogF("Preparing to hook onto the Actor VTables");
	uintptr_t sigAddr = Utils::FindSig("48 8D 05 ? ? ? ? 48 89 01 48 83 C1 08 48 89 4C 24 ? 33 D2");
	if (!sigAddr) return;
	
	//
}