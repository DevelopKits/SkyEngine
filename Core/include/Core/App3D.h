#pragma once

#include <string>
#include "Core/RenderSettings.h"

class SKYENGINE_CORE_API App3DFramework
{
public:
	App3DFramework( std::string name );
	virtual ~App3DFramework();

	virtual void InitObjects() = 0;
	virtual void DelObjects() = 0;
	void Create();
	void Run();

	std::string const & Name() const {
		return name_;
	}

	WindowPtr const MainWnd() const {
		return main_wnd_;
	}

	void Destroy();

	WindowPtr MakeWindow( std::string const & name, RenderSettings const & settings );

private:
	std::string name_;
	WindowPtr main_wnd_;
};