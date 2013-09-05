#include "Core/SkyEngine.h"
#include "Plugin/D3D9/D3D9RenderFactory.h"
#include "Plugin/D3D9/D3D9RenderEngine.h"
#include "Core/CoreUtil.h"

D3D9RenderFactory::~D3D9RenderFactory(){

}

RenderEnginePtr D3D9RenderFactory::DoMakeRenderEngine(){
	return MakeSharedPtr< D3D9RenderEngine >();
}

void MakeRenderFactory( RenderFactoryPtr & ptr ){
	ptr = MakeSharedPtr< D3D9RenderFactory >();
}