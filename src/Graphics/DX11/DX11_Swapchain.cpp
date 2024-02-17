#include "DX11_Swapchain.h"

using namespace Dewdrop;

DDResult DX11_Swapchain::Create(Context* context, const Window* pWindow) {

    printf("[DX11]\tCreating Swapchain.\n");
    if (FAILED(CreateSwapchain(pWindow->GetHandle()))) {
        printf("[DX11]\tError: Failed to create Swapchain!\n");
    }

    return DD_SUCCESS;
}

DDResult DX11_Swapchain::Destroy() {
    return DD_SUCCESS;
}

HRESULT DX11_Swapchain::CreateSwapchain(WindowHandle hWnd) {
    DXGI_MODE_DESC bd = { };
    {
        bd.Width = m_Width; //TODO: Vector2 Resolution member
        bd.Height = m_Height;
        bd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        bd.RefreshRate.Numerator = 60;
        bd.RefreshRate.Denominator = 1;
        bd.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        bd.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    }

    DXGI_SWAP_CHAIN_DESC sd = { };
    {
        sd.BufferDesc = bd;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.BufferCount = 1;
        sd.OutputWindow = reinterpret_cast<HWND>(hWnd);
        sd.Windowed = true;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        sd.Flags = 0;

        sd.SampleDesc.Count = 1;

        sd.SampleDesc.Quality = 0;
    }

    return E_NOTIMPL;
}