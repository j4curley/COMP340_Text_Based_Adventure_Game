#pragma once
#include "CombatItem.h"

class Weapon : public CombatItem {
public:
	Weapon(std::string name, std::string description, int damage);
	Weapon();
	~Weapon();
	std::string GetName();
	std::string GetDescription();
	int GetDamage();
protected:
	std::string name, description;
	int damage;
};