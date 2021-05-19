#include "Client.h"
#include "../Utils/Utils.h"

Client::Client(std::string name) {
	this->name = name;
	Utils::DebugLogF("Client Instance has been Initialized", std::string(name + "/Logs/Output.txt").c_str(), true);
}

#include "../Memory/Hooks/Hook.h"

#include "../Memory/Hooks/Hook/ClientInstance.h"
#include "../Memory/Hooks/Hook/GameMode.h"

#include "Modules/Module/TestMod.h"

void Client::init() {

	Utils::DebugLogF("Initializing Client...");

	Hook::initMH(this); /* Initialize MinHook */

	/* Initialize Client Instance Hook */
	CInstance_Hook* cI_Hook = new CInstance_Hook();
	cI_Hook->init();

	/* Initialize GameMode tick */
	GameMode_Hook* gm_Hook = new GameMode_Hook();
	gm_Hook->init();

	/* Initialize Categories */

	Category* combat = new Category(this, "Combat");
	Category* movement = new Category(this, "Movement");
	Category* player = new Category(this, "Player");
	Category* visuals = new Category(this, "Visuals");
	Category* other = new Category(this, "Other");

	/* Initialize Modules */

	TestMod* testMod = new TestMod(this, other, "Test Module");
}