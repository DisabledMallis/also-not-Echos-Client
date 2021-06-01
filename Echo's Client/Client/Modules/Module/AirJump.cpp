#include "AirJump.h"

void AirJump::onGmTick(GameMode* GM) {
	//*(bool*)((uintptr_t)(player)+0x1C0) = true;
	*player->onGround() = true;
 }