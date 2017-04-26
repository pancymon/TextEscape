#ifndef OBJECT_TOOL_H
#define OBJECT_TOOL_H

#include"Object.h"

//const int no_use_alone_ID = -5;
//const int no_use_on_that_ID = -6;

class Object_Tool : public Object
{
public:
	//Object_Tool() {}
	Object_Tool(std::unordered_map<std::string, std::vector<int>> acceptors, std::unordered_map<std::string, std::vector<int>> act, std::string name) : acceptors(acceptors), Object::Object(act, name) {}
	//int get_content_ID_when_used(std::string object);
//private:
	std::vector<int> look();
	std::vector<int> take();
	std::vector<int> use(std::string acceptor);

	std::unordered_map<std::string, std::vector<int>> acceptors;
};

#endif
