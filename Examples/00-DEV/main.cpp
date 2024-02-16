#include <Dewdrop/Dewdrop.h>
#include <Dewdrop/Window.h>
#include <Dewdrop/Renderer.h>
#include <cstdio>

int main() {
    Dewdrop::Init(); 

    Dewdrop::Window wnd; 
    wnd.Create(800, 560, "Hello!");

    Dewdrop::Renderer renderer; 
    renderer.Init(&wnd); 

    //Run for a couple of frames, to simulate work. 
    while (Dewdrop::Platform::PollEvents(&wnd)) {
        renderer.BeginFrame(); 

        //Eventually, we'll be traversing a scene graph. 
        renderer.Draw(); 

        renderer.EndFrame(); 
    }

    printf("\n");
    renderer.Shutdown(); 
    wnd.Destroy(); 
    Dewdrop::Platform::Shutdown(); 
}