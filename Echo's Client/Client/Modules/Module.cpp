#include "Module.h"

#include "../Client.h"
#include "../Categories/Category.h"

Module::Module(class Client* client, class Category* category, std::string name, uint64_t key) {
	this->client = client;
	this->category = category;
	this->name = name;
	this->key = key;

	this->category->modules.push_back(this);
}

void Module::baseTick() {
	onLoop();
	if (isEnabled != wasEnabled) {
		if (isEnabled) {
			onEnable();
		}
		else {
			onDisable();
		}
		wasEnabled = isEnabled;
	}
	if (isEnabled) onTick();
}