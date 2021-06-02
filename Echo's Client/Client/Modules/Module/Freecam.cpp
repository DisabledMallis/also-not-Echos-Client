#include "Freecam.h"

Vec3 lastPos;
Vec2 lastRot;

std::vector<Packet*> packets;

void Freecam::onLoop() {
	if (player == nullptr) {
		isEnabled = false;
		lastPos = Vec3();
		lastRot = Vec2();
		packets.clear();
	}
}

void Freecam::onPacket(Packet* packet, bool* cancel) {
	if (packet->instanceOf<MovePlayerPacket>() || packet->instanceOf<PlayerAuthInputPacket>()) {
		packets.push_back(packet);
		*cancel = true;
	}
}

void Freecam::onEnable() {
	if (player == nullptr) return;
	lastPos = *player->getPos();
	lastRot = *player->bodyRot();
}

void Freecam::onDisable() {
	if (player != nullptr) {
		player->setPos(lastPos);
		*player->bodyRot() = lastRot;
	}
	lastPos = Vec3();
	lastRot = Vec2();
	packets.clear();
}