#include "Plugin/D3D9/D3D9VideoMode.h"

D3D9VideoMode::D3D9VideoMode()
	:width_(0), height_(0), format_( D3DFMT_UNKNOWN )
{
}

D3D9VideoMode::D3D9VideoMode( uint32_t width, uint32_t height, D3DFORMAT format )
	:width_(width), height_(height), format_(format)
{
}

uint32_t D3D9VideoMode::Width() const {
	return width_;
}

uint32_t D3D9VideoMode::Height() const {
	return height_;
}

D3DFORMAT D3D9VideoMode::Format() const{
	return format_;
}

bool D3D9VideoMode::operator<( D3D9VideoMode const & rhs ) const{
	if( Width() < rhs.Width() ){
		return true;
	}
	else{
		if( Width() == rhs.Width() ){
			if( Height() < rhs.Height() ){
				return true;
			} 
			else if( Height() == rhs.Height() ) {
				return Format() < rhs.Format();
			}
		}
	}

	return false;
}

bool D3D9VideoMode::operator==( D3D9VideoMode const & rhs ) const {
	if( Width() == rhs.Width() 
		&& Height() == rhs.Height()
		&& Format() == rhs.Format()
		){
			return true;
	}
	return false;
}