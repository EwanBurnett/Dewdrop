#include <Dewdrop/Dewdrop.h>
#include <Dewdrop/Version.h>
#include <glfw/glfw3.h> 
#include <imgui.h>
#include <cstdio>
#include <Dewdrop/Maths.h>
#include <Dewdrop/Logging.h>

int main() {
    Dewdrop::Init(); 
    
    glfwInit();

    char title[256];
    sprintf(title, "Dewdrop-DEV v%d.%d.%d.%d", Dewdrop::DEWDROP_VERSION_MAJOR, Dewdrop::DEWDROP_VERSION_MINOR, Dewdrop::DEWDROP_VERSION_PATCH, Dewdrop::DEWDROP_VERSION_BUILD);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, title, nullptr, nullptr);
    
    Log::Message("Hello, World!");
    Math::Matrix4x4 m;
    Math::Matrix4x4 m2;
    auto res = Math::Matrix4x4::MMult_M4x4_M4x4(m, m2);
   

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); 
    }

    glfwDestroyWindow(window);
}