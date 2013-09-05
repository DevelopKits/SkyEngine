#include "Core/SkyEngine.h"
#include "Core/App3D.h"
#include "Core/Context.h"
#include "Core/RenderFactory.h"
#include "Core/RenderEngine.h"
#include "Core/CoreUtil.h"
#include "Core/Window.h"

App3DFramework::App3DFramework( std::string name )
	:name_(name)
{
	Context::Instance().AppInstance( *this );

	ContextCfg cfg = Context::Instance().Config();
	main_wnd_ = this->MakeWindow( name, cfg.graphics_cfg );

}

App3DFramework::~App3DFramework(){
	this->Destroy();

	main_wnd_.reset();
}

void App3DFramework::Destroy(){
	this->DelObjects();
}

void App3DFramework::Create(){
	ContextCfg const & cfg = Context::Instance().Config();
	Context::Instance().RenderFactoryInstance().RenderEngineInstance().CreateRenderWindow( name_, cfg.graphics_cfg );
}

void App3DFramework::Run(){
	static bool b = true;
	while( b ){
		Sleep( 1000 );
	}
}

WindowPtr App3DFramework::MakeWindow( std::string const & name, RenderSettings const & settings ){
	return MakeSharedPtr<Window>( name, settings );
}