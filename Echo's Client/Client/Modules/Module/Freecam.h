#pragma once
#include "../Module.h"

class Freecam : public Module {
public:
	Freecam(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onLoop();
	void onPacket(class Packet*, bool*);
	void onEnable();
	void onDisable();
};