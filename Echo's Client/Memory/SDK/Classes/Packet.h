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
	char pad_0008[40];  //0x0008
public:
	uint64_t runtimeId; //0x0030
	Vec3 pos;           //0x0038
	Vec2 rot;           //0x0044
	float headYaw;      //0x004C
	char pad_0050[60];  //0x0050

	MovePlayerPacket() {
		memset(this, 0, sizeof(this));
		this->VTable = GetVTable();
	}

	MovePlayerPacket(__int64 runtimeId, Vec3 pos, Vec2 bodyRot, float headYaw = 0) {
		memset(this, 0, sizeof(this));
		this->VTable = GetVTable();
		this->runtimeId = runtimeId;
		this->pos = pos;
		this->rot = bodyRot;
		this->headYaw = headYaw ? headYaw : bodyRot.y;
	}

	uintptr_t** GetVTable() {
		static uintptr_t** vtable = nullptr;
		if (vtable == nullptr) { //
			auto sig = Utils::FindSig("48 8D 05 ? ? ? ? 48 89 01 48 89 51 ? 48 83 C1 ? 49 8B D0 E8 ? ? ? ? 89");
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
			auto sig = Utils::FindSig("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 48 81 C1 ? ? ? ? E8 ? ? ? ? 48 8B BB ? ? ? ? 48 85 FF ");
			int offset = *reinterpret_cast<int*>(sig + 3);
			vtable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
		}
		return vtable;
	}
};