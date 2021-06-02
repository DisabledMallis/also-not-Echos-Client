#include "TestMod.h"

void TestMod::onEnable() {
	//
}

void TestMod::onDisable() {
	//
}

void TestMod::onTick() {
	//
}

void TestMod::onKey(uint64_t key, bool isDown, bool* cancelOrigin) {
	/*if (isDown) {
		std::ostringstream o;
		o << "Key Pressed Down: " << std::hex << key << std::endl;
		Utils::DebugLogF(o.str().c_str());
	}*/
}

void TestMod::onRender(class Renderer* renderer) {
	//renderer->drawString(L"Test", 20.f, Vec2(30.f, 30.f), 0xff60c8d1);
}

bool forEachDimensionCallback(const Dimension& dimension) {
	auto d = (Dimension*)&dimension;
	Utils::DebugLogF(std::to_string(d->height).c_str());

	std::ostringstream o;
	o << std::hex << d << std::endl;
	Utils::DebugLogF(o.str().c_str());

	return false;
}

void TestMod::onGmTick(GameMode* GM) {
	static bool once = false;
	if (player != nullptr) {
		if (!once) {
			once = true;
		}
	}
	else once = false;
}

void TestMod::onPacket(Packet* packet) {
	if (packet->instanceOf<MovePlayerPacket>()) {
		Utils::DebugLogF("Move Packet!");
	}
	if (packet->instanceOf<PlayerAuthInputPacket>()) {
		Utils::DebugLogF("PlayerAuthInput Packet!");
	}
}