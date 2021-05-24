#pragma once
#include "../Minecraft.h"
#include "GuiData.h"
#include "ItemStack.h"
#include "Player.h"
#include "PlayerInventory.h"
#include "GameMode.h"
#include "BlockSource.h"
#include "Dimension.h"
#include "Level.h"
#include "Block.h"

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
};