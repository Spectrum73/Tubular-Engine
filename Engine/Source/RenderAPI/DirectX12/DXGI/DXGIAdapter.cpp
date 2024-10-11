#include "Engine.h"
#include "DXGIAdapter.h"

DXGIAdapter::DXGIAdapter(IDXGIAdapter* pAdapter) : Microsoft::WRL::ComPtr<IDXGIAdapter>(pAdapter)
{

}
