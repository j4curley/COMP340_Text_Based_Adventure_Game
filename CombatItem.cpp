#include "CombatItem.h"

CombatItem::CombatItem(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

CombatItem::CombatItem() {

}

CombatItem::~CombatItem() {

}

std::string CombatItem::GetName() {
	return name;
}

std::string CombatItem::GetDescription() {
	return description;
}