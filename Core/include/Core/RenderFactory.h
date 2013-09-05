#pragma once

class SKYENGINE_CORE_API RenderFactory{
public:
	RenderFactory();
	virtual ~RenderFactory();
	RenderEngine& RenderEngineInstance();
	static RenderFactoryPtr NullObject(); 

private:
	virtual RenderEnginePtr DoMakeRenderEngine() = 0;

protected:
	RenderEnginePtr re_;

};