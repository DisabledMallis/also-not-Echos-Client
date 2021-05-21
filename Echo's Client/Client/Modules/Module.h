#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <thread>

#include "../../Memory/SDK/Minecraft.h"

#include "../../Utils/Utils.h"
#include "../../Utils/Renderer.h"

class Module {
public:
	class Client* client;
	class Category* category;

	std::thread moduleThread;

	std::string name;
	bool isEnabled = false;
	bool wasEnabled = false;

	void baseTick();

	virtual void onEnable() {};
	virtual void onDisable() {};
	virtual void onTick() {};

	virtual void onGmTick(GameMode*) {};

	virtual void onKey(uint64_t, bool, bool*) {};

	virtual void onRender(class Renderer*) {};

	Module(class Client*, class Category*, std::string);

	ClientInstance* instance;
	Player* player;
};