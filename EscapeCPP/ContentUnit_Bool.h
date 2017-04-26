#ifndef CONTENTUNITBOOL_H
#define CONTENTUNITBOOL_H

#include"ContentUnit.h"

class ContentUnit_Bool : public ContentUnit
{
public:
	ContentUnit_Bool() {}
	ContentUnit_Bool(std::string bool_name, Content c_true, Content c_false) :bool_name(bool_name), content_true(c_true), content_false(c_false) {}
	virtual Content get_content();
//private:
	std::string bool_name;
	Content content_true;
	Content content_false;
};

#endif
