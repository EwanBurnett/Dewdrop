/*
*   Win32 Platform Layer
*/
#include "Dewdrop/Platform.h"
#include "Dewdrop/Window.h"
#include <cstdio> 
#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw/glfw3.h> 
#include <GLFW/glfw3native.h>

#if DEWDROP_WIN32
//Windows-specific functionality can be enabled through this macro. 
#endif

using namespace Dewdrop;

DDResult Platform::Init() {
    printf("[Win32]\t Init()\n");

    //Initialize GLFW
    if (glfwInit() != GLFW_TRUE) {
        return DD_FAILED;
    }

    return DD_SUCCESS;
}


DDResult Platform::Shutdown() {
    printf("[Win32]\t Shutdown()\n");
    //Shutdown GLFW. 
    glfwTerminate();
    return DD_SUCCESS;
}


bool Platform::PollEvents(Window* pWindow) {
    glfwPollEvents();

    return !glfwWindowShouldClose(reinterpret_cast<GLFWwindow*>(pWindow->GetHandle()));
}


#pragma push_macro("CreateWindow")
#undef CreateWindow 

DDResult Platform::CreateWindow(WindowHandle& window, uint16_t width, uint16_t height, const char* title, const Window* pWindow) {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* wnd = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwSetWindowUserPointer(wnd, (void*)(pWindow));

    window = reinterpret_cast<WindowHandle>(wnd);
    if (!window) {
        return DD_FAILED;
    }

    return DD_SUCCESS;
}

#pragma pop_macro("CreateWindow")
DDResult Platform::DestroyWindow(WindowHandle& window) {
    glfwDestroyWindow(reinterpret_cast<GLFWwindow*>(window));
    return DD_SUCCESS;
}

WindowHandle Dewdrop::Platform::GetNativeWindowHandle(const WindowHandle& window)
{
    return reinterpret_cast<WindowHandle>(glfwGetWin32Window(reinterpret_cast<GLFWwindow*>(window)));
}

