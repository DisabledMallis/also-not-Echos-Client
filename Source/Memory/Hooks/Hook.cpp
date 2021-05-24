#include "Hook.h"
#include "../../Client/Client.h"
#include "../../Utils/Utils.h"

Client* Hook::client;

void Hook::initHook(Client* client) {
	static bool once = false;
	Hook::client = client;
	if (!once) {
		once = true;
		client->dis = new PLH::CapstoneDisassembler(PLH::Mode::x64);
		if (client->dis != nullptr) {
			Utils::DebugLogF("Successfully initialized MinHook", std::string(client->name + "/Logs/Output.txt").c_str());
		}
		else {
			Utils::DebugLogF("Failed to initialize MinHook", std::string(client->name + "/Logs/Output.txt").c_str());
		}
	}
}