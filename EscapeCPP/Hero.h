#ifndef HERO_H
#define HERO_H

#include<unordered_set>;

class Hero
{
public:
	Hero() {}
private:
	std::unordered_set<std::string> iventory;
};

#endif