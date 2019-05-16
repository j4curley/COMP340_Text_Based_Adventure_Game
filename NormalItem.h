#pragma once
#include "Item.h"

class NormalItem : public Item {
public:
	NormalItem(std::string name, std::string description);
	NormalItem();
	~NormalItem();
	std::string GetName();
	std::string GetDescription();
	int Heal(int something);
	void Use(NormalItem item);
protected:
	std::string name, description;
};

