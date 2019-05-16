#pragma once
#include "CombatItem.h"

class Spells : public CombatItem {
public:
	Spells(std::string name, std::string description);
	Spells();
	~Spells();
	std::string GetName();
	std::string GetDescription();
	void SnowSpell(int something);
	void FireSpell(int something);
	void ThunderSpell(int something);
protected:
	std::string name, description;
};