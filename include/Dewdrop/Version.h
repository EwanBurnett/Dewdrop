#include <cstdint> 
#include <string> 

namespace Dewdrop {
    constexpr uint32_t DEWDROP_VERSION_MAJOR = 0;
    constexpr uint32_t DEWDROP_VERSION_MINOR = 0;
    constexpr uint32_t DEWDROP_VERSION_PATCH = 1;
    constexpr uint32_t DEWDROP_VERSION_BUILD = 8;

    std::string GetVersionString(); 
}
