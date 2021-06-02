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

	uint64_t key;

	void baseTick();

	virtual void onLoop() {};

	virtual void onEnable() {};
	virtual void onDisable() {};
	virtual void onTick() {};

	virtual void onGmTick(GameMode*) {};

	virtual void onKey(uint64_t, bool, bool*) {};

	virtual void onRender(class Renderer*) {};

	virtual void onPacket(class Packet*, bool* cancel = (bool)false) {};

	Module(class Client* client, class Category* category, std::string name, uint64_t key = 0);

	ClientInstance* instance;
	Player* player;
};