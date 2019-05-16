#pragma once
/*#ifndef INVENTORY_H
#define INVENTORY_H*/
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"


class Inventory
{
public:
	//Constructor
	Inventory();
	//Methods.
	void add(Item* item_name);
	void displayInventory();
	void showInventory();
	std::vector<Item*> GetInventory();
	int Exists(Item* item_name);
private:
	std::vector<Item*> inventory;
	std::vector<Item*>::iterator myIterator;
	std::vector<Item*>::const_iterator iter;
};


