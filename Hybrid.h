#pragma once
#include "Enemy.h"

class Hybrid : public Enemy {
public:
	Hybrid(std::string name, int health, int health_taken, int health_taken_2, std::string description);
	Hybrid();
	~Hybrid();
protected:
	std::string name;
	int health;
	int health_taken;
	int health_taken_2;
	std::string description;
};