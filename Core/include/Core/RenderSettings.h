#pragma once

struct RenderSettings{
	RenderSettings()
		:fullscreen(false), left(0), top(0){
	}
	
	bool fullscreen;
	int left;
	int top;
	int width;
	int height;
};

