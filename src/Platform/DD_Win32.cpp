/*
*   Win32 Platform Layer
*/
#include "Dewdrop/Platform.h"
#include <cstdio> 
#include <glfw/glfw3.h> 

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


bool Platform::PollEvents() {
    glfwPollEvents(); 
    return true;
}
