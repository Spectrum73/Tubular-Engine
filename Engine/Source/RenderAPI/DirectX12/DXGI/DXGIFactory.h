#pragma once
#include <wrl.h>

#include "DXGIAdapter.h"

class DXGIFactory : public Microsoft::WRL::ComPtr<IDXGIFactory>
{

public:
	DXGIFactory();

	DXGIAdapter GetAdapter();
};