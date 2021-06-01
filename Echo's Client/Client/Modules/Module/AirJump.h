#pragma once
#include "../Module.h"

class AirJump : public Module {
public:
	AirJump(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};