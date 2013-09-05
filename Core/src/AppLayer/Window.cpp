#include "Core/SkyEngine.h"
#include "Core/Window.h"
#include "Core/CoreUtil.h"

Window::Window( std::string const & name, RenderSettings const & settings ){
	HINSTANCE hInstance = ::GetModuleHandle( 0 );
	name_ = name;

	WNDCLASSEXW wc;
	std::wstring wname;
	Convert( wname, name );

	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = 0;
	wc.hCursor = 0;
	wc.hbrBackground = static_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
	wc.lpszMenuName = 0;
	wc.lpszClassName = wname.c_str();
	wc.hIconSm = 0;

	::RegisterClassExW( &wc );

	uint32_t style;
	if( settings.fullscreen ){
		style = WS_POPUP;
	}
	else{
		style = WS_OVERLAPPEDWINDOW;
	}

	RECT rc = { 0, 0, settings.width, settings.height };
	::AdjustWindowRect( &rc, style, false );
	
	wnd_ = ::CreateWindowW( wname.c_str(), wname.c_str(), style, settings.left, settings.top, 
		rc.right - rc.left, rc.bottom - rc.top, 0, 0, hInstance, 0 );
	DWORD err = GetLastError();
	HRESULT result = HRESULT_FROM_WIN32( err );
	UNUSED( result );

	::GetClientRect( wnd_, &rc );
	left_ = settings.left;
	top_ = settings.top;
	width_ = rc.right - rc.left;
	height_ = rc.bottom - rc.top;

	::ShowWindow( wnd_, SW_NORMAL );
	::UpdateWindow( wnd_ );
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return ::DefWindowProc( hWnd, uMsg, wParam, lParam );
}