#pragma once
#include "../Module.h"

class Killaura : public Module {
public:
	Killaura(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);

	float range = 12.0f;
};