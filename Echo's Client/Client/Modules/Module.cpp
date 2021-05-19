#include "Module.h"

#include "../Client.h"
#include "../Categories/Category.h"

Module::Module(class Client* client, class Category* category, std::string name) {
	this->client = client;
	this->category = category;

	this->category->modules.push_back(this);

	this->moduleThread = std::thread([this] { this->baseTick(); });
}

void Module::baseTick() {
	while (true) {
		if (isEnabled != wasEnabled) {
			if (isEnabled) {
				onEnable();
			}
			else {
				onDisable();
			}
			wasEnabled = isEnabled;
		}
		if(isEnabled) onTick();
	}
}