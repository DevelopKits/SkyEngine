#pragma once

#include <vector>
#include <stdint.h>
#include <d3d9.h>
#include "Plugin/D3D9/D3D9PreDeclare.h"


class D3D9AdapterList{
public:
	D3D9AdapterList();
	~D3D9AdapterList();
	void Enumerate( IDirect3D9* device );

private:
	std::vector<D3D9AdapterPtr> adapters_;
	uint32_t current_adpater_;
};