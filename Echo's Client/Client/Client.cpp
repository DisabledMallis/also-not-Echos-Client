#include "Client.h"
#include "../Utils/Utils.h"
#include "../Utils/Renderer.h"

Client::Client(std::string name) {
	this->name = name;
	Utils::DebugLogF("Client Instance has been Initialized", std::string(name + "/Logs/Output.txt").c_str(), true);
}

/* Hook Includes */

#include "../Memory/Hooks/Hook.h"

#include "../Memory/Hooks/Hook/ClientInstance.h"
#include "../Memory/Hooks/Hook/GameMode.h"
#include "../Memory/Hooks/Hook/Actor.h"

#include "../Memory/Hooks/Hook/KeyItem.h"

#include "../Memory/Hooks/Hook/SwapChain.h"

/* Module Includes */

/* Combat */
#include "Modules/Module/Killaura.h"
/* Movement */
#include "Modules/Module/AutoSprint.h"
/* Player */
/* Visuals */
#include "Modules/Module/TabGui.h"
/* World */
/* Other */
#include "Modules/Module/TestMod.h"
#include "Modules/Module/Uninject.h"

/* */

void Client::init() {

	Utils::DebugLogF("Initializing Client...");

	Hook::initMH(this); /* Initialize MinHook */

	/* Initialize SwapChain (Dx11) Hook */

	SwapChain_Hook* swapChain_Hook = new SwapChain_Hook();
	swapChain_Hook->init();

	/* Initialize Client Instance Hook */
	CInstance_Hook* cI_Hook = new CInstance_Hook();
	cI_Hook->init();

	/* Initialize GameMode tick */
	GameMode_Hook* gm_Hook = new GameMode_Hook();
	gm_Hook->init();

	/* Initialize Actor Hooks */
	Actor_Hook* actor_Hook = new Actor_Hook();
	actor_Hook->init();

	/* Initialize AVKeyItem Hook */
	KeyItem_Hook* key_Hook = new KeyItem_Hook();
	key_Hook->init();

	/* Initialize Categories */

	Category* combat = new Category(this, "Combat");
	Category* movement = new Category(this, "Movement");
	Category* player = new Category(this, "Player");
	Category* visuals = new Category(this, "Visuals");
	Category* world = new Category(this, "World");
	Category* other = new Category(this, "Other");

	/* Initialize Modules */

	/* Combat */
	Killaura* killauraMod = new Killaura(this, combat, "Killaura");
	/* Movement */
	AutoSprint* sprintMod = new AutoSprint(this, movement, "AutoSprint");
	/* Player */
	/* Visuals */
	TabGui* TabGuiMod = new TabGui(this, visuals, "TabGui");
	/* World */
	/* Other */
	TestMod* testMod = new TestMod(this, other, "Test Module");
	Uninject* uninjectMod = new Uninject(this, other, "Uninject");
}