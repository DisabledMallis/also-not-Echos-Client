#pragma once
#include "../../Client.h"
#include "../Module.h"

class TestMod : public Module {
public:
	TestMod(class Client* i, class Category* c, std::string n) : Module(i, c, n) {};

	void onEnable();
	void onDisable();
	void onTick();

	void onGmTick(GameMode*);
	void onKey(uint64_t, bool, bool*);
	void onRender(class Renderer*);
	void onPacket(class Packet*, bool*);
};