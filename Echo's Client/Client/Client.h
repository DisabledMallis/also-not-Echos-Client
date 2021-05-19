#pragma once
#include <Windows.h>
#include <vector>
#include <string>

#include "Categories/Category.h"
#include "Modules/Module.h"

class Client {
public:
	HMODULE hModule;
	bool isRunning = false;

	std::string name;

	std::vector<Category*> categories;
	std::vector<Module*> modules;

	Client(std::string name);

	void init();
};

