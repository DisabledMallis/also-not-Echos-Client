#pragma once
#include <string>
#include "../Math/Math.h"

#include <d3d11.h>
#include <d2d1_1.h>
#include <dwrite_1.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dwrite.lib")

class Renderer {
public:
	ID3D11DeviceContext* pContext = nullptr;

	ID2D1RenderTarget* d2dRenderTarget;
	
	ID2D1Factory* factory;
	IDXGISurface* dxgiBackbuffer;
	IDWriteFactory1* writeFactory;

	IDWriteTextFormat* textFormat;
	ID2D1SolidColorBrush* brush;

	void init(IDXGISwapChain*, ID3D11Device*, ID3D11DeviceContext*);
	void drawString(std::wstring, float, Vec2, _RGBA);
};