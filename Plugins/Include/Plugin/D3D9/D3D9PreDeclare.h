#pragma once

#include "boost/smart_ptr.hpp"

class D3D9Adapter;
typedef boost::shared_ptr<D3D9Adapter> D3D9AdapterPtr;

class D3D9AdapterList;
typedef D3D9AdapterList* D3D9AdapterListPtr;

class D3D9RenderEngine;
typedef D3D9RenderEngine* D3D9RenderEnginePtr;

class D3D9RenderFactory;
typedef D3D9RenderFactory* D3D9RenderFactoryPtr;

class D3D9RenderWindow;
typedef boost::shared_ptr<D3D9RenderWindow> D3D9RenderWindowPtr;

