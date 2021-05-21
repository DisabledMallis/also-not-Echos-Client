#pragma once

class LevelData {
public:
	//
};

class Level {
private:
	virtual ~Level();
	virtual void Function0();
public:
	virtual void postProcessResources(void);
	virtual void startLeaveGame(void);
	virtual bool isLeaveGameDone(void);
	virtual void createDimension(int);
	virtual class Dimension* getDimension(int);
	virtual void forEachDimension(std::function<bool(Dimension const&)>);
private:
	virtual void _forEachDimension(std::function<bool(Dimension const&)>);
public:
	virtual int getChunkTickRange(void);
	class PortalForcer* getPortalForcer(void);
private:
	virtual void Function10();
public:
	virtual void entityChangeDimension(Actor&, int);
	virtual class Spawner* getSpawner(void);
	virtual class ProjectileFactory* getProjectileFactory(void);
	virtual class ActorDefinitionGroup* getEntityDefinitions(void);
	virtual class ActorAnimationGroup getActorAnimationGroup(void);
	virtual class ActorAnimationControllerGroup* getActorAnimationControllerGroup(void);
	virtual class BlockDefinitionGroup* getBlockDefinitions(void);
	virtual class BlockComponentFactory* getBlockComponentFactory(void);
	virtual class BlockComponentFactory* getBlockComponentFactoryA(void);
	virtual class ActorSpawnRuleGroup* getSpawnRules(void);
	virtual class SpawnGroupRegistry* getSpawnGroupRegistry(void);
	virtual class ActorSpawnRuleGroup* getSpawnRulesA(void);
	virtual class SpawnSettings* getSpawnSettings(void);
	virtual void setSpawnSettings(class SpawnSettings const&);
	virtual class BehaviourTreeGroup* getBehaviorTreeGroup(void);
	virtual class BehaviourFactory* getBehaviorFactory(void);
	virtual int getDifficulty(void);
	virtual class DimensionConversionData* getDimensionConversionData(void);
	virtual __int64 getSpecialMultiplier(int dimensionId);
	virtual bool hasCommandsEnabled(void);
	virtual bool useMsaGamertagsOnly(void);
	virtual void setMsaGamertagsOnly(bool);
	virtual void addEntity(class BlockSource&, std::unique_ptr<Actor, std::default_delete<class Actor>>);
	virtual void addGlobalEntity(class BlockSource&, std::unique_ptr<class Actor, std::default_delete<class Actor>>);
	virtual void addAutonomousEntity(class BlockSource&, std::unique_ptr<class Actor, std::default_delete<class Actor>>);
	virtual void addPlayer(std::unique_ptr<class Player, std::default_delete<class Player>>);
	virtual void suspendPlayer(class Player&);
	virtual void resumePlayer(class Player&);
	virtual bool isPlayerSuspended(class Player&);
	virtual class Actor* takeEntity(__int64 ActorUniqueID);
	virtual class Actor* borrowEntity(__int64 ActorUniqueID);
	virtual class Actor* fetchEntity(__int64 ActorUniqueID, bool);
	virtual __int64 getRuntimeEntity(__int64 ActorRuntimeID, bool);
	virtual class Actor* getMob(__int64 ActorUniqueID);
	virtual class Actor* getPlayer(__int64 ActorUniqueID);
private:
	//virtual class Actor* getPlayer(mce::UUID const&);
	virtual void Function46();
public:
	virtual class Actor* getPlayer(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual class Actor* getPlayerByXuid(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual class Actor* getPlayerFromUnknownIdentifier(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
private:
	virtual void Function50();
	virtual void Function51();
public:
	virtual class Actor* getRuntimePlayer(int ActorRuntimeID);
	virtual class Actor* getNextPlayer(__int64 ActorUniqueID, bool);
	virtual class Actor* getPrevPlayer(__int64 ActorUniqueID, bool);
	virtual std::vector<class Actor*> getNumRemotePlayers(void);
	virtual class Actor* getPrimaryLocalPlayer(void);
	virtual class Actor* getRandomPlayer(void);
	virtual __int64 getNewPlayerId(void);
	virtual class MinecraftEventing* getEventing(void);
	virtual __int64 getPlayerColor(class Player const&);
	virtual class Tick* getCurrentTick(void);
	virtual class Tick* getCurrentServerTick(void);
	virtual void removeAllNonPlayerEntities(__int64 ActorUniqueID);
	virtual class BiomeRegistry* getBiomeRegistry(void);
	virtual class BiomeRegistry* getBiomeRegistryA(void);
	virtual class BlockPallete* getBlockPalette(void);
	virtual class BlockPallete* getBlockPaletteA(void);
	virtual class FeatureRegistry* getFeatureRegistry(void);
	virtual class FeatureRegistry* getFeatureRegistryA(void);
	virtual class FeatureTypeFactory* getFeatureTypeFactory(void);
	virtual class FeatureTypeFactory* getFeatureTypeFactoryA(void);
	virtual class JigsawStructureRegistry* getJigsawStructureRegistry(void);
	virtual class JigsawStructureRegistry* getJigsawStructureRegistryA(void);
	virtual __int64 getStructureManager(void);
	virtual __int64 getStructureManagerA(void);
	virtual class BiomeComponentFactory* getBiomeComponentFactory(void);
	virtual class BiomeComponentFactory* getBiomeComponentFactoryA(void);
	virtual class BuilderSurfaceRegistry* getSurfaceBuilderRegistry(void);
	virtual class BuilderSurfaceRegistry* getSurfaceBuilderRegistryA(void);
	virtual __int64 getDimensionFactory(void);
	virtual __int64 getDimensionFactoryA(void);
	virtual __int64 getLightTextureImageBuilderFactory(void);
	virtual __int64 getLightTextureImageBuilderFactoryA(void);
	virtual void addListener(class LevelListener&);
	virtual void removeListener(class LevelListener&);
	virtual void tickEntities(void);
	virtual void tickEntitySystems(void);
	virtual void nPlayerDeath(class Player&, class ActorDamageSource const&);
	virtual void tick(void);
private:
	virtual void Function90();
	virtual void Function91();
public:
	virtual void animateTick(class Actor&);
	virtual void explode(class Explosion&);
	virtual void explode(class BlockSource&, class Actor*, Vec3 const&, float, bool, bool, float, bool);
	virtual void spawnParticleEffect(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, class Actor const&, Vec3 const&);
	virtual void spawnParticleEffect(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vec3 const&, class Dimension*);
	virtual void denyEffect(class BlockSource&, Vec3 const&);
	virtual void potionSplash(Vec3 const&, /*mce::Color const&*/ __int64 color, bool);
	virtual void checkAndHandleWater(class Actor*);
	virtual void checkMaterial(AABB const&, class MaterialType, class BlockSource&);
	virtual void extinguishFire(class BlockSource&,  /*class BlockPos*/Vec3i const&, unsigned char);
	virtual __int64 findPath(class Actor&, class Actor&, class NavigationComponent&);
	virtual __int64 findPath(class Actor&, int, int, int, class NavigationComponent&);
	virtual void updateSleepingPlayerList(void);
	virtual __int64 getTime(void);
	virtual void setTime(int);
	virtual unsigned int getSeed(void);
	virtual class  /*class BlockPos*/Vec3i* getDefaultSpawn(void);
	virtual void setDefaultSpawn(class BlockPos const&);
	virtual class  /*class BlockPos*/Vec3i* getDefaultSpawnA(void);
	virtual void setDefaultGameType(int GameType);
	virtual int getDefaultGameType(void);
	virtual void setDifficulty(int Difficulty);
	virtual void setMultiplayerGameIntent(bool);
	virtual bool getMultiplayerGameIntent(void);
	virtual void setMultiplayerGame(bool);
	virtual bool isMultiplayerGame(void);
	virtual void setLANBroadcastIntent(bool);
	virtual bool getLANBroadcastIntent(void);
	virtual void setLANBroadcast(bool);
	virtual bool getLANBroadcast(void);
	virtual void setXBLBroadcastIntent(__int64 GamePublicSetting /*Social::GamePublishSetting*/);
	virtual __int64 getXBLBroadcastIntent(void);
	virtual bool hasXBLBroadcastIntent(void);
private:
	virtual void Function125();
	virtual void Function126();
	virtual void Function127();
	virtual void Function128();
	virtual void Function129();
	virtual void Function130();
public:
	virtual void setHasLockedBehaviorPack(bool);
	virtual void setHasLockedResourcePackA(bool);
	virtual void setCommandsEnabled(bool);
	virtual void setWorldTemplateOptionsUnlocked(void);
private:
	virtual void Function135();
public:
	virtual class LevelStorage* getLevelStorage(void);
	virtual class LevelStorage* getLevelStorageA(void);
private:
	virtual class LevelData* _getLevelData(void);
public:
	virtual class LevelData* getLevelData(void);
	virtual class PhotoStorage* getPhotoStorage(void);
	virtual void createPhotoStorage(void);
	virtual void setEducationLevelSettings(class EducationLevelSettings);
	virtual __int64 getEducationLevelSettings(void);
	virtual void save(void);
	virtual void saveEducationLevelSettings(void);
	virtual void saveLevelData(void);
	virtual void saveGameData(void);
	virtual void saveVillages(void);
	virtual void savePlayers(void);
	virtual void savePlayer(class Player&);
	virtual void saveBiomeData(void);
	virtual void saveDirtyChunks(void);
	virtual void saveAdditionalData(void);
	virtual void requestTimedStorageDeferment(void);
	virtual void _checkUserStorage(void);
	virtual class TickingAreasManager* getTickingAreasMgr(void);
	virtual class Tick* getTickingArea(__int64/*mce::UUID const&*/);
	virtual void addParticle(class ParticleType, Vec3 const&, Vec3 const&, int, class CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(class ParticleType, Vec3 const&, Vec3 const&, int);
	virtual void playSound(class BlockSource&, class LevelSoundEvent, Vec3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void handleSoundEvent(class LevelSoundEvent, Vec3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void playSynchronizedSound(class BlockSource&, class LevelSoundEvent, Vec3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void playSynchronizedSound(class BlockSource&, class LevelSoundEvent, Vec3 const&, Block const&, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void setRemotePlayerEventCoordinator(std::unique_ptr<class PlayerEventCoordinator, std::default_delete<class PlayerEventCoordinator>>&&);
	virtual class PlayerEventCoordinator* getRemotePlayerEventCoordinator(void);
	virtual void setServerPlayerEventCoordinator(std::unique_ptr<class ServerPlayerEventCoordinator, std::default_delete<class ServerPlayerEventCoordinator>>&&);
	virtual class ServerPlayerEventCoordinator* getServerPlayerEventCoordinator(void);
	virtual void setClientPlayerEventCoordinator(std::unique_ptr<class ClientPlayerEventCoordinator, std::default_delete<class ClientPlayerEventCoordinator>>&&);
	virtual class ClientPlayerEventCoordinator* getClientPlayerEventCoordinator(void);
	virtual void setActorEventCoordinator(std::unique_ptr<class ActorEventCoordinator, std::default_delete<class ActorEventCoordinator>>&&);
	virtual class ActorEventCoordinator* getActorEventCoordinator(void);
	virtual void setBlockEventCoordinator(std::unique_ptr<class BlockEventCoordinator, std::default_delete<class BlockEventCoordinator>>&&);
	virtual class BlockEventCoordinator* getBlockEventCoordinator(void);
	virtual void setItemEventCoordinator(std::unique_ptr<class ItemEventCoordinator, std::default_delete<class ItemEventCoordinator>>&&);
	virtual class ItemEventCoordinator* getItemEventCoordinator(void);
	virtual class LevelEventCoordinator* getLevelEventCoordinator(void);
	virtual void handleLevelEvent(class LevelEvent, class CompoundTag const&);
	virtual void handleLevelEvent(class LevelEvent, Vec3 const&, int);
	virtual void handleSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vec3 const&, float, float);
private:
	//virtual void handleSoundEvent(class LevelSoundEvent, Vec3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void Function80();
public:
	virtual void handleStopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void handleStopAllSounds(void);
	virtual void broadcastLevelEvent(class LevelEvent, class CompoundTag const&, class Player*);
	virtual void broadcastLevelEvent(class LevelEvent, Vec3 const&, int, class Player*);
	virtual void broadcastLocalEvent(class BlockSource&, class LevelEvent, Vec3 const&, Block const&);
	virtual void broadcastLocalEvent(class BlockSource&, class LevelEvent, Vec3 const&, int);
	virtual void broadcastSoundEvent(class BlockSource&, class LevelSoundEvent, Vec3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void broadcastSoundEvent(class BlockSource&, class LevelSoundEvent, Vec3 const&, Block const&, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void broadcastActorEvent(class Actor&, class ActorEvent, int);
	virtual void addBossEventListener(class BossEventListener*);
	virtual void removeBossEventListener(class BossEventListener*);
	virtual void broadcastBossEvent(class BossEventUpdateType);
	virtual void broadcastBossEvent(class BossEventUpdateType, __int64 ActorUniqueID/*const&*/, class BossEventPacket const&);
	virtual void pruneChunkViewTrackers(void);
	virtual void onChunkReload(class Bounds const&);
	virtual std::vector<__int64> getPlayerNames(void);
	virtual __int64 getActivePlayerCount(void);
private:
	virtual void _forEachPlayer(std::function<bool(class Player const&)>);
public:
	virtual void forEachPlayer(std::function<bool(class Player const&)>);
	virtual void findPlayer(std::function<bool(class Player const&)>);
	virtual __int64 getUserCount(void);
private:
	virtual void Function202();
	virtual void Function203();
	virtual void Function204();
	virtual void Function205();
public:
	virtual void queueEntityRemoval(std::unique_ptr<Actor, std::default_delete<class Actor>>&&, bool);
	virtual void removeEntityReferences(Actor&, bool);
	virtual void forceRemoveEntity(class Actor&);
	virtual void forceFlushRemovedPlayers(void);
	virtual void loadFunctionManager(void);
	virtual void levelCleanupQueueEntityRemoval(std::unique_ptr<class Actor, std::default_delete<class Actor>>&&, bool);
private:
	virtual void Function212();
	virtual void Function213();
public:
	virtual void destroyBlock(class BlockSource&, /*class BlockPos*/Vec3i const&, bool);
	virtual void upgradeStorageVersion(class StorageVersion);
	virtual void suspendAndSave(void);
	virtual void waitAsyncSuspendWork(void);
	virtual void _destroyEffect( /*class BlockPos*/Vec3i const&, class Block const&, int);
	/* Lots more but fuck this shit = Jesus Fucking Christ */
public:
	char pad_0x0008[0x50]; //0x0008
	uintptr_t* entListStart; //0x0058
	uintptr_t* entListEnd; //0x0060

	std::vector<class Actor*> getEntities() {
		size_t size = (entListEnd - entListStart) / sizeof(uintptr_t);
		std::vector<class Actor*> ents;
		for (size_t i = 0; i < size; i++) {
			class Actor* curr = *reinterpret_cast<class Actor**>(entListStart + (i * sizeof(uintptr_t)));
			if (curr != nullptr) ents.push_back(curr);
		}
		return ents;
	}
};