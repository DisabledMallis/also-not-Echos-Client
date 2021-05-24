#pragma once
#include "Actor.h"

class Player : public Actor {
public:
	virtual void knockback(Actor*, int, float, float, float, float, float);
	virtual void resolveDeathLoot(int, class ActorDamageSource const&);
private:
	virtual void Function268();
public:
	virtual void setSleeping(bool);
	virtual void setSprinting(bool);
	virtual void playAmbientSound(void);
	virtual __int64 getAmbientSound(void);
	virtual __int64 getAmbientSoundPostponeTicks(void);
	virtual __int64 getAmbientSoundPostponeTicksRange(void);
	virtual __int64 getItemInHandIcon(class ItemStack const&, int);
	virtual float getSpeed(void);
	virtual void setSpeed(float);
	virtual float getJumpPower(void);
	virtual __int64 hurtEffects(class ActorDamageSource const&, int, bool, bool);
	virtual __int64 getMeleeWeaponDamageBonus(Actor*);
	virtual __int64 getMeleeKnockbackBonus(void);
	virtual void travel(class IMobMovementProxy&, float, float, float);
	virtual void travel(float, float, float);
	virtual void applyFinalFriction(float, bool);
	virtual void updateWalkAnim(void);
	virtual void aiStep(class IMobMovementProxy&);
	virtual void aiStep(void);
	virtual void pushActors(void);
	virtual void lookAt(class Actor*, float, float);
	virtual bool isLookingAtAnEntity(void);
	virtual __int64 checkSpawnRules(bool);
	virtual __int64 checkSpawnObstruction(void);
	virtual float getAttackAnim(float);
	virtual __int64 getItemUseDuration(void);
	virtual float getItemUseStartupProgress(void);
	virtual float getItemUseIntervalProgress(void);
	virtual __int64 getItemuseIntervalAxis(void);
	virtual float getTimeAlongSwing(void);
private:
	virtual void Function299();
public:
	virtual float getMaxHeadXRot(void);
	virtual Actor* getLastHurtByMob(void);
	virtual void setLastHurtByMob(Actor*);
	virtual class Player* getLastHurtByPlayer(void);
	virtual void setLastHurtByPlayer(class Player*);
	virtual Actor* getLastHurtMob(void);
	virtual void setLastHurtMob(Actor*);
private:
	virtual void Function307();
public:
	virtual void doHurtTarget(Actor*);
private:
	virtual void Function309();
public:
	virtual void leaveCaravan(void);
	virtual void joinCaravan(Actor*);
	virtual bool hasCaravanTail(void);
	virtual __int64 getCaravanHead(void);
	virtual int getArmorValue(void);
	virtual __int64 getArmorCoverPercentage(void);
private:
	virtual void Function316();
public:
	virtual void hurtArmor(class ActorDamageSource const&, int);
	virtual void hurtArmorSlot(class ActorDamageSource const&, int, int ArmorSlot);
	virtual void setDamagedArmor(int ArmorSlot, class ItemStack const&);
private:
	virtual void Function320();
	virtual void Function321();
public:
	virtual bool containerChanged(int);
	virtual void updateEquipment(void);
	virtual void clearEquipment(void);
	virtual std::vector<class ItemStack*> getAllArmor(void);
	virtual __int64 getAllArmorID(void);
	virtual __int64 getAllHand(void);
	virtual std::vector<class Item*> getAllEquipment(void);
	virtual __int64 getArmorTypeHash(void);
	virtual void dropEquipmentOnDeath(void);
	virtual void dropEquipmentOnDeath(class ActorDamageSource const&, int);
private:
	virtual void Function342();
	virtual void Function343();
public:
	virtual __int64 getDamageAfterMagicAbsorb(ActorDamageSource const&, int);
	virtual void createAIGoals(void);
private:
	virtual void Function346();
public:
	virtual void setItemSlot(class EquipmentSlot, ItemStack const&);
	virtual void setTransitioningSitting(bool);
	virtual void attackAnimation(Actor*, float);
	virtual __int64 getTickDelay(void);
private:
	virtual void Function351();
	virtual void Function352();
	virtual void Function353();
public:
	virtual void ascendLadder(void);
	virtual void ascendScaffolding(void);
	virtual void ascendScaffoldingA(void);
	virtual void descendScaffolding(void);
	virtual bool canAscendCurrentBlockByJumping(void);
	virtual void dropContainer(void);
	virtual __int64 initBodyControl(void);
	virtual void jumpFromGround(class IMobMovementProxy&);
	virtual void jumpFromGround(void);
private:
	virtual void Function363();
	virtual void Function364();
	virtual void Function365();
	virtual void Function366();
	virtual void Function367();
public:
	virtual void dropBags(void);
	virtual void tickDeath(void);
	virtual void updateGliding(void);
private:
	virtual void Function371();
public:
	virtual void prepareRegion(class ChunkSource&);
	virtual void destroyRegion(void);
	virtual void suspendRegion(void);
private:
	virtual void Function375();
public:
	virtual void _fireWillChangeDimension(void);
	virtual void _fireDimensionChanged(void);
private:
	virtual void Function378();
public:
	virtual void tickWorld(__int64);
private:
	virtual void Function380();
	virtual void Function381();
public:
	virtual void moveView(void);
private:
	virtual void Function383();
	virtual void Function384();
	virtual void Function385();
	virtual void Function386();
public:
	virtual void respawn(void);
private:
	virtual void Function388();
public:
	virtual void resetPos(bool);
private:
	virtual void Function390();
public:
	virtual bool hasResource(int);
	virtual void completeUsingItem(void);
	virtual void setPermissions(int CommandPermissionLevel);
	virtual void startDestroy(void);
	virtual void stopDestroy(void);
private:
	virtual void Function396();
	virtual void Function397();
	virtual void Function398();
public:
	virtual bool canOpenContainerScreen(void);
private:
	virtual void Function400();
	virtual void Function401();
	virtual void Function402();
	virtual void Function403();
	virtual void Function404();
	virtual void Function405();
	virtual void Function406();
	virtual void Function407();
public:
	virtual void startSleepInBed(Vec3i const&);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed(void);
	virtual __int64 getSleepTimer(void);
	virtual __int64 getPreviousTickSleepTimer(void);
private:
	virtual void Function413();
	virtual void Function414();
	virtual void Function415();
	virtual void Function416();
	virtual void Function417();
	virtual void Function418();
public:
	virtual void registerTrackedBoss(int ActorUniqueID);
	virtual void unRegisterTrackedBoss(int ActorUniqueID);
	virtual void setPlayerGameType(int GameType);
	virtual void initHUDContainerManager(void);
	virtual void _crit(Actor&);
	virtual __int64 getEventing(void);
private:
	virtual void Function425();
public:
	virtual void sendEventPacket(class EventPacket&);
	virtual void addExperience(int);
	virtual void addLevels(int);
private:
	virtual void Function429();
	virtual void Function430();
public:
	virtual void inventoryChanged(class Container&, int, class ItemStack const&, class ItemStack const&, bool);
private:
	virtual void Function432();
public:
	virtual void deleteContainerManager(void);
	virtual void setFieldOfViewModifier(float);
private:
	virtual void Function435();
	virtual void Function436();
	virtual void Function437();
	virtual void Function438();
	virtual void Function439();
public:
	virtual void startCooldown(class Item*);
private:
	virtual void Function441();
	virtual void Function442();
	virtual void Function443();
	virtual void Function444();
	virtual void Function445();
	virtual void Function446();
	virtual void Function447();
	virtual void Function448();
	virtual void Function449();
	virtual void Function450();
public:
	virtual void onMovePlayerPacketNormal(Vec3 const&, Vec2 const&, float);
};