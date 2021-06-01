#pragma once
#include "../Module.h"

class Uninject : public Module {
public:
	Uninject(class Client* i, class Category* c, std::string n) : Module(i, c, n) {};
	void onEnable();
};