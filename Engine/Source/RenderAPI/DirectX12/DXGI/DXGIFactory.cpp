#include "Engine.h"
#include "DXGIFactory.h"

DXGIFactory::DXGIFactory()
{
	// Factory made with IID macro using the com pointer
	ENGINE_EVALUATE_HR(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&ptr_)), "Failed to create DXGI Factory.");
}

DXGIAdapter DXGIFactory::GetAdapter()
{
	Microsoft::WRL::ComPtr<IDXGIFactory6> fac6;
	Microsoft::WRL::ComPtr<IDXGIAdapter> adapter;

	// Query for the factory 6 interface
	if (Get()->QueryInterface(IID_PPV_ARGS(&fac6)) == S_OK)
	{
		ENGINE_EVALUATE_HR(fac6->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter)), "Error finding the adapter.");
	}
	else
	{
		ENGINE_ASSERT(false);
	}

	return DXGIAdapter(adapter.Get());
}
