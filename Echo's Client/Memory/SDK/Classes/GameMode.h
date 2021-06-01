#pragma once

class GameMode {
private:
	virtual void Constructor(void);
public:
	virtual void startDestroyBlock(Vec3i const&, UCHAR, bool&);
	virtual void destroyBlock(Vec3i const&, UCHAR);
	virtual void continueDestroyBlock(Vec3i const&, UCHAR, Vec3 const&, bool&);
	virtual void stopDestroyBlock(Vec3i const&);
	virtual void startBuildBlock(Vec3i const&, UCHAR);
	virtual void buildBlock(Vec3i const&, UCHAR);
	virtual void continueBuildBlock(Vec3i const&, UCHAR);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual float getPickRange(__int64 const&, bool);
	virtual void useItem(class ItemStack&);
	virtual void useItemOn(class ItemStack&, Vec3i const&, UCHAR, Vec3 const&, class Block const*);
	virtual void interact(Actor&, Vec3 const&);
	virtual void attack(Actor*);
	virtual void releaseUsingItem(void);
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode(void);
	virtual void registerUpsellScreenCallback(void);

public:

	Player* player;
};