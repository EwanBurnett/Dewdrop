#include "../include/Dewdrop/Renderer.h"
#include "../include/Dewdrop/Window.h"
#include <cstdio>

#include "Graphics/DX11/DX11_Context.h"
#include "Graphics/DX11/DX11_Swapchain.h"

using namespace Dewdrop;

DDResult Renderer::Init(const Window* pWindow)
{
    //TODO: Select Rendering API through an Enum
    m_pContext = new DX11_Context; 
    m_pContext->Init(); 

    m_pSwapchain = new DX11_Swapchain;
    m_pSwapchain->Create(m_pContext, pWindow);

    return DD_SUCCESS;
}

DDResult Renderer::Shutdown()
{
    m_pSwapchain->Destroy(); 
    m_pContext->Shutdown();

    delete m_pSwapchain; 
    delete m_pContext; 

    return DD_SUCCESS;
}

void Dewdrop::Renderer::BeginFrame()
{
    m_pSwapchain->Clear(m_pContext); 
    //printf("\rFrame %d", ++frameIdx);
}

void Dewdrop::Renderer::EndFrame()
{
    m_pSwapchain->Present(m_pContext); 
}

void Dewdrop::Renderer::Draw()
{
}
