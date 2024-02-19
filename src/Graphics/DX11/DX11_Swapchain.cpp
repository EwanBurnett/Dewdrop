#include "DX11_Swapchain.h"
#include "../../../include/Dewdrop/Platform.h"

using namespace Dewdrop;

DDResult DX11_Swapchain::Create(Context* context, const Window* pWindow) {
    m_Width = pWindow->GetWidth();
    m_Height = pWindow->GetHeight();

    DX11_Context* pContext = static_cast<DX11_Context*>(context);

    WindowHandle hWnd = Platform::GetNativeWindowHandle(pWindow->GetHandle());

    printf("[DX11]\tCreating Swapchain.\n");
    if (FAILED(CreateSwapchain(hWnd, pContext))) {
        printf("[DX11]\tError: Failed to create Swapchain!\n");
        return DD_FAILED;
    }

    return DD_SUCCESS;
}

DDResult DX11_Swapchain::Destroy() {
    return DD_SUCCESS;
}

DDResult Dewdrop::DX11_Swapchain::Clear(Context* context)
{
    return DDResult();
}

DDResult Dewdrop::DX11_Swapchain::Present(Context* context)
{
    HRESULT hr = CheckHResult(m_pSwapchain->Present(0, 0), "Failed to Present Swapchain!\n");
    return DD_SUCCESS;
}

HRESULT DX11_Swapchain::CreateSwapchain(WindowHandle hWnd, DX11_Context* pContext) {
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
        sd.BufferCount = 2;
        sd.OutputWindow = reinterpret_cast<HWND>(hWnd);
        sd.Windowed = true;
        sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;  //NOTE: see https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/for-best-performance--use-dxgi-flip-model
        sd.Flags = 0;
        sd.SampleDesc.Count = 1;    //TODO: Load from MSAA Settings 
        sd.SampleDesc.Quality = 0;
    }

    HRESULT hr = {};

    IDXGIDevice* dxgiDevice = 0;
    hr = CheckHResult(pContext->m_pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice), "[Error]\tFailed to retrieve DXGI Device Interface!\n");

    IDXGIAdapter* dxgiAdapter = 0;
    hr = CheckHResult(dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter), "");

    IDXGIFactory* dxgiFactory = 0;
    hr = CheckHResult(dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory), "");

    hr = CheckHResult(dxgiFactory->CreateSwapChain(dxgiDevice, &sd, m_pSwapchain.ReleaseAndGetAddressOf()), "");

    dxgiFactory->Release();
    dxgiAdapter->Release();
    dxgiDevice->Release();

    return hr;
}