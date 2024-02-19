#ifndef __DEWDROP_SWAPCHAIN_H
#define __DEWDROP_SWAPCHAIN_H

#include "../Types.h"
#include "../Window.h"
#include "Context.h"

namespace Dewdrop {
    class Swapchain {
    public:
        virtual DDResult Create(Context* context, const Window* pWindow) = 0;
        virtual DDResult Destroy() = 0; 

        virtual DDResult Clear(Context* context) = 0; 
        virtual DDResult Present(Context* context) = 0; 
    protected:
        uint16_t m_Width; 
        uint16_t m_Height; 
     };
}
#endif