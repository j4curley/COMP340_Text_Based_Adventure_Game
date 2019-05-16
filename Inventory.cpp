#include "Inventory.h"
#include <iostream>
#include <vector>   //  To enable the use of the vector class.
#include <string>

Inventory::Inventory() {

}

void Inventory::add(Item* item_name) {
	inventory.push_back(item_name);
}

void Inventory::showInventory() {
	char input[80];
	std::cin >> input;
	char inventoryRequest[] = "i";
	int invent = strcmp(input, inventoryRequest);
	//compare the player input to inventoryRequest (i) to see if they want to look at inventory.
	if (invent == 0) {
		displayInventory();
	}
}

void Inventory::displayInventory() {
	//vector<string> inventory;
	std::cout << "You have " << inventory.size() << " items.\n";
	std::cout << "\n******Inventory******";
	std::cout << "\nYour items:\n";
	for (int i = 0; i < inventory.size(); ++i)
		std::cout << inventory[i]->GetName() << std::endl;
}

std::vector<Item*> Inventory::GetInventory() {
	return inventory;
}

int Inventory::Exists(Item* item_name) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->GetName() == item_name->GetName()) {
			return 1;
			break;
		}
	}return 0;
}


