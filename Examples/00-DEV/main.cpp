#include <Dewdrop/Dewdrop.h>
#include <Dewdrop/Window.h>
#include <Dewdrop/Renderer.h>
#include <Dewdrop/Timer.h>
#include <cstdio>

int main() {
    Dewdrop::Init();

    Dewdrop::Window wnd;
    wnd.Create(400, 300, "Hello!");

    Dewdrop::Renderer renderer;
    renderer.Init(&wnd);

    Dewdrop::Timer t;
    t.Start(); 

    double dtms = 0.0; 
    uint64_t fps = 0; 

    //Run for a couple of frames, to simulate work. 
    while (Dewdrop::Platform::PollEvents(&wnd)) {
        printf("\rdtms: %02.6f\t\t%05d fps", dtms, fps);

        t.Tick();
        dtms = t.DeltaTime();
        fps = 1.0 / dtms; 

        renderer.BeginFrame();

        //Eventually, we'll be traversing a scene graph. 
        renderer.Draw();

        renderer.EndFrame();
    }

    t.Reset(); 

    printf("\n");
    renderer.Shutdown();
    wnd.Destroy();
    Dewdrop::Platform::Shutdown();
}