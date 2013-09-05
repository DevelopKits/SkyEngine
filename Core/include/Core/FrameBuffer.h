#pragma once
#include "Core/Color.h"

class SKYENGINE_CORE_API FrameBuffer
{
public:
	enum Attatchment
	{
		ATT_DepthStencil,
		ATT_Color0,
		ATT_Color1,
		ATT_Color2,
		ATT_Color3,
		ATT_COlor4,
		ATT_Color5,
		ATT_Color6,
		ATT_Color7
	};

	enum ClearBufferMask
	{
		CBM_Depth = 1UL << 0,
		CBM_Color = 1UL << 1,
		CBM_Stencil = 1UL << 2
	};

public:
	FrameBuffer();
	virtual ~FrameBuffer();

	static FrameBufferPtr NullObject();

	virtual void Clear( uint32_t flags, Color color, float depth, int32_t stencil ) = 0;
};