#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
class Item {
public:
	Item(std::string name, std::string description, int damage);
	Item();
	~Item();
	int GetDamage();
	std::string GetDescription();
	std::string GetName();
protected:
	int damage;
	std::string description, name;
};
#endif