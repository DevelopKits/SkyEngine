#pragma once

#include "Core/FrameBuffer.h"

class D3D9FrameBuffer : public FrameBuffer
{
public:
	void Clear( uint32_t flags, Color color, float depth, int32_t stencil );
};