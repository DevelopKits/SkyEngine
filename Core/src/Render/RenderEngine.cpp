//RenderEngine.cpp
#include "Core/SkyEngine.h"
#include <string>
#include "Core/RenderEngine.h"
#include "Core/CoreUtil.h"

class NullRenderEngine : public RenderEngine
{
public:
	void DoCreateRenderWindow( std::string const & name, RenderSettings const & settings ){
		UNUSED(name);
		UNUSED(settings);
	}
};

RenderEngine::RenderEngine()
{

}

RenderEngine::~RenderEngine(){

}

RenderEnginePtr RenderEngine::NullObject(){
	static RenderEnginePtr obj = MakeSharedPtr<NullRenderEngine>();
	return obj;
}

void RenderEngine::CreateRenderWindow( std::string const & name, RenderSettings const & settings ){
	render_settnigs_ = settings;
	this->DoCreateRenderWindow( name, settings );
}