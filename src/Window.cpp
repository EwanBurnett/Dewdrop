#include "../include/Dewdrop/Window.h"
#include "../include/Dewdrop/Platform.h"

using namespace Dewdrop;

DDResult Window::Create(uint16_t width, uint16_t height, const char* title)
{
    return Platform::CreateWindow(m_Window, width, height, title);
}

DDResult Window::Destroy()
{
    return Platform::DestroyWindow(m_Window);
}
