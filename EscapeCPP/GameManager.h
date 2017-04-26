#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"ContentUnit_Bool.h"
#include"Object_Tool.h"
#include<unordered_set>

class GameManager
{
public:
	static GameManager* Instance();

	//void Update(Time elapsed);

	int get_bool(std::string name);
	void Initialize(std::string game_name);
	void Update();
	bool run_content(Content conten);

	std::unordered_set<std::string> visible;
	std::unordered_set<std::string> invetory;
private:
	//bool in_puzzle;
	std::unordered_map<int, ContentUnit*> contentUnits;
	std::unordered_map<std::string, Object*> objects;
	std::unordered_map<std::string, bool> blackboard;
	
	void debug();

	bool processCmd(std::vector<std::string>& cmd);

	void Initialize_Default();
	void Initialize_Contents_Puzzle(std::string game_name);
	void Initialize_Contents_bool(std::string game_name);
	void Initialize_Contents(std::string game_name);
	void Initialize_Objects(std::string game_name);
	void Initialize_Tools(std::string game_name);

	//singleton
	GameManager();
	GameManager(GameManager const&);
	GameManager& operator=(GameManager const&);
	static GameManager* m_pInstance;
};

#endif