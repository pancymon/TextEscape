#include"Object_Tool.h"
#include"GameManager.h"
#include<iostream>

using namespace std;

//static unordered_set<string> visible = GameManager::Instance()->visible;
//static unordered_set<string> invetory = GameManager::Instance()->invetory;

//int Object_Tool::get_content_ID_when_used(std::string object)
//{
//	if (!acceptors.count(object))
//		return -1;
//	return acceptors[object];
//}

vector<int> Object_Tool::look()
{
	vector<int> answer;
	if (!GameManager::Instance()->visible.count(name) && !GameManager::Instance()->invetory.count(name))
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

vector<int> Object_Tool::take()
{
	vector<int> answer;
	if (!GameManager::Instance()->visible.count(name))
	{
		cout << "You can't find any " << name << " to take." << endl;
		if (GameManager::Instance()->invetory.count(name))
			cout << "You already have one in your inventory." << endl;
	}
	else
	{
		GameManager::Instance()->invetory.insert(name);
		GameManager::Instance()->visible.erase(name);
		cout << "You take the " << name << "." << endl;
		answer = actions["take"];
	}
	return answer;
}

vector<int> Object_Tool::use(string acceptor)
{
	vector<int> answer;
	if (!GameManager::Instance()->invetory.count(name))
	{
		if (GameManager::Instance()->visible.count(name))
			cout << "You must take it before use it. Try take " <<name<<"."<< endl;
		else
			cout << "You can't find any " << name << " to use." << endl;
	}
	else
	{
		if (acceptor == "")
		{
			cout << "You can't use the " << name << " alone. Try use " << name << " on/with something." << endl;
		}
		else if(!GameManager::Instance()->visible.count(acceptor))
			cout << "You can't find any " << acceptor << " to use on/with." << endl;
		else if (!acceptors.count(acceptor))
		{
			cout << "You can't use the " << name << " on/with the " << acceptor << "." << endl;
		}
		else
			answer = acceptors[acceptor];
	}
	return answer;

}