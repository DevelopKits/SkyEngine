#include "Core/SkyEngine.h"
#include "Core/RenderFactory.h"
#include "Core/RenderEngine.h"
#include "Core/CoreUtil.h"

class NullRenderFactory : public RenderFactory{
	RenderEnginePtr DoMakeRenderEngine(){
		return RenderEngine::NullObject();
	}
};

RenderFactory::RenderFactory()
	:re_(0)
{
}

RenderFactory::~RenderFactory(){
	if( re_ ) re_.reset();
}

RenderFactoryPtr RenderFactory::NullObject(){
	static RenderFactoryPtr obj = MakeSharedPtr<NullRenderFactory>();		
	return obj;
}

RenderEngine& RenderFactory::RenderEngineInstance(){
	if( !re_ ){
		re_ = this->DoMakeRenderEngine();
	}
	return *re_;
}