#include <Dewdrop/Dewdrop.h>
#include <Dewdrop/Window.h>
#include <cstdio>

int main() {
    Dewdrop::Init(); 

    Dewdrop::Window wnd; 
    wnd.Create(800, 560, "Hello!");

    //Run for a couple of frames, to simulate work. 
    uint64_t frameIdx = 0; 
    while (frameIdx < 50000) {
        Dewdrop::Platform::PollEvents();
        printf("\rFrame %d", ++frameIdx);
    }

    printf("\n");
    wnd.Destroy(); 
    Dewdrop::Platform::Shutdown(); 
}