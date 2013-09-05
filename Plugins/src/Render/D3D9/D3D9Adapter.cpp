#include "Core/SkyEngine.h"
#include <algorithm>
#include "Plugin/D3D9/D3D9Adapter.h"

D3D9Adapter::D3D9Adapter()
	:adapter_no_(0)
{

}

D3D9Adapter::D3D9Adapter( uint32_t adapter_no, IDirect3D9* direct_3d )
	:adapter_no_( adapter_no ), direct_3d_( direct_3d )
{

}

void D3D9Adapter::Enumerate(){
	std::vector<D3DFORMAT> adapter_formats;
	adapter_formats.push_back( D3DFMT_A8R8G8B8 );
	adapter_formats.push_back( D3DFMT_X8R8G8B8 );

	for( size_t i = 0; i<adapter_formats.size(); ++i ){
		UINT num_adapter_modes = direct_3d_->GetAdapterModeCount( adapter_no_, adapter_formats[i] );
		for( UINT mode_no = 0; mode_no < num_adapter_modes; ++mode_no ){
			D3DDISPLAYMODE mode;
			direct_3d_->EnumAdapterModes( adapter_no_, adapter_formats[i], mode_no, &mode );
			D3D9VideoMode video_mode( mode.Width, mode.Height, mode.Format );
			modes_.push_back( video_mode );
		}
	}

	std::sort( modes_.begin(), modes_.end() );
}