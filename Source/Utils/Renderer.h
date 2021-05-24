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
private:
	ID3D11DeviceContext* pContext = nullptr;

	ID2D1RenderTarget* d2dRenderTarget;
	
	ID2D1Factory* factory;
	IDXGISurface* dxgiBackbuffer;
	IDWriteFactory1* writeFactory;

	IDWriteTextFormat* textFormat;
	ID2D1SolidColorBrush* brush;
public:
	void init(IDXGISwapChain*, ID3D11Device*, ID3D11DeviceContext*);
	void releaseTarget();
	void beginDraw();
	void endDraw();
	void drawString(std::wstring text, float size, Vec2 pos, _RGBA rgb);
	void drawRectangle(Vec2 start, Vec2 end, _RGBA rgb, float lineWidth = 1.0f);
	void fillRectangle(Vec2 start, Vec2 end, _RGBA rgb);
};