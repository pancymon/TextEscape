#include"GameManager.h"
#include<iostream>
#include<sstream>

using namespace std;

bool GameManager::run_content(Content content)
{
	bool win = false;

	for (size_t i = 0; i < content.content.size(); i++)
	{
		cout << content.content[i] << endl;
		if (content.content[i].find("win!") != string::npos)
			win = true;
	}
	for (size_t i = 0; i < content.reveal.size(); i++)
		visible.insert(content.reveal[i]);
	for (size_t i = 0; i < content.eliminate.size(); i++)
		visible.erase(content.eliminate[i]);
	for (size_t i = 0; i < content.change.size(); i++)
		blackboard[content.change[i]] = !blackboard[content.change[i]];
	//they are initialized to be false, so they become true after consumed
	for (size_t i = 0; i < content.consume.size(); i++)
		blackboard[content.consume[i]] = true;

	return win;
}

int GameManager::get_bool(string name)
{
	if (!blackboard.count(name))
		return -1;
	return blackboard[name] ? 1 : 0;
}

vector<string> parseCmd(string cmd)
{
	vector<string> answer;
	stringstream ss(cmd);
	string tmp;
	while (ss >> tmp)
	{
		if (tmp == "the" || tmp == "a")
			continue;
		answer.push_back(tmp);
	}
	return answer;

}

bool GameManager::processCmd(vector<string>& cmd)
{
	bool win = false;
	if (cmd.size() == 0)
		return win;
	vector<int> units;
	if (cmd[0] == "look")
	{
		if (cmd.size() < 3 || cmd[1] != "at")
			cout << "Try look at something." << endl;
		else if (!objects.count(cmd[2]))
			cout << "You can't find any " << cmd[2] << "." << endl;
		else
			units = objects[cmd[2]]->look();
		
	}
	else if (cmd[0] == "take")
	{
		if (cmd.size() < 2)
			cout << "Try take something." << endl;
		else if(!objects.count(cmd[1]))
			cout << "You can't find any " << cmd[1] << "." << endl;
		else
			units = objects[cmd[1]]->take();
	}
	else if (cmd[0] == "use")
	{
		if (cmd.size() < 2)
			cout << "Try use something." << endl;
		else if (!objects.count(cmd[1]))
			cout << "You can't find any " << cmd[1] << "." << endl;
		else if (cmd.size() == 2)
			units = objects[cmd[1]]->use(string());
		else if (cmd.size() < 4 || (cmd[2] != "on"&&cmd[2] != "with"))
		{
			cout << "Try use something or use something on/with something." << endl;
		}
		else
			units = objects[cmd[1]]->use(cmd[3]);
	}
	else if (cmd[0] == "help" || cmd[0] == "h")
	{
		//cout << "This is help." << endl;
		units.push_back(help_content_ID);
	}
	else if (cmd[0] == "i" || cmd[0] == "inventory")
	{
		if (invetory.size() == 0)
			cout << "You have nothing in your inventory." << endl;
		else
		{
			cout << "Things you have:" << endl;
			for (string item : invetory)
				cout << item << ", ";
			cout << endl;
		}
	}
	else if (cmd[0] == "cong_debug")
	{
		debug();
	}
	else
		cout << cmd[0] << " is not a verb you can use." << endl;

	for (size_t i = 0; i < units.size(); i++)
	{
		if (!contentUnits.count(units[i]))
			cout << "This unit doesn't exist. Number: "<<units[i]<< endl;
		else
		{
			if (run_content(contentUnits[units[i]]->get_content()))
				win = true;
		}
	}
	cout << endl;
	return win;
}

void GameManager::Update()
{
	string cmd;
	while (getline(cin, cmd))
	{
		if (processCmd(parseCmd(cmd)))
			break;
	}
}

