#include"ContentUnit.h"
#include<iostream>

using namespace std;


void ContentUnit::run()
{
	//cout << content.content << endl;
}

void ContentUnit::run_content(Content c)
{
	for (size_t i = 0; i < c.content.size();i++)
	cout << c.content[i] << endl;

}
