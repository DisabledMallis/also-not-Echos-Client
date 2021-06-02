#pragma once

class Packet {
public:
	uintptr_t** VTable; //0x0000
	template <class T>
	bool instanceOf() {
		T packet;
		return (packet.VTable == this->VTable);
	}
};

class MovePlayerPacket : public Packet {
private:
	char pad_0008[32];        //0x0008
public:
	__int64 runtimeId;        //0x0028
	Vec3 pos = Vec3(0, 0, 0); //0x0030
	Vec2 rot = Vec2(0, 0);    //0x003C
	float headYaw;            //0x0044

	MovePlayerPacket() {
		this->VTable = GetVTable();
	}

	MovePlayerPacket(__int64 runtimeId, Vec3 pos = Vec3(0, 0, 0), Vec2 bodyRot = Vec2(0, 0), float headYaw = 0) {
		this->VTable = GetVTable();
		this->runtimeId = runtimeId;
		this->pos = pos;
		this->rot = bodyRot;
		this->headYaw = headYaw;
	}

	uintptr_t** GetVTable() {
		static uintptr_t** vtable = nullptr;
		if (vtable == nullptr) {
			auto sig = Utils::FindSig("48 8D 05 ? ? ? ? 48 89 01 48 8B 82 ? ? ? ? 48 89 41 ? 48 8B 02 48 8B CA");
			int offset = *reinterpret_cast<int*>(sig + 3);
			vtable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
		}
		return vtable;
	}
};

class PlayerAuthInputPacket : public Packet {
public:
	PlayerAuthInputPacket() {
		this->VTable = GetVTable();
	}

	uintptr_t** GetVTable() {
		static uintptr_t** vtable = nullptr;
		if (vtable == nullptr) {
			auto sig = Utils::FindSig("48 8D 05 ? ? ? ? 48 89 01 F2 0F 10 42 ? F2 0F 11 41 30");
			int offset = *reinterpret_cast<int*>(sig + 3);
			vtable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
		}
		return vtable;
	}
};