#include "AutoSprint.h"

void AutoSprint::onGmTick(GameMode* GM) {
	GM->player->setSprinting(true);
}