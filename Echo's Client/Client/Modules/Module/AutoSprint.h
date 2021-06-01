#pragma once
#include "../Module.h"

class AutoSprint : public Module {
public:
	AutoSprint(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};