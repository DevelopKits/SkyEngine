#pragma once
#include "Core/SkyEngine.h"
#include "Core/Mutex.h"
#include "Core/DllLoader.h"
#include "Core/RenderSettings.h"

struct ContextCfg{
	std::string render_factory_name;
	RenderSettings graphics_cfg;
};

class SKYENGINE_CORE_API Context{
public:
	~Context();
	static Context& Instance();

	void LoadCfg( std::string const & cfg_file );
	void SaveCfg( std::string const & cfg_file );
	void Config( ContextCfg const & cfg );
	ContextCfg const & Config() const;

	RenderFactory& RenderFactoryInstance();
	void LoadRenderFactory(std::string const & rf_name);

	void AppInstance( App3DFramework& app ){
		app_ = &app;
	}

	App3DFramework& AppInstance() const {
		return *app_;
	}

private:
	Context();
	SKY_MUTEX single_mutex_;

	ContextCfg cfg_;
	RenderFactoryPtr render_factory_;

	DllLoader	render_loader_;

	std::string dll_suffix_;

	App3DFrameworkPtr app_;

};