#pragma once
#include "Enemy.h"

class Animal : public Enemy {
public:
	Animal(std::string name, int health, int health_taken, int health_taken_2, std::string description);
	Animal();
	~Animal();
	int StoneGas(int something);
protected:
	std::string name;
	int health;
	int health_taken;
	int health_taken_2;
	std::string description;
};