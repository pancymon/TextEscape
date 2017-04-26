#ifndef OBJECT_H
#define OBJECT_H

//const int no_take_ID = -1;
//const int no_use_ID = -2;
//const int no_look_ID = -3;
//const int no_use_on_ID = -4;

#include<unordered_map>
#include<vector>

class Object
{
public:
	//Object() {}
	Object(std::unordered_map < std::string, std::vector<int>> act) : actions(act) {}
	Object(std::unordered_map < std::string, std::vector<int>> act, std::string name) : actions(act), name(name) {}
	//Object(std::string name, std::unordered_map<std::string, std::vector<int>> act) : name(name), actions(act) {}
	//int get_content_ID(std::string action);
//private:

	virtual std::vector<int> look();
	virtual std::vector<int> take();
	virtual std::vector<int> use(std::string acceptor);

	std::string name;
	std::unordered_map<std::string, std::vector<int>> actions;
};

#endif