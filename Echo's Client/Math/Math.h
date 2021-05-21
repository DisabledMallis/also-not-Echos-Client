#pragma once
#include <Windows.h>

class Math {
public:
	//
};

struct Vec2 {
	union {
		struct {
			float x, y;
		};
		float arr[2];
	};

	Vec2() { x = y = 0; };
	
	Vec2(float x = 0, float y = 0) {
		this->x = x; this->y = y;
	};

	bool operator == (Vec2 v) { return v.x == x && v.y == y; };
	bool operator != (Vec2 v) { return v.x != x || v.y != y; };
};

struct Vec3 {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};

	Vec3() { x = y = z = 0; };

	Vec3(float x = 0, float y = 0, float z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vec3 v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vec3 v) { return v.x != x || v.y != y || v.z != z; };
};

struct Vec3i {
	union {
		struct {
			int x, y, z;
		};
		int arr[3];
	};

	Vec3i() { x = y = z = 0; };

	Vec3i(int x = 0, int y = 0, int z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vec3i v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vec3i v) { return v.x != x || v.y != y || v.z != z; };
};

struct AABB {
	Vec3 lower;
	Vec3 upper;
};

class _RGBA {
public:
	float r;
	float g;
	float b;
	float a;
	_RGBA(float r, float g, float b, float a = 1) {
		this->r = r; this->g = b; this->b = b; this->a = a;
	}
};

class RGBA_FW1 {
public:
	float r;
	float g;
	float b;
	float a;

	RGBA_FW1(float r, float g, float b, float a = 1) {
		//this->r = r; this->g = b; this->b = b; this->a = a;
		this->b = r;
		this->g = g;
		this->r = b;
	}
	UINT32 toUint32() {
		UINT32 _r = 255 * r;
		UINT32 _b = 255 * b;
		UINT32 _g = 255 * g;

		return 0xFF000000 | _r | (_b << 16) | (_g << 8);
	}
};