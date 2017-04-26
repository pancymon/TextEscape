#ifndef CONTENTUNIT_PUZZLE
#define CONTENTUNIT_PUZZLE

#include"ContentUnit.h"

class ContentUnit_Puzzle :public ContentUnit
{
public:
	ContentUnit_Puzzle(std::string question, std::string answer, Content right, Content wrong) :question(question), answer(answer), right(right), wrong(wrong) {}
	//void run_content();
	Content get_content();
private:
	std::string question;
	std::string answer;
	Content wrong;
	Content right;

};

#endif
