#ifndef __DEWDROP_TYPES_H
#define __DEWDROP_TYPES_H

#include <cstdint> 

namespace Dewdrop {
    enum DDResult {
        DD_FAILED = 0, 
        DD_SUCCESS = 1,
    };

    typedef uint64_t WindowHandle; 
}
#endif