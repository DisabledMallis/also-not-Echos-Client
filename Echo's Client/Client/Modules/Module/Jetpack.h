#pragma once
#include "../Module.h"

class Jetpack : public Module {
public:
	Jetpack(class Client* client, class Category* category, std::string name) : Module(client, category, name, 0x46) {};
	void onLoop();
	void onGmTick(class GameMode*);

	float speed = 1.0f;
};