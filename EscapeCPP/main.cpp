#include<iostream>
#include<string>
#include<vector>
#include"Object.h"
#include"GameManager.h"
using namespace std;

void processCommand(string cmd, string pattern)
{
	vector<string> svec;
	int pos = 0;
	while ((pos = cmd.find(pattern)) != string::npos)
	{
		svec.push_back(cmd.substr(0, pos));
		cmd = cmd.substr(pos+pattern.size(), cmd.size()-pos-pattern.size());
	}
	if (cmd.size() != 0)
		svec.push_back(cmd);
	for (int i = 0; i < svec.size(); i++)
	{
		cout << svec[i] << ends;
	}
}

class A
{
public:
	virtual void print() { cout << "a" << endl; }
	int ID;
};

class B :public A
{
public:
	void print() { cout << "b" << endl; }
};

int main()
{
	string game = "game1";
	GameManager::Instance()->Initialize(game);
	GameManager::Instance()->Update();
	return 0;
}