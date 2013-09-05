#include "Core/SkyEngine.h"
#include "Core/RenderSettings.h"
#include "Core/Context.h"
#include "Core/RenderFactory.h"
#include "Core/CoreUtil.h"
#include "Plugin/D3D9/D3D9RenderWindow.h"
#include "Plugin/D3D9/D3D9RenderEngine.h"

D3D9RenderWindow::D3D9RenderWindow( RenderSettings const & settings ){
	D3D9RenderEngine re = *check_cast<D3D9RenderEnginePtr>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
	if( re.Device() ){
	}
	else{

	}
}
