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
			//MovePlayerPacket* packet = new MovePlayerPacket(player->getActorId(), *player->getPos(), *player->bodyRot());
			//Utils::DebugLogF("Sending the packet..");
			//instance->loopbackPacketSender()->send(packet);
		}
	}
	else once = false;
}

void TestMod::onPacket(Packet* packet, bool*) {
	if (packet->instanceOf<MovePlayerPacket>()) {
		static int packetID = 0;
		auto curr = (MovePlayerPacket*)packet;

		char mem[0x110];
		memcpy(mem, packet, 0x110);

		std::string fName = std::string("move-" + std::to_string(packetID));
		std::string path = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + fName);

		std::ofstream fout;
		fout.open(path, std::ios::binary | std::ios::out);
		fout.write(mem, 0x0110);
		fout.close();

		packetID++;
	}
	if (packet->instanceOf<PlayerAuthInputPacket>()) {
		/*static int packetID = 0;
		auto curr = (MovePlayerPacket*)packet;

		char mem[0x400];
		memcpy(mem, packet, 0x400);

		std::string fName = std::string("auth-" + std::to_string(packetID));
		std::string path = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + fName);

		std::ofstream fout;
		fout.open(path, std::ios::binary | std::ios::out);
		fout.write(mem, 0x0400);
		fout.close();

		packetID++;*/
	}
}