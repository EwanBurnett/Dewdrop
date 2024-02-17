#ifndef __DEWDROP_DX11_CONTEXT_H
#define __DEWDROP_DX11_CONTEXT_H

#include "DX11_Common.h"
#include "../../../include/Dewdrop/Graphics/Context.h"
#include <cstdio>

namespace Dewdrop {
    class DX11_Context : public Context {
    public:
        DDResult Init() override;
        DDResult Shutdown() override;
    private:
        Microsoft::WRL::ComPtr<ID3D11Device> m_pDevice; 
        Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pContext; 

        HRESULT CreateDeviceAndContext(D3D_FEATURE_LEVEL& featureLevel); 
    };
}
#endif