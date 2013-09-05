#pragma once
#include <rapidxml/rapidxml.hpp>
#include <vector>
#include <rapidxml/rapidxml_print.hpp>
#include "Core/PreDeclare.h"

class SKYENGINE_CORE_API XMLDocument
{
public:
	XMLDocument();
	virtual ~XMLDocument();
	XMLNodePtr Parse( ResIdentifierPtr const & source);

private:
	void* doc_;
	std::vector<char> xml_src_;

	XMLNodePtr root_;
};

class SKYENGINE_CORE_API XMLNode{
public:
	explicit XMLNode( void* node );
    XMLNodePtr FirstNode(std::string const & name);
    XMLNodePtr LastNode(std::string const & name);
    XMLNodePtr FirstNode();
    XMLNodePtr LastNode();

	XMLAttributePtr FirstAttrib(std::string const & name);
    XMLAttributePtr LastAttrib(std::string const & name);
    XMLAttributePtr FirstAttrib();
    XMLAttributePtr LastAttrib();

    XMLAttributePtr Attrib(std::string const & name);
    int32_t AttribInt(std::string const & name, int32_t default_val);
    uint32_t AttribUInt(std::string const & name, uint32_t default_val);
    float AttribFloat(std::string const & name, float default_val);
    std::string AttribString(std::string const & name, std::string default_val);

private:
	void* node_;
	std::string name_;
};

class SKYENGINE_CORE_API XMLAttribute{
public:
	explicit XMLAttribute(void* attr);
	std::string const & Name() const;

	int32_t ValueInt() const;
	uint32_t ValueUInt() const;
	float ValueFloat() const;
	std::string const & ValueString() const;
private:
	void* attr_;
	std::string name_;
	std::string value_;
};