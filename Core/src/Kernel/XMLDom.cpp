#include "Core/SkyEngine.h"
#include "Core/XMLDom.h"
#include "Core/ResLoader.h"
#include "Core/CoreUtil.h"
#include "boost/lexical_cast.hpp"


XMLDocument::XMLDocument()
	:root_(0)
{
	doc_ = static_cast<void*>(new( rapidxml::xml_document<> ));
}

XMLDocument::~XMLDocument(){
	if( root_ ) root_.reset();
	delete( doc_ );
}

XMLNodePtr XMLDocument::Parse( ResIdentifierPtr const & source){
	source->seekg( 0, std::ios_base::end );
	int len = static_cast<int>(source->tellg());
	source->seekg( 0, std::ios_base::beg );
	xml_src_.resize( len+1, 0 );
	source->read( &xml_src_[0], len );

	static_cast< rapidxml::xml_document<>* >(doc_)->parse<0>( &xml_src_[0] );
	root_ = MakeSharedPtr<XMLNode>(static_cast<rapidxml::xml_document<>*>(doc_)->first_node());
	return root_;
}


XMLNode::XMLNode( void* node )
	:node_(node)
{
	if( node ){
		name_ = std::string( static_cast< rapidxml::xml_node<>* >(node_)->name(),
			static_cast< rapidxml::xml_node<>* >(node_)->name_size() );
	}
}

XMLNodePtr XMLNode::FirstNode(){
	rapidxml::xml_node<>* node = static_cast< rapidxml::xml_node<>* >(node_)->first_node();
	if( node ){
		return MakeSharedPtr<XMLNode>(node);
	}
	else{
		return XMLNodePtr();
	}
}

XMLNodePtr XMLNode::FirstNode( std::string const & name ){
	rapidxml::xml_node<>* node = static_cast< rapidxml::xml_node<>* >(node_)->first_node( name.c_str() );
	if( node ){
		return MakeSharedPtr<XMLNode>(node);
	}
	else{
		return XMLNodePtr();
	}
}

XMLNodePtr XMLNode::LastNode(){
	rapidxml::xml_node<>* node = static_cast< rapidxml::xml_node<>* >(node_)->last_node();
	if( node ){
		return MakeSharedPtr<XMLNode>(node);
	}
	else{
		return XMLNodePtr();
	}
}

XMLNodePtr XMLNode::LastNode( std::string const & name ){
	rapidxml::xml_node<>* node = static_cast< rapidxml::xml_node<>* >(node_)->last_node( name.c_str() );
	if( node ){
		return MakeSharedPtr<XMLNode>(node);
	}
	else{
		return XMLNodePtr();
	}
}

XMLAttributePtr XMLNode::FirstAttrib(std::string const & name){
	rapidxml::xml_attribute<>* attr = static_cast< rapidxml::xml_node<>* >(node_)->first_attribute(name.c_str());
	if( attr ){
		return MakeSharedPtr<XMLAttribute>( attr );
	}
	else{
		return XMLAttributePtr();
	}
}

XMLAttributePtr XMLNode::LastAttrib(std::string const & name){
	rapidxml::xml_attribute<>* attr = static_cast< rapidxml::xml_node<>* >(node_)->last_attribute(name.c_str());
	if( attr ){
		return MakeSharedPtr<XMLAttribute>( attr );
	}
	else{
		return XMLAttributePtr();
	}
}

XMLAttributePtr XMLNode::FirstAttrib(){
	rapidxml::xml_attribute<>* attr = static_cast< rapidxml::xml_node<>* >(node_)->first_attribute();
	if( attr ){
		return MakeSharedPtr<XMLAttribute>( attr );
	}
	else{
		return XMLAttributePtr();
	}
}

XMLAttributePtr XMLNode::LastAttrib(){
	rapidxml::xml_attribute<>* attr = static_cast< rapidxml::xml_node<>* >(node_)->last_attribute();
	if( attr ){
		return MakeSharedPtr<XMLAttribute>( attr );
	}
	else{
		return XMLAttributePtr();
	}
}

XMLAttributePtr XMLNode::Attrib(std::string const & name){
	return this->FirstAttrib( name );
}

int32_t XMLNode::AttribInt(std::string const & name, int32_t default_val){
	XMLAttributePtr attr = this->Attrib( name );
	return attr ? attr->ValueInt() : default_val;
}

uint32_t XMLNode::AttribUInt(std::string const & name, uint32_t default_val){
	XMLAttributePtr attr = this->Attrib( name );
	return attr ? attr->ValueUInt() : default_val;
}

float XMLNode::AttribFloat(std::string const & name, float default_val){
	XMLAttributePtr attr = this->Attrib( name );
	return attr ? attr->ValueFloat() : default_val;
}

std::string XMLNode::AttribString(std::string const & name, std::string default_val){
	XMLAttributePtr attr = this->Attrib( name );
	return attr ? attr->ValueString() : default_val;
}

XMLAttribute::XMLAttribute( void * attr )
	:attr_(attr)
{
	if( attr ){
		name_ = std::string( static_cast< rapidxml::xml_attribute<>* >(attr_)->name(), static_cast< rapidxml::xml_attribute<>* >(attr_)->name_size());
		value_ = std::string( static_cast< rapidxml::xml_attribute<>* >(attr_)->value(), static_cast< rapidxml::xml_attribute<>* >(attr_)->value_size());
	}
}

std::string const & XMLAttribute::Name() const{
	return name_;
}

int32_t XMLAttribute::ValueInt() const{
	return boost::lexical_cast<int32_t>( value_ );
}

uint32_t XMLAttribute::ValueUInt() const{
	return boost::lexical_cast<uint32_t>( value_ );
}

float XMLAttribute::ValueFloat() const{
	return boost::lexical_cast<float>( value_ );
}

std::string const & XMLAttribute::ValueString() const{
	return value_;
}

