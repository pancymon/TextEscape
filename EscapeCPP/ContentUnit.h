#ifndef CONTENTUNIT_H
#define CONTENTUNIT_H

#include"Content.h"

const int help_content_ID = -1;
const int start_content_ID = 0;

class ContentUnit
{
public:
	ContentUnit() {}
	ContentUnit(Content content) :content(content) {}
	virtual Content get_content() { return content; }
	virtual void run();
	void run_content(Content content);
	int ID;
	Content content;
};

#endif