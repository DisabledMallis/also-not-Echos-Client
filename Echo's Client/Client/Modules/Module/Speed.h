#pragma once
#include "../Module.h"

class Speed : public Module {
public:
	Speed(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);

	float speed = .3f;
};