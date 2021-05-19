#pragma once
#include <functional>

class Inventory {
private:
	virtual ~Inventory();
public:
	virtual void init(void);
private:
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
public:
	virtual class ItemStack* getItem(int);
	virtual bool hasRoomForItem(class ItemStack const&);
	virtual void addItem(class ItemStack&);
	virtual void addItemToFirstEmptySlot(class ItemStack&);
	virtual void setItem(int, class ItemStack const&);
	virtual void setItemWithForceBalance(int, class ItemStack const&, bool);
	virtual void removeItem(int, int);
	virtual void removeAllItems(void);
	virtual void dropContents(class BlockSource&, Vec3 const&, bool);
	virtual __int64 getContainerSize(void);
	virtual __int64 getMaxStackSize(void);
private:
	virtual void Function15();
	virtual void Function16();
public:
	virtual std::vector<class ItemStack*> getSlotCopies(void);
	virtual std::vector<class ItemStack*> getSlots(void);
	virtual int getItemCount(class ItemStack* const&);
	virtual int findFirstSlotForItem(class ItemStack const&);
private:
	virtual void Function21();
	virtual void Function22();
public:
	virtual void setContainerChanged(int);
	virtual void setContainerMoved(void);
	virtual void setCustomName(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual bool hasCustomName(void);
private:
	virtual void Function27();
	virtual void Function28();
public:
	virtual void createTransactionContext(std::function<void(class Inventory&, int, class ItemStack const&, class ItemStack const&)>, std::function<void(void)>);
private:
	virtual void Function30();
public:
	virtual bool isEmpty(void);
	virtual void add(class ItemStack&);
	virtual bool canAdd(class ItemStack const&);
	virtual void clearSlot(int);
	virtual void clearInventory(int);
private:
	virtual void Function36();
public:
	virtual int getEmptySlotsCount(void);
};

class PlayerInventory {
public:
	class Inventory* inventory() {
		static unsigned int offset = 0;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 89 ? ? ? ? 44 0F B6 4C 24 ? 48 8B 01 48 FF 60 ?") + 3);
		return *reinterpret_cast<Inventory**>((uintptr_t)(this) + offset);
	}
};