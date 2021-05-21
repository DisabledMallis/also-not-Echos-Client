#pragma once
#include "../Hook.h"

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

class SwapChain_Hook : public Hook {
public:
	void init();
};