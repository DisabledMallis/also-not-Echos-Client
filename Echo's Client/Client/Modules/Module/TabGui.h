#pragma once
#include "../../Client.h"
#include "../Module.h"

class TabGui : public Module {
public:
	TabGui(class Client* i, class Category* c, std::string n) : Module(i, c, n) {};

	void onRender(class Renderer*);
	void renderLogo(class Renderer*);
	void onKey(uint64_t, bool, bool*);

	int sCIndex; /* Selected Category Index */
	int sMIndex; /* Selected Module Index */

	bool sCat = false;
	bool sMod = false;
};