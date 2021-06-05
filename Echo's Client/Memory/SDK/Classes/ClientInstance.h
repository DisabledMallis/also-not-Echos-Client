#pragma once
#include "../Minecraft.h"
#include "MinecraftGame.h"
#include "GuiData.h"
#include "ItemStack.h"
#include "Player.h"
#include "PlayerInventory.h"
#include "GameMode.h"
#include "BlockSource.h"
#include "Dimension.h"
#include "Level.h"
#include "Block.h"

#include "LoopbackPacketSender.h"
#include "Packet.h"

class ClientInstance {
public:
	class Player* GetLocalPlayer() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC CC CC 48 89 91 ? ? ? ?") + 3);
		return *reinterpret_cast<Player**>((uintptr_t)(this) + offset);
	}
	class MinecraftGame* minecraftGame() {
		return *reinterpret_cast<MinecraftGame**>((uintptr_t)(this) + 0x98);
	}

	class GuiData* guiData() {
		return *reinterpret_cast<GuiData**>((uintptr_t)(this) + 0x4D8);
	}

	class LoopbackPacketSender* loopbackPacketSender() {
		/*static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 88 ? ? ? ? 48 8B D3 48 8B 01 48 83 C4 20") + 3); //Offset in LoopbackPacketSender::flush */
		return *reinterpret_cast<LoopbackPacketSender**>((uintptr_t)(this) + 0xD0);
	}
};