#pragma once
#include <MinHook.h>

class Hook {
public:
	virtual void init() {};

	static void initMH(class Client*);
	static Client* client;
};