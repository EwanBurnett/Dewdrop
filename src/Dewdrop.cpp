#include "../include/Dewdrop/Dewdrop.h"
#include "../include/Dewdrop/Version.h"
#include "../include/Dewdrop/Platform.h"
#include <cstdio>

void Dewdrop::Init() {
    printf("Initialising %s\n", GetVersionString().c_str());
    
    //Initialize platform-specific code 
    Dewdrop::Platform::Init(); 
}

void Dewdrop::Shutdown()
{
    printf("Shutting Down...\n");

    Dewdrop::Platform::Shutdown(); 
}
