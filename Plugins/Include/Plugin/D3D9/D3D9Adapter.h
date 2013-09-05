#pragma once

#include <stdint.h>
#include <d3d9.h>
#include <vector>
#include "Plugin/D3D9/D3D9VideoMode.h"

class D3D9Adapter{
public:
	D3D9Adapter();
	D3D9Adapter( uint32_t adpter_no, IDirect3D9* direct_3d );

	void Enumerate();

private:
	uint32_t adapter_no_;
	IDirect3D9* direct_3d_;

	std::vector<D3D9VideoMode> modes_;
};