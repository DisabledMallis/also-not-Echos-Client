#include "AutoSprint.h"

void AutoSprint::onGmTick(GameMode* GM) {
	if (player->velocity()->magnitudexz() > 0.05f) player->setSprinting(true);
}