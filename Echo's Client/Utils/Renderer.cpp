#include "Renderer.h"

void Renderer::init(ID3D11Device* pDevice, ID3D11DeviceContext* pContext) {
    FW1CreateFactory(FW1_VERSION, &this->pFW1Factory);
    pFW1Factory->CreateFontWrapper(pDevice, L"Bahnschrift", &this->pFontWrapper);
    this->pFW1Factory->Release();
    this->pContext = pContext;
}

void Renderer::drawString(std::wstring t, float size, Vec2 pos, UINT32 colour) {
   const wchar_t* text = t.c_str();
    pFontWrapper->DrawString(pContext, text, size, pos.x, pos.y, colour, FW1_RESTORESTATE);
}