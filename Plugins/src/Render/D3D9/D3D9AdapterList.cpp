#include "Core/SkyEngine.h"
#include "Core/CoreUtil.h"
#include "Plugin/D3D9/D3D9AdapterList.h"
#include "Plugin/D3D9/D3D9Adapter.h"


D3D9AdapterList::D3D9AdapterList(){

}

D3D9AdapterList::~D3D9AdapterList(){
	for( size_t i = 0; i < adapters_.size(); ++i ){
		adapters_[i].reset();
	}
}

void D3D9AdapterList::Enumerate( IDirect3D9* device ){
	adapters_.clear();

	std::vector<D3DFORMAT> adapter_format_available;
	adapter_format_available.push_back( D3DFMT_X8R8G8B8 );
	adapter_format_available.push_back( D3DFMT_X1R5G5B5 );
	adapter_format_available.push_back( D3DFMT_R5G6B5 );
	adapter_format_available.push_back( D3DFMT_A2R10G10B10 );

	UINT num_adapter = device->GetAdapterCount();

	for( UINT adapter_no = 0; adapter_no < num_adapter; ++adapter_no ){
		D3D9AdapterPtr adapter = MakeSharedPtr<D3D9Adapter>( adapter_no, device );
		adapter->Enumerate();
		adapters_.push_back( adapter );
	}
}