#include "Killaura.h"

void Killaura::onGmTick(GameMode* GM) {
	auto level = player->getMultiPlayerLevel();
	auto entities = level->getEntities();
	auto myPos = *player->getPos();
	for (auto ent : entities) {
		if (ent == player) continue;
		if (ent->getPos()->distance(myPos) <= range) {
			GM->attack(ent);
			player->swing();
		}
	}
}