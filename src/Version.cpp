#include "../include/Dewdrop/Version.h"

#if _DEBUG
const char* g_VersionName = "[Debug] Dewdrop";
#else
const char* g_VersionName = "Dewdrop";
#endif

std::string Dewdrop::GetVersionString() {
    char buffer[256];
    sprintf(buffer, "%s v%d.%d.%d.%d",
        g_VersionName,
        Dewdrop::DEWDROP_VERSION_MAJOR, 
        Dewdrop::DEWDROP_VERSION_MINOR, 
        Dewdrop::DEWDROP_VERSION_PATCH, 
        Dewdrop::DEWDROP_VERSION_BUILD 
    );


    return std::string(buffer);

}
