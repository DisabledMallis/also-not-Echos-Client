#include "SwapChain.h"
#include "../../../Client/Client.h"
#include "../../../Utils/Renderer.h"

typedef HRESULT(__fastcall* D3D11PresentHook) (IDXGISwapChain* pChain, UINT syncInterval, UINT flags);
D3D11PresentHook oPresent = nullptr;

IDXGISwapChain* pSwapChain = nullptr;
ID3D11Device* pDevice = nullptr;
ID3D11DeviceContext* pContext = nullptr;
ID3D11RenderTargetView* renderTargetView = nullptr;

Client* rClient;
bool init = false;

Renderer* renderer = new Renderer();

#include <d3d11.h>
#include <d2d1_1.h>
#include <dwrite_1.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dwrite.lib")

HRESULT __fastcall callback(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) {
    if (!init) {
        pSwapChain = pChain;

        if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(pDevice), reinterpret_cast<void**>(&pDevice)))) {
            pSwapChain->GetDevice(__uuidof(pDevice), reinterpret_cast<void**>(&pDevice));
            pDevice->GetImmediateContext(&pContext);
        }

        init = true;
    };

    renderer->init(pChain, pDevice, pContext); /* Initialize Data */

    renderer->beginDraw(); /* Begin Frame */

    for (auto C : rClient->categories) {
        for (auto M : C->modules) M->onRender(renderer); /* Let onRender handle renderer method calls*/
    }

    renderer->endDraw(); /* End Frame */

    renderer->releaseTarget(); /* Release Target Texture */

    return oPresent(pChain, syncInterval, flags);
}

void SwapChain_Hook::init() {
    rClient = client;
    WNDCLASSEX wc{};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = DefWindowProc;
    wc.lpszClassName = TEXT("TemporaryWindow");
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindow(wc.lpszClassName, TEXT(""), WS_DISABLED, 0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr);

    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
    DXGI_SWAP_CHAIN_DESC sd;
    {
        memset((&sd), 0, (sizeof(sd)));
        sd.BufferCount = 1;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        sd.OutputWindow = hWnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    }

    HRESULT hrD3D11CreateDeviceAndSwapChain = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr,
        0, &featureLevel, 1, D3D11_SDK_VERSION, &sd,
        &pSwapChain, &pDevice, nullptr, &pContext);

    if (FAILED(hrD3D11CreateDeviceAndSwapChain)) {
        DestroyWindow(sd.OutputWindow);
        UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
        return;
    }

    uintptr_t** pSwapChainVTable = *reinterpret_cast<uintptr_t***>(pSwapChain);

    Utils::DebugLogF("Preparing to hook SwapChain Present");

    if (MH_CreateHook((void*)pSwapChainVTable[8], &callback, reinterpret_cast<LPVOID*>(&oPresent)) == MH_OK) {
        MH_EnableHook((void*)pSwapChainVTable[8]);
        Utils::DebugLogF("Successfully completed SwapChain Present Hook!");
    }
    else {
        Utils::DebugLogF("Failed to create SwapChain Present Hook :/");
    }

    pDevice->Release();
    pContext->Release();
    pSwapChain->Release();

    DestroyWindow(sd.OutputWindow);
    UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
}