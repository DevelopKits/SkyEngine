#include "Core/SkyEngine.h"
#include "Plugin/D3D9/D3D9FrameBuffer.h"
#include "Plugin/D3D9/D3D9RenderEngine.h"
#include "Core/Context.h"
#include "Core/RenderFactory.h"
#include "Core/CoreUtil.h"

void D3D9FrameBuffer::Clear( uint32_t flags, Color color, float depth, int32_t stencil ){
	D3D9RenderEngine const & re = *check_cast<D3D9RenderEngine const*>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
	IDirect3DDevice9* const device = re.Device();

	DWORD d3d_flag = 0;
	if( flags & CBM_Color ){
		d3d_flag |= D3DCLEAR_TARGET;
	}
	if( flags & CBM_Depth ){
		d3d_flag |= D3DCLEAR_ZBUFFER;
	}
	if( flags & CBM_Stencil ){
		d3d_flag |= D3DCLEAR_STENCIL;
	}

	device->Clear( 0, 0, d3d_flag, color.ARGB(), depth, stencil );
	return ;
}