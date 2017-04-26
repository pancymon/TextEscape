#include"ContentUnit_Puzzle.h"
#include<iostream>

using namespace std;

Content ContentUnit_Puzzle::get_content()
{
	cout << question << endl;
	string tmp;
	getline(cin, tmp);
	if (tmp == answer)
		return right;
	return wrong;
}