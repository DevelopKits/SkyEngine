#pragma once

#include <stdint.h>
#include <d3d9.h>

class D3D9VideoMode
{
public:
	D3D9VideoMode();
	D3D9VideoMode( uint32_t width, uint32_t height, D3DFORMAT format );

	uint32_t Width() const;
	uint32_t Height() const;
	D3DFORMAT Format() const;

	bool operator<( D3D9VideoMode const & rhs ) const;
	bool operator==( D3D9VideoMode const & rhs ) const;

private:
	uint32_t width_;
	uint32_t height_;
	D3DFORMAT format_;
};