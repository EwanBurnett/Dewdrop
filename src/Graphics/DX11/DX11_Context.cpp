#include "DX11_Context.h"

using namespace Dewdrop;

DDResult DX11_Context::Init() {
    printf("[DX11]\tCreating Context for DirectX 11.\n");

    printf("[DX11]\tCreating DX11 Device and Context.\n");
    D3D_FEATURE_LEVEL featureLevel = {}; 
    if (FAILED(CreateDeviceAndContext(featureLevel))) {
        printf("[DX11]\tERROR: Failed to create Device and Context!\n");
    }

    return DD_SUCCESS;
}

DDResult DX11_Context::Shutdown() {
    printf("[DX11]\tDestroying Context.\n");
    return DD_SUCCESS;
}

HRESULT Dewdrop::DX11_Context::CreateDeviceAndContext(D3D_FEATURE_LEVEL& featureLevel)
{
    int flags = 0;
#ifdef _DEBUG
    flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
    };

    return D3D11CreateDevice(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        0,
        flags,
        featureLevels,
        ARRAYSIZE(featureLevels),
        D3D11_SDK_VERSION,
        m_pDevice.ReleaseAndGetAddressOf(),
        &featureLevel,
        m_pContext.ReleaseAndGetAddressOf()
    );
}

