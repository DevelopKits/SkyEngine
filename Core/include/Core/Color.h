#pragma once

class Color{
public:
	float r() const{
		return color_[0];
	}

	float g() const{
		return color_[1];
	}

	float b() const{
		return color_[2];
	}

	float a() const{
		return color_[3];
	}

	void RGBA( uint8_t & R, uint8_t & G, uint8_t & B, uint8_t & A ) const{
		R = static_cast<uint8_t>( this->r()*255 );
		G = static_cast<uint8_t>( this->g()*255 );
		B = static_cast<uint8_t>( this->b()*255 );
		A = static_cast<uint8_t>( this->a()*255 );
	}

	uint32_t ARGB() const{
		uint8_t r,g,b,a;
		this->RGBA( r, g, b, a );
		return a<<24 | r<<16 | g<<8 | a;
	}

private:
	float color_[4];
};