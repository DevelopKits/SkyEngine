#include "Core/SkyEngine.h"
#include <d3d9.h>
#include "Plugin/D3D9/D3D9RenderEngine.h"
#include "Core/CoreUtil.h"
#include "Plugin/D3D9/D3D9PreDeclare.h"

D3D9RenderEngine::D3D9RenderEngine(){
	mod_dxd9_ = ::LoadLibraryW(L"D3D9.dll");
	DynamicD3D9Create_ = reinterpret_cast<DynamicCreateD3D9Func>(::GetProcAddress( mod_dxd9_, "Direct3DCreate9" ));
	direct_3d_ = DynamicD3D9Create_( D3D_SDK_VERSION );

	adapterList_.Enumerate( direct_3d_ );
}

D3D9RenderEngine::~D3D9RenderEngine(){
	::FreeLibrary( mod_dxd9_ );
}

IDirect3DDevice9* D3D9RenderEngine::Device() const{
	return d3d_device_;
}

void D3D9RenderEngine::DoCreateRenderWindow( std::string const & name, RenderSettings const & settings ){
	UNUSED( name );

	D3D9RenderWindowPtr win = MakeSharedPtr<D3D9RenderWindow>( settings );
	UNUSED(win);
}