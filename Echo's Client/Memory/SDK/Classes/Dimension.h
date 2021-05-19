#pragma once
#include <cstdint>
#include <memory>

class ChunkSource {
private:
	virtual ~ChunkSource();
public:
	virtual void shutdown(void);
	virtual bool isShutdownDone(void);
private:
	virtual void Function3();
	virtual void Function4();
public:
	virtual void createNewChunk(class ChunkPos const&, int LoadMode, bool);
	virtual void getOrLoadChunk(class ChunkPos const&, int loadMode, bool);
private:
	virtual void Function7();
	virtual void Function8();
public:
	virtual void loadChunk(class LevelChunk&, bool);
	virtual void postProcessMobsAt(class BlockSource&, int, int, struct Random&);
	virtual void saveLiveChunk(class LevelChunk&);
	virtual void hintDiscardBatchBegin(void);
	virtual void hintDiscardBatchEnd(void);
	virtual void acquireDiscarded(std::unique_ptr<class LevelChunk, class LevelChunkFinalDeleter>);
	virtual void compact(void);
	virtual void flushPendingWrites(void);
public:
	//
};

class WorldGenerator {
public:
	//
};

class Dimension { 
public:
	char pad_0000[90]; //0x0000
	uint16_t height; //0x005A
	char pad_005B[125]; //0x005B
	uint16_t dimensionId; //0x00D8
	char pad_00D9[7]; //0x00D9
	bool isDay; //0x00E0
	char pad_00E1[31]; //0x00E1
	class ChunkSource* chunkSource; //0x0100
	class WorldGenerator* worldGenerator; //0x0108
	class Weather* weather; //0x0110
	char pad_0118[48]; //0x0118
public:
	void forEachPlayer(std::function<bool(class Player const&)> f) {
		using FEP = void(__fastcall*)(Dimension*, std::function<bool(class Player const&)>);
		static FEP _FEP = reinterpret_cast<FEP>(Utils::FindSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? ? ? 48 8B DA 48 8B F9  48 3B CA ? ? 48 8B 49 ?"));
		_FEP(this, f);
	}
};

class Weather {
public:
	char pad_0000[56]; //0x0000
	bool isRaining; //0x0038
	char pad_0039[11]; //0x0039
	bool isLightning; //0x0044
	char pad_0045[3]; //0x0045
	float lightningLevel; //0x0048
	char pad_004C[56]; //0x004C
};