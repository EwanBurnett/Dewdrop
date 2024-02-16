#include "../include/Dewdrop/Renderer.h"
#include "../include/Dewdrop/Window.h"
#include <cstdio>

using namespace Dewdrop;

DDResult Renderer::Init(const Window* pWindow)
{
    pWindow->GetHandle();
    return DD_SUCCESS;
}

DDResult Renderer::Shutdown()
{
    return DD_SUCCESS;
}

void Dewdrop::Renderer::BeginFrame()
{
    printf("\rFrame %d", ++frameIdx);
}

void Dewdrop::Renderer::EndFrame()
{
}

void Dewdrop::Renderer::Draw()
{
}
