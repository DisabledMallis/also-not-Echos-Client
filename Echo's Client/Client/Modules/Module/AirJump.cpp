#include "AirJump.h"

void AirJump::onGmTick(GameMode* GM) {
	*player->onGround() = true;
 }