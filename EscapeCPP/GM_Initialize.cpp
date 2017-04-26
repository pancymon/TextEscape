#include<fstream>
#include<iostream>
#include<sstream>
#include"GameManager.h"
#include"ContentUnit_Puzzle.h"

using namespace std;

vector<string> parseFile(string filename)
{
	vector<string> answer;
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "open failed: " <<filename<< endl;
		return answer;
	}

	string line;
	while (getline(file, line))
	{
		if (line == ""||line[0]=='/')
			continue;
		answer.push_back(line);
	}
	file.close();
	return answer;
}

inline void parseLine_Content(string& line, Content& content)
{
	size_t pos = line.find(' ');
	string type = line.substr(0, pos);
	string remain = line.substr(pos + 1, line.size() - pos - 1);
	if (type == "reveal")
		content.reveal.push_back(remain);
	else if (type == "eliminate")
		content.eliminate.push_back(remain);
	else if (type == "change")
		content.change.push_back(remain);
	else if (type == "content")
		content.content.push_back(remain);
	else if (type == "consume")
		content.consume.push_back(remain);
	else
		cout << type << ends << remain << endl;
}

inline void parseLine_Object(string& line, unordered_map<string, vector<int>>& actions)
{
	stringstream ss(line);
	string type;
	ss >> type;
	int ID = 0;
	while (ss >> ID)
		actions[type].push_back(ID);
}

void GameManager::Initialize_Default()
{
	//Content no_take;
	//Content no_look;
	//Content no_use;
	//Content no_use_on;
	//Content no_use_alone;
	//Content no_use_on_that;

	//no_take.content = "You can't take it.";
	//no_look.content = "There is nothing interesting about it.";
	//no_use.content = "You can't use it.";
	//no_use_on.content = "You can't use it on/with anything else.";
	//no_use_alone.content = "You can't use it alone. Try use it on/with something.";
	//no_use_on_that.content = "You can't use it on/with that.";

	//contentUnits[no_take_ID] = new ContentUnit(no_take);
	//contentUnits[no_look_ID] = new ContentUnit(no_look);
	//contentUnits[no_use_ID] = new ContentUnit(no_use);
	//contentUnits[no_use_on_ID] = new ContentUnit(no_use_on);
	//contentUnits[no_use_alone_ID] = new ContentUnit(no_use_alone);
	//contentUnits[no_use_on_that_ID] = new ContentUnit(no_use_on_that);
}

void GameManager::Initialize_Contents_Puzzle(std::string game_name)
{
	vector<string> lines = parseFile(game_name + "/puzzles.txt");

	size_t start = 0, end1 = 0, end2 = 0;
	while (start < lines.size())
	{
		end1 = start;
		while (lines[end1] != "content_end")
			end1++;
		end2 = end1 + 1;
		while (lines[end2] != "puzzle_end")
			end2++;
		int ID = stoi(lines[start]);
		Content c_right;
		for (size_t i = start + 3; i < end1; i++)
		{
			parseLine_Content(lines[i], c_right);
		}
		Content c_wrong;
		for (size_t i = end1 + 1; i < end2; i++)
		{
			parseLine_Content(lines[i], c_wrong);
		}
		contentUnits[ID] = new ContentUnit_Puzzle(lines[start+1],lines[start+2], c_right, c_wrong);
		start = end2 + 1;
	}
}

void GameManager::Initialize_Contents_bool(string game_name)
{
	vector<string> lines = parseFile(game_name + "/contents_bool.txt");
	size_t start = 0, end1 = 0, end2 = 0;
	while (start < lines.size())
	{
		end1 = start;
		while (lines[end1] != "content_end")
			end1++;
		end2 = end1 + 1;
		while (lines[end2] != "content_end")
			end2++;
		int ID = stoi(lines[start]);
		string bool_name = lines[start + 1];
		blackboard[bool_name] = false;
		Content c_true;
		for (size_t i = start + 2; i < end1; i++)
		{
			parseLine_Content(lines[i], c_true);
		}
		Content c_false;
		for (size_t i = end1 + 1; i < end2; i++)
		{
			parseLine_Content(lines[i], c_false);
		}
		start = end2 + 1;
		contentUnits[ID] = new ContentUnit_Bool(bool_name, c_true, c_false);
	}
}

void GameManager::Initialize_Contents(string game_name)
{
	vector<string> lines = parseFile(game_name + "/contents.txt");
	size_t start = 0, end = 0;
	while (start < lines.size())
	{
		end = start;
		while (lines[end] != "content_end")
			end++;

		int ID = stoi(lines[start]);
		Content content;
		for (size_t i = start + 1; i < end; i++)
		{
			parseLine_Content(lines[i], content);
		}
		start = end + 1;
		contentUnits[ID] = new ContentUnit(content);
	}
}

void GameManager::Initialize_Objects(string game_name)
{
	vector<string> lines = parseFile(game_name + "/objects.txt");
	size_t start = 0, end = 0;
	while (start < lines.size())
	{
		end = start;
		while (lines[end] != "object_end")
			end++;
		string name = lines[start];
		unordered_map<string, vector<int>> actions;
		for (size_t i = start + 1; i < end; i++)
		{
			parseLine_Object(lines[i], actions);
		}
		objects[name] = new Object(actions, name);
		start = end + 1;
	}
}

void GameManager::Initialize_Tools(string game_name)
{
	vector<string> lines = parseFile(game_name + "/tools.txt");
	size_t start = 0, end1 = 0, end2 = 0;
	while (start < lines.size())
	{
		end1 = start;
		while (lines[end1] != "actions_end")
			end1++;
		end2 = end1 + 1;
		while (lines[end2] != "acceptors_end")
			end2++;
		string name = lines[start];
		unordered_map<string, vector<int>> actions;
		for (size_t i = start + 1; i < end1; i++)
		{
			parseLine_Object(lines[i], actions);
		}
		unordered_map<string, vector<int>> acceptors;
		for (size_t i = end1 + 1; i < end2; i++)
		{
			parseLine_Object(lines[i], acceptors);
		}
		objects[name] = new Object_Tool(acceptors, actions, name);
		start = end2 + 1;
	}
}

void GameManager::Initialize(string game_name)
{
	//Initialize_Default();

	Initialize_Contents_Puzzle(game_name);
	Initialize_Contents(game_name);
	Initialize_Contents_bool(game_name);


	Initialize_Objects(game_name);
	Initialize_Tools(game_name);

	cout << "Hello and welcome to \"escape the room\" text adventrue game." << endl;
	cout << "In this game, instead of all the graphic and audio, " << endl;
	cout << "you read text and type commands." << endl;
	cout << "If you are new to this kind of game, "<<endl;
	cout << "type \"help\" and press Enter to get a hint." << endl;
	cout << "I hope you enjoy this game!" << endl << endl;

	//system("pause");

	run_content(contentUnits[start_content_ID]->get_content());
	cout << endl;
}