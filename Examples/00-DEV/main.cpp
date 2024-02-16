#include <Dewdrop/Dewdrop.h>
#include <cstdio>

int main() {
    Dewdrop::Init(); 

    //Run for a couple of frames, to simulate work. 
    uint64_t frameIdx = 0; 
    while (frameIdx < 50000) {
        Dewdrop::Platform::PollEvents();
        printf("\rFrame %d", ++frameIdx);
    }

    printf("\n");
    Dewdrop::Platform::Shutdown(); 
}