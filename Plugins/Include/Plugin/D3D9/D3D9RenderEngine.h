#pragma once
#include <d3d9.h>
#include "Core/RenderEngine.h"
#include "Plugin/D3D9/D3D9AdapterList.h"

class D3D9RenderEngine : public RenderEngine
{
public:
	D3D9RenderEngine();
	virtual ~D3D9RenderEngine();
	IDirect3DDevice9* Device() const;

private:
	void DoCreateRenderWindow( std::string const & name, RenderSettings const & settings );
	HMODULE mod_dxd9_;	

	typedef IDirect3D9 * (WINAPI *DynamicCreateD3D9Func)(UINT SDKVersion);

	DynamicCreateD3D9Func DynamicD3D9Create_;

	IDirect3D9* direct_3d_;
	IDirect3DDevice9* d3d_device_;

	D3D9AdapterList adapterList_;
};
