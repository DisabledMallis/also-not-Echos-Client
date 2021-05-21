#pragma once
#include <span>

class LevelChunk {
public:
	char pad_0000[80]; //0x0000
	class Level* level; //0x0050
	class Dimension* dimension; //0x0058
	char pad_0060[12]; //0x0060
	Vec3i chunkPos; //0x006C
};

class BlockSource {
public:
	Block* getBlock(Vec3i blockPos) {
		using GetBlock = Block * (__thiscall*)(BlockSource*, Vec3i*);
		static GetBlock _GetBlock = reinterpret_cast<GetBlock>(Utils::FindSig("48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 48 8B DA 8B 4A 04 0F BF 47 2A 3B C8 7C 67 0F BF 47 28 3B C8"));
		return _GetBlock(this, &blockPos);
	}

	LevelChunk* getLevelChunk() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 86 ? ? ? ? E9 ? ? ? ? 48 8B 4E ? 4C 8B C2 44 38 7E ? ? ? 48") + 3);
		return *reinterpret_cast<class LevelChunk**>((uintptr_t)(this) + offset);
	}
};