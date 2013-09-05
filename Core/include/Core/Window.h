#pragma once

#include <stdint.h>
#include <string>
#include <Windows.h>
#include "RenderSettings.h"

class SKYENGINE_CORE_API Window
{
public:
	Window( std::string const & name, RenderSettings const & settings );

	int32_t Left() const{
		return left_;
	}

	int32_t Top() const{
		return top_; 
	}

	int32_t Width() const{
		return width_;
	}

	int32_t Height() const{
		return height_;
	}

	HWND HWnd() const {
		return wnd_;
	}

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	std::string name_;
	int32_t left_;
	int32_t top_;
	int32_t width_;
	int32_t height_;

	HWND wnd_;
};