#pragma once
#include <Windows.h>
#include <vector>
#include <string>

class Category {
public:
	class Client* client;

	std::string name;
	std::vector<class Module*> modules;

	Category(Client*, std::string);
};