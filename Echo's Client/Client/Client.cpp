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
#include "Modules/Module/Hitbox.h"
/* Movement */
#include "Modules/Module/AutoSprint.h"
#include "Modules/Module/AirJump.h"
#include "Modules/Module/Step.h"
#include "Modules/Module/Speed.h"
#include "Modules/Module/Jetpack.h"
/* Player */
#include "Modules/Module/Coords.h"
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

	this->isRunning = true;

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
	Category* exploits = new Category(this, "Exploits");
	Category* other = new Category(this, "Other");

	/* Initialize Modules */

	/* Combat */
	new Killaura(this, combat, "Killaura");
	new Hitbox(this, combat, "Hitbox");
	/* Movement */
	new AutoSprint(this, movement, "AutoSprint");
	new AirJump(this, movement, "AirJump");
	new Step(this, movement, "Step");
	new Speed(this, movement, "Speed");
	new Jetpack(this, movement, "Jetpack");
	/* Player */
	new Coords(this, player, "Coordinates");
	/* Visuals */
	new TabGui(this, visuals, "TabGui");
	/* World */
	/* Other */
	new TestMod(this, other, "Test Module");
	new Uninject(this, other, "Uninject");

	/*modulesThread = std::thread([this] {
		while (isRunning) {
			for (auto C : this->categories) {
				for (auto M : C->modules) M->baseTick();
			}
		}
	});*/

	while (isRunning) {
		for (auto C : this->categories) {
			for (auto M : C->modules) M->baseTick();
		}
	}
}