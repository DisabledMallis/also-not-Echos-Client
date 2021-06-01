#pragma once
#include "../Module.h"

class Hitbox : public Module {
public:
	Hitbox(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	void onDisable();
	
	float shadowX = 2.0f;
	float shadowY = 2.0f;
};