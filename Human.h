#pragma once
#include <Windows.h>
#include "Enemy.h"

class Human : public Enemy {
public:
	Human(std::string name, int health, int health_taken, int health_taken_2, std::string description);
	Human();
	~Human();
	int restoreHealth();
	int MummysCurse(int something);
	int Infection(int something);
protected:
	std::string name;
	int health;
	int health_taken;
	int health_taken_2;
	std::string description;
};