#pragma once

class Material {
public:
	uintptr_t unknown;
	char pad_0001[4]; //0x0001
	bool isSolidBlocking; //0x0005
	bool isDestroyable; //0x0006
	bool isTopSolid; //0x0007
	char pad_0008[4]; //0x0008
	float translucency; //0x000C
	char pad_0010[2]; //0x0010
	bool isSolid; //0x0012
	bool isSuperHot; //0x0013

};

class BlockLegacy {
private:
	char pad_0x0000[0xD8]; //0x0000
public:
	Material* Material; //0x00D8
};

class Block {
private:
	char pad_0x0000[0x10]; //0x0000
public:
	BlockLegacy* BlockLegacy; //0x0010
};