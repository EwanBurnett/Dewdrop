#ifndef __DEWDROP_DX11_SWAPCHAIN_H
#define __DEWDROP_DX11_SWAPCHAIN_H

#include "DX11_Common.h"
#include "DX11_Context.h"
#include "../../../include/Dewdrop/Graphics/Swapchain.h"

namespace Dewdrop {
    class DX11_Swapchain : public Swapchain {
    public: 
        DDResult Create(Context* context, const Window* pWindow) override; 
        DDResult Destroy() override; 
        DDResult Clear(Context* context) override; 
        DDResult Present(Context* context) override; 

    private:
        Microsoft::WRL::ComPtr<IDXGISwapChain> m_pSwapchain; 
    private:
        HRESULT CreateSwapchain(WindowHandle hWnd, DX11_Context* pContext); 
    };
}

#endif