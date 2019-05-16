#pragma once
#include "Item.h"

class CombatItem : public Item {
public:
	CombatItem(std::string name, std::string description);
	CombatItem();
	~CombatItem();
	std::string GetName();
	std::string GetDescription();
protected:
	std::string name, description;
};