#pragma once
#include <string>
#include "../Math/Math.h"
#include <FW1FontWrapper.h>

class Renderer {
public:
	IFW1Factory* pFW1Factory = nullptr;
	IFW1FontWrapper* pFontWrapper = nullptr;

	ID3D11DeviceContext* pContext = nullptr;

	void init(ID3D11Device*, ID3D11DeviceContext*);
	void drawString(std::wstring, float, Vec2, UINT32);
};