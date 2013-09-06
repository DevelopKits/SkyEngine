#include "Core/SkyEngine.h"
#include "Core/App3D.h"
#include "Core/Context.h"

class TestApp : public App3DFramework
{
public:
	TestApp( std::string name );
	void InitObjects();
	void DelObjects();
};

TestApp::TestApp( std::string name )
	:App3DFramework( name )
{
	
}

void TestApp::InitObjects(){

}

void TestApp::DelObjects(){
	
}

int main(){
	Context::Instance().LoadCfg("KlayGE.cfg");
	TestApp test("Hello Baby!");
	test.Create();
	test.Run();

	return 0;
}
