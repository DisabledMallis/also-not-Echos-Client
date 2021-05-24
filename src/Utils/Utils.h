#pragma once
#include <Windows.h>
#include <Psapi.h>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

#define PI 3.14159265359

class Utils {
public:
	static uintptr_t FindMultiLvlPtr(uintptr_t, std::vector<unsigned int>);
	static uintptr_t FindSig(const char*);
	static void DebugLogF(const char*, const char* fPath = "", bool deleteIfFirstLaunch = false);
};

