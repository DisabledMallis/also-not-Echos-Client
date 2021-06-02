#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <map>

#include "Categories/Category.h"
#include "Modules/Module.h"

class Client {
public:
	HMODULE hModule;
	bool isRunning = false;

	std::string name;

	std::vector<Category*> categories;
	std::vector<Module*> modules;

	//std::thread modulesThread;

	Client(std::string name);

	std::map<uint64_t, bool> keyMap;

	void init();
};