#include "Speed.h"
#include "../../Client.h"

void Speed::onGmTick(GameMode* GM) {
	if (instance == nullptr || instance->minecraftGame() == nullptr || !instance->minecraftGame()->canUseKeys)
		return;

	bool wKey = client->keyMap[0x57], sKey = client->keyMap[0x53], aKey = client->keyMap[0x41], dKey = client->keyMap[0x44];
	auto rot = *player->bodyRot();
	float yaw = rot.y;

	if (wKey) {
		if (!aKey && !dKey) {
			yaw += 90.f;
		}
		else if (aKey) {
			yaw += 45.f;
		}
		else if (dKey) {
			yaw += 135.f;
		}
	}
	else if (sKey) {
		if (!aKey && !dKey) {
			yaw -= 90.f;
		}
		else if (aKey) {
			yaw -= 45.f;
		}
		else if (dKey) {
			yaw -= 135.f;
		}
	}
	else if (!wKey && !sKey) {
		if (dKey) yaw += 180.f;
	}

	if(wKey || sKey || aKey || dKey)
		*player->velocity() = Vec3(cos((yaw) * (PI / 180.f)) * speed, player->velocity()->y, sin((yaw) * (PI / 180.f)) * speed);
}