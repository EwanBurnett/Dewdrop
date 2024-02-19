#include "../include/Dewdrop/Window.h"
#include "../include/Dewdrop/Platform.h"

using namespace Dewdrop;


DDResult Window::Create(uint16_t width, uint16_t height, const char* title)
{
    m_Width = width;
    m_Height = height; 
    return Platform::CreateWindow(m_Window, width, height, title, this);
}

DDResult Window::Destroy()
{
    return Platform::DestroyWindow(m_Window);
}

const uint16_t Dewdrop::Window::GetWidth() const
{
    return m_Width;
}

const uint16_t Dewdrop::Window::GetHeight() const
{
    return m_Height;
}


WindowHandle Window::GetHandle() const
{
    return m_Window;
}

