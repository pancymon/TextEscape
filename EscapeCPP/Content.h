#ifndef CONTENT_H
#define CONTENT_H

#include<string>
#include<vector>
class Content
{
public:
	Content() { /*puzzle = 0;*/ }
	Content(std::string s) { content.push_back(s); }
//private:
	std::vector<std::string> content;
	std::vector<std::string> reveal;
	std::vector<std::string> eliminate;
	std::vector<std::string> change;
	std::vector<std::string> consume;
	//int puzzle;
	//std::string puzzle_answer;
	//int right_ID;
	//int wrong_ID;
};

#endif