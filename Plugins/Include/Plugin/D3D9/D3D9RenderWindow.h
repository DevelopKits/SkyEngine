#pragma once

#include "D3D9FrameBuffer.h"
#include "Core/RenderSettings.h"

class D3D9RenderWindow : public D3D9FrameBuffer
{
public:
	D3D9RenderWindow( RenderSettings const & settings );

};