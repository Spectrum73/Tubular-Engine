#include "Engine.h"
#include "D12Device.h"

D12Device::D12Device(IDXGIAdapter* pAdapter)
{
}

void D12Device::Init(IDXGIAdapter* pAdapter)
{
	ENGINE_EVALUATE_HR(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&ptr_)), "Error creating D12 device.\n");
}
