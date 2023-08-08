#include <Dewdrop/Dewdrop.h>
#include <Dewdrop/Version.h>
#include <glfw/glfw3.h> 
#include <imgui.h>
#include <cstdio>

int main() {
    Dewdrop::Init(); 

    glfwInit();

    char title[256];
    sprintf(title, "Dewdrop-DEV v%d.%d.%d.%d", Dewdrop::DEWDROP_VERSION_MAJOR, Dewdrop::DEWDROP_VERSION_MINOR, Dewdrop::DEWDROP_VERSION_PATCH, Dewdrop::DEWDROP_VERSION_BUILD);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, title, nullptr, nullptr);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); 
    }

    glfwDestroyWindow(window);
}