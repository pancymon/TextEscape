#include"Object.h"
#include"GameManager.h"
#include<iostream>

using namespace std;

//static unordered_set<string> visible = GameManager::Instance()->visible;
//static unordered_set<string> invetory = GameManager::Instance()->invetory;

//int Object::get_content_ID(std::string action)
//{
//	if (!actions.count(action))
//		return -1;
//	return actions[action];
//}

vector<int> Object::take()
{
	vector<int> answer;
	if (!GameManager::Instance()->visible.count(name))
	{
		cout << "You can't find any " << name << " to take." << endl;
	}
	else
		cout << "You can't take the " << name << "." << endl;
	return answer;
}

vector<int> Object::look()
{
	vector<int> answer;
	if (!GameManager::Instance()->visible.count(name))
	{
		cout << "You can't find any " << name << "." << endl;
	}
	else if (!actions.count("look"))
	{
		cout << "There is nothing interesting about the " << name << "." << endl;
	}
	else
		answer = actions["look"];
	return answer;
}

vector<int> Object::use(string acceptor)
{
	vector<int> answer;
	if (!GameManager::Instance()->visible.count(name))
	{
		cout << "You can't find any " << name << " to use." << endl;
	}
	else if (acceptor != "")
	{
		cout << "You can't use the "<<name<<" on/with anything else." << endl;
	}
	else if (!actions.count("use"))
	{
		cout << "You can't use the " << name << " ." << endl;
	}
	else answer = actions["use"];
	return answer;
}
