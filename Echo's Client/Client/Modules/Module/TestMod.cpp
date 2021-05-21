#include "TestMod.h"
#include "../../../Utils/Utils.h"

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
	if (isDown) {
		std::ostringstream o;
		o << "Key Pressed Down: " << std::hex << key << std::endl;
		Utils::DebugLogF(o.str().c_str());
	}
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