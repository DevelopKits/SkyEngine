#include "Core/SkyEngine.h"
#include "Core/FrameBuffer.h"

class NullFrameBuffer : public FrameBuffer
{
public:
	void Clear( uint32_t /*flags*/, Color /*color*/, float /*depth*/, int32_t /*stencil*/ ){

		return;
	}
};

FrameBuffer::FrameBuffer(){

}

FrameBuffer::~FrameBuffer(){

} 

FrameBufferPtr FrameBuffer::NullObject(){
	static NullFrameBuffer obj;
	return &obj;
}

