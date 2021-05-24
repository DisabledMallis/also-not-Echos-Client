#pragma once

class ItemStack {
private:
	uintptr_t** VTable;
public:
	class Item** item;

	int getId() {
		using GetId = int(__thiscall*)(ItemStack*);
		static GetId _GetId = reinterpret_cast<GetId>(Utils::FindSig("80 79 23 00 75 06 B8 ? ? ? ? C3"));
		return _GetId(this);
	}

	int getMaxStackSize() {
		using GetMaxStackSize = int(__thiscall*)(ItemStack*);
		static GetMaxStackSize _GetMaxStackSize = reinterpret_cast<GetMaxStackSize>(Utils::FindSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 70 33 FF 89 BC 24 ? ? ? ? 48 8B 41 08 48 85 C0"));
		return _GetMaxStackSize(this);
	}

	class Item* getItem() {
		using GetItem = Item * (__thiscall*)(ItemStack*);
		static GetItem _GetItem = reinterpret_cast<GetItem>(Utils::FindSig("48 8B 41 08 48 85 C0 74 04 48 8B 00 C3"));
		return _GetItem(this);
	}
};

class Item {
private:
	virtual ~Item();
	virtual void Function0();
	virtual void Function1();
public:
	virtual __int64 getMaxUseDuration(class ItemInstance const*);
private:
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
public:
	virtual bool isCamera(void);
	virtual bool isDamageable(void);
private:
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
public:
	virtual bool isFood(void);
private:
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
public:
	virtual struct IFoodComponent getFood(void);
private:
	virtual void Function21();
public:
	virtual void setMaxStackSize(unsigned char);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped(void);
	virtual void setUseAnimation(class UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual void setRequiresWorldBuilder(bool);
	virtual void setExplodable(bool);
	virtual void setFireResistant(bool);
	virtual void setIsGlint(bool);
	virtual void setShouldDespawn(bool);
private:
	virtual void Function33();
public:
	virtual bool canBeDepleted(void);
private:
	virtual void Function35();
	virtual void Function36();
public:
	virtual bool isStackedByData(void);
	virtual int getMaxDamage(void);
private:
	virtual void Function39();
public:
	virtual bool isHandEquipped(void);
private:
	virtual void Function41();
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
	virtual void Function52();
	virtual void Function53();
	virtual void Function54();
	virtual void Function55();
	virtual void Function56();
	virtual void Function57();
public:
	virtual __int64 getDamageChance(int);
private:
	virtual void Function59();
	virtual void Function60();
	virtual void Function61();
	virtual void Function62();
	virtual void Function63();
	virtual void Function64();
	virtual void Function65();
	virtual void Function66();
	virtual void Function67();
	virtual void Function68();
	virtual void Function69();
	virtual void Function70();
	virtual void Function71();
	virtual void Function72();
	virtual void Function73();
public:
	virtual void use(class ItemStack&, class Player&);
	virtual void dispense(class BlockSource&, class Container&, int, Vec3 const&, unsigned char);
	virtual void useTimeDepleted(class ItemStack&, class Level*, class Player*);
	virtual void releaseUsing(class ItemStack&, class Player*, int);
private:
	virtual void Function78();
public:
	virtual void hurtActor(ItemStack&, class Actor&, class Actor&);
private:
	virtual void Function80();
	virtual void Function81();
public:
	virtual void mineBlock(class ItemInstance&, class Block const&, int, int, int, class Actor*);
private:
	virtual void Function83();
	virtual void Function84();
	virtual void Function85();
	virtual void Function86();
public:
	virtual void buildCategoryDescriptionName(void);
private:
	virtual void Function88();
	virtual void Function89();
public:
	virtual __int8 getMaxStackSize(class ItemDescriptor const&);
private:
	virtual void Function91();
	virtual void Function92();
	virtual void Function93();
public:
	virtual __int64 getCooldownTime(void);
	virtual void fixupCommon(class ItemStackBase&, class Level&);
	virtual void fixupCommon(class ItemStackBase&);
	virtual __int64 getDamageValue(class CompoundTag const*);
	virtual void setDamageValue(class ItemStackBase&, short);
private:
	virtual void Function99();
	virtual void Function100();
	virtual void Function101();
public:
	virtual bool isSameItem(class ItemStackBase const&, class ItemStackBase const&);
private:
	virtual void Function103();
	virtual void Function104();
	virtual void Function105();
public:
	virtual bool isEmissive(int);
	virtual __int64 getLightEmission(int);
	virtual __int64 getIcon(class ItemStackBase const&, int, bool);
private:
	virtual void Function109();
public:
	virtual void setIcon(class TextureUVCoordinateSet const&);
private:
	virtual void Function111();
	virtual void Function112();
	virtual void Function113();
	virtual void Function114();
	virtual void Function115();
public:
	virtual float getFurnaceBurnIntervalMultipler(class ItemStackBase const&);
	virtual float getFurnaceXPmultiplier(class ItemStackBase const&);
private:
	virtual void Function118();
	virtual void Function119();
	virtual void Function120();
public:
	virtual void _useOn(ItemStack&, class Actor&, Vec3i, unsigned char, float, float, float);
public:
	int16_t itemId() {
		return *reinterpret_cast<int16_t*>((uintptr_t)(this) + 0x92);
	}
};