#pragma once
#include "Core/RenderFactory.h"

class D3D9RenderFactory : public RenderFactory
{
public:
	virtual ~D3D9RenderFactory();

private:
	RenderEnginePtr DoMakeRenderEngine();
};

#define SKYENGINE_D3D9_API __declspec(dllexport)

extern "C"
{
	SKYENGINE_D3D9_API void MakeRenderFactory( RenderFactoryPtr & ptr );
}