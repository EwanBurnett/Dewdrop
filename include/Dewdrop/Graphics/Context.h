#ifndef __DEWDROP_CONTEXT_H
#define __DEWDROP_CONTEXT_H

#include "../Types.h"

namespace Dewdrop {
    class Context {
    public: 
        virtual DDResult Init() = 0;
        virtual DDResult Shutdown() = 0;
    };
}
#endif