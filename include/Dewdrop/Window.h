#ifndef __DEWDROP_WINDOW_H
#define __DEWDROP_WINDOW_H

#include "../include/Dewdrop/Types.h"
#include "../include/Dewdrop/Platform.h"

namespace Dewdrop {
    class Window {
    public: 
        DDResult Create(uint16_t width, uint16_t height, const char* title);
        DDResult Destroy(); 
    private:
        WindowHandle m_Window; 

        uint16_t m_Width; 
        uint16_t m_Height; 
        const char* m_Title; 
    };
}

#endif
