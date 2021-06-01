#pragma once
#include "../Module.h"

class Step : public Module {
public:
	Step(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	void onDisable();
};