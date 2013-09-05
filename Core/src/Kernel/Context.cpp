#include "Core/SkyEngine.h"
#include "Core/Context.h"
#include "Core/RenderFactory.h"
#include "Core/ResLoader.h"
#include "Core/Log.h"
#include "Core/XMLDom.h"

typedef void (*MakeRenderFactoryFunc)(RenderFactoryPtr& ptr);

Context::Context():render_factory_(0){
	SKY_MUTEX_INIT( &single_mutex_ );

	render_factory_ = RenderFactory::NullObject();
	dll_suffix_ = "d.dll";
}

Context::~Context(){
	SKY_MUTEX_DESTROY( &single_mutex_ );
	render_factory_.reset();
}

Context& Context::Instance(){
	static Context context;
	return context;
}

void Context::LoadCfg( std::string const & cfg_file ){
	int width = 800;
	int height = 600;

	std::string rf_name = "D3D9";

	XMLDocument cfg_doc;
	XMLNodePtr rf_node;

	ResIdentifierPtr file = ResLoader::Instance().Open( cfg_file );
	if ( file ){
		XMLNodePtr cfg_root = cfg_doc.Parse( file );
		XMLNodePtr context_node = cfg_root->FirstNode( "context" );
		XMLNodePtr graphics_node = cfg_root->FirstNode( "graphics" );
		
		rf_node = context_node->FirstNode("render_factory");
		if( rf_node ){
			rf_name = rf_node->Attrib("name")->ValueString();
		}
		
		XMLNodePtr frame_node = graphics_node->FirstNode( "frame" );
		width = frame_node->Attrib( "width" )->ValueInt();
		height = frame_node->Attrib( "height" )->ValueInt();

		ResLoader::Instance().Close( file );
	}

	cfg_.render_factory_name = rf_name;
	cfg_.graphics_cfg.width = width;
	cfg_.graphics_cfg.height = height;
}

void Context::SaveCfg( std::string const & cfg_file ){
	(void)cfg_file;
}

void Context::Config( ContextCfg const & cfg ){
	cfg_ = cfg;
}

ContextCfg const & Context::Config() const{
	return cfg_;
}

void Context::LoadRenderFactory(std::string const & rf_name){
	render_factory_ = RenderFactory::NullObject();
	render_loader_.Free();

	std::string render_path = ResLoader::Instance().Locate("Render");
	std::string fn = SKYENGINE_STRINGIZE(SKYENGINE_NAME) + std::string("_RenderEngine_")+rf_name+"_"+dll_suffix_;
	std::string path = render_path + "/" + fn;

	render_loader_.Load( path );

	MakeRenderFactoryFunc mrf = (MakeRenderFactoryFunc)render_loader_.GetProcAddress("MakeRenderFactory");
	if( mrf ){
		mrf( render_factory_ );
	}
	else{
		LogInfo( "Loading %s failed", path.c_str() );
		render_loader_.Free();
	}
}

RenderFactory& Context::RenderFactoryInstance(){
	if( render_factory_ == RenderFactory::NullObject() ){
		SKY_MUTEX_LOCK( &single_mutex_ );
		if( render_factory_ == RenderFactory::NullObject() ){
			this->LoadRenderFactory( cfg_.render_factory_name );
		}
		SKY_MUTEX_UNLOCK( &single_mutex_ );
	}
	return *render_factory_;
}