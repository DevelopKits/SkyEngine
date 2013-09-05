//FF RenderEngine ( only D3D9 by now )

#pragma once

#include "RenderSettings.h"

class SKYENGINE_CORE_API RenderEngine{
public:
	RenderEngine();
	virtual ~RenderEngine();
	
	static RenderEnginePtr NullObject();

	void CreateRenderWindow( std::string const & name, RenderSettings const & settings );

private:
	virtual void DoCreateRenderWindow( std::string const & name, RenderSettings const & settings ) = 0;

private:
	RenderSettings render_settnigs_;
};
