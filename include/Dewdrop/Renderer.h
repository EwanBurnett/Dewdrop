#ifndef __DEWDROP_RENDERER_H
#define __DEWDROP_RENDERER_H

#include "Types.h"

namespace Dewdrop {
    class Window;
    class Renderer {
    public:
        DDResult Init(const Window* pWindow);
        DDResult Shutdown();

        void BeginFrame();
        void EndFrame();

        void Draw();
    private:
        uint64_t frameIdx = 0;
    };
}
#endif