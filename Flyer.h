#pragma once
#include "Enemy.h"

class Flyer : public Enemy {
public:
	Flyer(std::string name, int health, int health_taken, int health_taken_2, std::string description);
	Flyer();
	~Flyer();
	int Claws(int something, int health_taken_2);
protected:
	std::string name;
	int health;
	int health_taken;
	int health_taken_2;
	std::string description;
};