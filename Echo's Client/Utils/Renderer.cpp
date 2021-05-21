#include "Renderer.h"

void Renderer::init(IDXGISwapChain* pChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext) {

    static bool once = false;

    if (!once) {
        D2D1_FACTORY_OPTIONS options;
        options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
        D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, options, &factory);
    }

    pChain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackbuffer));

    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED));
    factory->CreateDxgiSurfaceRenderTarget(dxgiBackbuffer, props, &d2dRenderTarget);
    dxgiBackbuffer->Release();

    if (!once) {
        DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(writeFactory), (IUnknown**)(&writeFactory));
    }

    if(!once) once = true;
}

void Renderer::drawString(std::wstring t, float size, Vec2 pos, _RGBA rgb) {
   const wchar_t* text = t.c_str();

   writeFactory->CreateTextFormat(L"Arial", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, size, L"", &textFormat);
   d2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(rgb.r, rgb.b, rgb.g, rgb.a), &brush);
   
   d2dRenderTarget->BeginDraw();

   brush->SetColor(D2D1::ColorF(rgb.r, rgb.g, rgb.b, rgb.a));
   d2dRenderTarget->DrawText(text, wcslen(text), textFormat, D2D1::RectF(pos.x, pos.y, pos.x + (pos.x * size), pos.y + (pos.y * size)), brush);

   d2dRenderTarget->EndDraw();
}