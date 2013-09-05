#include "boost/smart_ptr.hpp"

class RenderEngine;
typedef boost::shared_ptr<RenderEngine> RenderEnginePtr;

class Context;
typedef Context* ContextPtr;

class App3DFramework;
typedef App3DFramework* App3DFrameworkPtr;

class RenderFactory;
typedef boost::shared_ptr<RenderFactory> RenderFactoryPtr;

class ResLoader;
typedef ResLoader* ResLoaderPtr;

class DllLoader;
typedef DllLoader* DllLoaderPtr;

class XMLDocument;
typedef XMLDocument* XMLDocumentPtr;

class XMLNode;
typedef boost::shared_ptr<XMLNode> XMLNodePtr;

class XMLAttribute;
typedef boost::shared_ptr<XMLAttribute> XMLAttributePtr;

class ResIdentifier;
typedef ResIdentifier* ResIdentifierPtr;

class Window;
typedef boost::shared_ptr<Window> WindowPtr;

class FrameBuffer;
typedef FrameBuffer* FrameBufferPtr;