#pragma once
#include <wrl.h>

class DXGIAdapter : public Microsoft::WRL::ComPtr<IDXGIAdapter>
{
public:
	DXGIAdapter() = default;

	DXGIAdapter(IDXGIAdapter* pAdapter);


};