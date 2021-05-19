#pragma once

class Actor {
private:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
public:
	virtual void serverInitItemStackIds(void);
	virtual void _doInitialMove(void);
private:
	virtual void Function6();
public:
	virtual void reset(void);
	virtual __int64 getOnDeathExperience(void);
private:
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
public:
	virtual void setPos(Vec3 const&);
private:
	virtual void Function13();
public:
	virtual struct PredictedMovementValues* getPredictedMovementValues(void);
	//virtual struct StateVectorComponent* getStateVectorComponent(void);
	virtual Vec3* getPos(void);
	virtual Vec3* getPosOld(void);
	virtual Vec3* getPosExtrapolated(float);
	virtual Vec3* getAttachPos(Vec3 const & ActorLocation, float);
	virtual Vec3* getFiringPos(void);
	virtual void setRot(Vec2 const&);
	virtual void move(class IActorMovementProxy&, Vec3 const&);
	virtual void move(Vec3 const&);
	virtual Vec3* getInterpolatedRidingPosition(float);
	virtual Vec2* getInterpolatedBodyRot(float);
	virtual Vec2* getInterpolatedHeadRot(float);
	virtual float getInterpolatedBodyYaw(float);
	virtual float getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
	virtual Vec3 getWorldPosition(void);
	virtual void checkBlockCollisions(void);
	virtual void checkBlockCollisions(struct AABB const&, void*/*std::function<void(BlockSource&, Block const&, BlockPos const&, Actor&)>*/);
	virtual bool isFireImmune(void);
private:
	virtual void Function33();
	virtual void Function34();
public:
	virtual void teleportTo(Vec3 const&, bool, int, int);
	virtual void tryTeleportTo(Vec3 const&, bool, bool, int, int);
	virtual void chorusFruitTeleport(Vec3 const&);
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void lerpMotion(Vec3 const&);
private:
	virtual void Function40();
public:
	virtual void normalTick(void);
	virtual void baseTick(void);
	virtual void rideTick(void);
	virtual void positionRider(Actor&, float);
	virtual float getRidingHeight(void);
	virtual void startRiding(Actor&);
	virtual void addRider(Actor&);
	virtual void flagRiderToRemove(Actor&);
private:
	virtual void Function49();
public:
	virtual bool intersects(Vec3 const&, Vec3 const&);
	virtual bool isFree(Vec3 const&);
	virtual bool isFree(Vec3 const&, float);
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual bool canShowNameTag(void);
private:
	virtual void Function56();
public:
	virtual void setNameTagVisible(bool);
	virtual std::string getNameTag(void);
	virtual __int64 getNameTagAsHash(void);
private:
	virtual void Function60();
	virtual void Function61();
public:
	virtual void setNameTag(std::string const&);
private:
	virtual void Function63();
	virtual void Function64();
	virtual void Function65();
public:
	virtual bool isInWater(void);
	virtual bool hasEnteredWater(void);
	virtual bool isImmersedInWater(void);
	virtual bool isInWaterOrRain(void);
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(class MaterialType);
	virtual bool isOverWater(void);
	virtual void setBlockMovementSlowdownMultiplier(Vec3 const&);
	virtual void resetBlockMovementSlowdownMultiplier(void);
private:
	virtual void Function75();
public:
	virtual float getShadowHeightOffs(void);
	virtual float getShadowRadius(void);
	virtual Vec3 getHeadLookVector(float);
private:
	virtual void Function79();
public:
	virtual bool canSee(Vec3 const&);
	virtual bool canSee(Actor const&);
	virtual bool isSkyLit(float);
	virtual bool getBrightness(float);
private:
	virtual void Function84();
	virtual void Function85();
public:
	virtual bool onAboveBubbleColumn(bool);
	virtual bool onInsideBubbleColumn(bool);
	virtual bool isImmobile(void);
	virtual bool isSilent(void);
	virtual bool isPickable(void);
private:
	virtual void Function91();
public:
	virtual bool isSleeping(void);
private:
	virtual void Function93();
public:
	virtual void setSneaking(bool);
	virtual bool isBlocking(void);
private:
	virtual void Function96();
public:
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
	virtual bool isOnHotBlock(void);
private:
	virtual void Function100();
public:
	virtual bool isSurfaceMob(void);
private:
	virtual void Function102();
	virtual void Function103();
	virtual void Function104();
public:
	virtual bool canAttack(Actor*, bool);
	virtual void setTarget(Actor*);
private:
	virtual void Function107();
	virtual void Function108();
public:
	virtual void attack(Actor*);
	virtual void performRangedAttack(Actor&, float);
private:
	virtual void Function111();
public:
	virtual int getEquipmentCount(void);
	virtual void setOwner(__int64 ActorUniqueID);
	virtual void setSitting(bool);
private:
	virtual void Function115();
	virtual void Function116();
public:
	virtual __int64 getInventorySize(void);
	virtual __int64 getEquipSlots(void);
	virtual __int64 getChestSlots(void);
	virtual void setStanding(bool);
	virtual bool canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
private:
	virtual void Function125();
	virtual void Function126();
public:
	virtual bool shouldRender(void);
	virtual bool isInvulnerableTo(class ActorDamageSource const&);
	virtual class DamageCause getBlockDamageCause(class Block const&);
public:
	virtual void actuallyHurt(int, class ActorDamageSource const&, bool);
	virtual void animateHurt(void);
	virtual void doFireHurt(int);
	virtual void onLightningHit(void);
private:
	virtual void Function134();
public:
	virtual void feed(int);
	virtual void handleEntityEvent(class ActorEvent, int);
	virtual float getPickRadius(void);
	virtual __int64 getActorRendererId(void);
	virtual void spawnAtLocation(class ItemStack const&, float);
	virtual void spawnAtLocation(class Block const&, int, float);
	virtual void spawnAtLocation(class Block const&, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(int, int);
	virtual void despawn(void);
	virtual void killed(Actor&);
private:
	virtual void Function146();
public:
	virtual void setArmor(int ArmorSlot, ItemStack const&);
	virtual class ItemStack getArmor(int ArmorSlot);
	virtual int /*enum ArmorType*/ getArmorMaterialTypeInSlot(int ArmorSlot);
	virtual int /*enum ArmorTextureType*/ getArmorMaterialTextureTypeInSlot(int ArmorSlot);
	virtual void getArmorColorInSlot(int ArmorSlot, int);
	virtual class ItemStack getEquippedSlot(int EquipmentSlot);
	virtual void setEquippedSlot(int EquipmentSlot, class ItemStack const&);
	virtual class ItemStack* getCarriedItem(void);
	virtual void setCarriedItem(ItemStack const&);
	virtual void setOffhandSlot(ItemStack const&);
	virtual class ItemStack* getEquippedTotem(void);
	virtual void consumeTotem(void);
	virtual void save(class CompoundTag&);
	virtual void saveWithoutId(class CompoundTag&);
	virtual void load(class CompoundTag const&, class DataLoadHelper&);
private:
	virtual void Function162();
public:
	virtual __int64 getEntityTypeId(void);
private:
	virtual void Function164();
public:
	virtual __int64 getSourceUniqueID(void);
	virtual void setOnFire(int);
	virtual void extinguishFire(void);
	virtual void thawFreezeEffect(void);
	virtual struct AABB getHandleWaterAABB(void);
	virtual void handleInsidePortal(Vec3i const&);
	virtual __int64 getPortalCooldown(void);
private:
	virtual void Function172();
public:
	virtual class AutomaticID getDimensionId(void);
private:
	virtual void Function174();
	virtual void Function175();
public:
	virtual void changeDimension(class AutomaticID);
	virtual __int64 _getSourceUniqueID(void);
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float, float, class ActorDamageSource);
	virtual void handleFallDistanceOnServer(float, float, bool);
private:
	virtual void Function181();
	virtual void Function182();
	virtual void Function183();
public:
	virtual bool canAddRider(Actor&);
private:
	virtual void Function185();
	virtual void Function186();
	virtual void Function187();
	virtual void Function188();
public:
	virtual void tickLeash(void);
	virtual void sendMotionPacketIfNeeded(void);
private:
	virtual void Function191();
public:
	virtual void stopRiding(bool, bool, bool);
	virtual void startSwimming(void);
	virtual void stopSwimming(void);
private:
	virtual void Function195();
public:
	virtual int getCommandPermissionLevel(void);
private:
	virtual void Function197();
	virtual void Function198();
	virtual void Function199();
public:
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
	virtual bool canBeAffected(class MobEffectInstance const&);
	virtual bool canBeAffected(int);
	virtual bool canBeAffectedByArrow(class MobEffectInstance const&);
	virtual bool onEffectAdded(class MobEffectInstance&);
	virtual bool onEffectUpdated(class MobEffectInstance const&);
	virtual bool onEffectRemoved(class MobEffectInstance&);
	virtual __int64 getAnimationComponent(void);
	virtual void openContainerComponent(class Player&);
	virtual void swing(void);
public:
	virtual void useItem(class ItemStackBase&, class ItemUseMethod, bool);
private:
	virtual void Function212();
	virtual void Function213();
	virtual void Function214();
public:
	virtual float getMapDecorationRotation(void);
	virtual float getRiderYRotation(Actor const&);
public:
	virtual float getYHeadRot(void);
	virtual bool isWorldBuilder(void);
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
public:
	virtual void add(class ItemStack&);
	virtual void drop(class ItemStack const&, bool);
	virtual __int64 getInteraction(class Player&, class ActorInteraction&, Vec3 const&);
private:
	virtual void Function225();
	virtual void Function226();
public:
	virtual void setSize(float, float);
	virtual __int64 getLifeSpan(void);
private:
	virtual void onOrphan(void);
public:
	virtual void wobble();
	virtual bool wasHurt(void);
	virtual void startSpinAttack(void);
private:
	virtual void Function233();
public:
	virtual void setDamageNearbyMobs(bool);
private:
	virtual void Function235();
public:
	virtual void reloadLootTable(class EquipmentTableDefinition const&);
	virtual void reloadLootTable(void);
private:
	virtual void Function238();
public:
	virtual void kill(void);
	virtual void die(ActorDamageSource const&);
	virtual bool shouldTick(void);
	virtual void createMovementProxy(void);
	virtual float getNextStep(float);
private:
	virtual void Function244();
public:
	virtual bool shouldTryMakeStepSound(void);
private:
	virtual void Function246();
public:
	virtual bool outOfWorld(void);
	virtual void _hurt(class ActorDamageSource const&, int, bool, bool);
	virtual void markHurt(void);
private:
	virtual void Function250();
	virtual void Function251();
public:
	virtual void _playStepSound(Vec3i const&, Block const&);
	virtual void _playFlySound(Vec3i const&, Block const&);
private:
	virtual void Function254();
public:
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vec3 const&);
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
	virtual void updateInsideBlock(void);
	virtual __int64 getLootTable(void);
private:
	virtual void Function262();
public:
	virtual void _removeRider(__int64 ActorUniqueID, bool, bool, bool);
private:
	virtual void onSizeUpdated(void);
	virtual void Function265();
public:
	__int64 getActorId() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 82 ? ? ? ? 48 39 01 75 03 B0 01 C3") + 3);
		uintptr_t addr = (uintptr_t)(this) + offset;
		return *reinterpret_cast<__int64*>(addr);
	}

	AABB* getAABB() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("F3 0F 11 81 ? ? ? ? F3 0F 10 42 ? F3 0F 58 81 ? ? ? ? F3 0F 11 81 ? ? ? ? F3 0F 10 42") + 4);
		return reinterpret_cast<AABB*>((uintptr_t)(this) + offset);
	}

	Vec2* collision() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("0F 2E BB ? ? ? ? 75 0D 0F 2E B3 ? ? ? ?") + 3);
		return reinterpret_cast<Vec2*>((uintptr_t)(this) + offset);
	}

	class PlayerInventory* getSupplies() {
		static unsigned int offset = 0;
		if (offset == NULL) {
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 8B ? ? ? ? 8B 47 ? 8B") + 3);
		}
		return *reinterpret_cast<class PlayerInventory**>((uintptr_t)(this) + offset);
	}
	class BlockSource* getRegionConst() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 97 ? ? ? ? 48 8B ? ? E8 ? ? ? ? 90") + 3);
		return *reinterpret_cast<class BlockSource**>((uintptr_t)(this) + offset);
	}

	class Level* getMultiPlayerLevel() {
		return *reinterpret_cast<class Level**>((uintptr_t)(this) + 0x358);
	}

	void _updateOwnerChunk() {
		using UpdateOwnerChunk = void(__thiscall*)(Actor*);
		static UpdateOwnerChunk _UpdateOwnerChunk = reinterpret_cast<UpdateOwnerChunk>(Utils::FindSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B D9 48 8B 89 ? ? ? ? 48 85 C9"));
		_UpdateOwnerChunk(this);
	}
};