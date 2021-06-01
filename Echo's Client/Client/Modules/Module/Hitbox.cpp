#include "Hitbox.h"

void Hitbox::onGmTick(GameMode* GM) {
	if (player == nullptr || player->getMultiPlayerLevel() == nullptr) return;
	auto entities = player->getMultiPlayerLevel()->getEntities();
	for (auto ent : entities) {
		if (ent == player) continue;
		ent->setSize(shadowX, shadowY);
	}
}

void Hitbox::onDisable() {
	if (player == nullptr || player->getMultiPlayerLevel() == nullptr) return;
	auto entities = player->getMultiPlayerLevel()->getEntities();
	for (auto ent : entities) {
		if (ent == player) continue;
		ent->setSize(0.6, 1.8);
	}
}