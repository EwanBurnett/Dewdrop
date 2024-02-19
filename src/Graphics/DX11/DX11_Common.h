#ifndef __DEWDROP_DX11_COMMON_H
#define __DEWDROP_DX11_COMMON_H

#include <windows.h>
#include <d3d11.h>
#include <wrl/client.h>

#include <utility>
#include <cstdio> //TODO: Logger class

namespace Dewdrop {
    inline constexpr HRESULT CheckHResult(HRESULT hr, const char* fmt, ...) {
        if (FAILED(hr)) {
            va_list args = {};
            va_start(args, fmt); 
            vprintf(fmt, args);
            va_end(args);
        }

        return hr;
    }
}

#endif