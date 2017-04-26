#include"GameManager.h"
#include<iostream>
#include<sstream>

using namespace std;

void GameManager::debug()
{
	for (auto object : objects)
		for (auto action : object.second->actions)
			for (auto ID : action.second)
			{
				if (!contentUnits.count(ID))
					cout << "unit doesn't exit: " << object.first << ends << action.first << ends << ID << endl;
			}


}