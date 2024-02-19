#ifndef __DEWDROP_PLATFORM_H
#define __DEWDROP_PLATFORM_H
/*
*   Platform-Independent abstraction layer
*   Enables different systems to perform these arbitrary tasks differently.
*   --------------------------
*   Author: Ewan Burnett (EwanBurnettSK@Outlook.com)
*   Last Modified: 2024-02-16
*/

#include "Types.h"

namespace Dewdrop {
    
    class Window; 
    namespace Platform {
        /**
         * @brief Performs Platform-specific Initialisation code
         * @return DD_SUCCESS upon successful initialisation, or DD_FAILED otherwise.
        */
        DDResult Init();

        /**
         * @brief Performs Platform-specific Destruction code
         * @return DD_SUCCESS upon successful shutdown, or DD_FAILED otherwise.
        */
        DDResult Shutdown();


        bool PollEvents(Window* pWindow);

        //Undefine the CreateWindow macro (possibly implemented by Windows!!!), so we can use it as our function name. 
#pragma push_macro("CreateWindow")
#undef CreateWindow 
        DDResult CreateWindow(WindowHandle& window, uint16_t width, uint16_t height, const char* title, const Window* pWnd);
#pragma pop_macro("CreateWindow")

        DDResult DestroyWindow(WindowHandle& window);

        WindowHandle GetNativeWindowHandle(const WindowHandle& window); 
    }
}

#endif