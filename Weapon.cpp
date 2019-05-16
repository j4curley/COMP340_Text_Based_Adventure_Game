#include "Weapon.h"
#include <string>

Weapon::Weapon(std::string name, std::string description, int damage) {
	this->name = name;
	this->description = description;
	this->damage = damage;
}

Weapon::Weapon() {

}

Weapon::~Weapon() {

}

std::string Weapon::GetName() {
	return name;
}

std::string Weapon::GetDescription() {
	return description;
}

int Weapon::GetDamage() {
	return damage;
}