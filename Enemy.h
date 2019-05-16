#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Inventory.h"

class Enemy {
public:
	Enemy(std::string name, int health, int health_taken, int health_taken_2, std::string description);
	Enemy();
	~Enemy();
	std::string GetName();
	int GetHealth();
	int GetHealthTaken();
	int GetHealthTaken2();
	std::string GetDescription();
	int TakeHit(int amount);
	int Attack(int something, int health_taken);
	void Add(Item* item);
	void Loot(Inventory* thing);
protected:
	std::string name;
	int health;
	int health_taken;
	int health_taken_2;
	std::string description;
	std::vector<Item*> enemyInv;
};

