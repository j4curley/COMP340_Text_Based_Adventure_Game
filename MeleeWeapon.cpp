#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(std::string name, std::string description) {
	this->name;
	this->description;
}

MeleeWeapon::MeleeWeapon() {

}

MeleeWeapon::~MeleeWeapon() {

}

std::string MeleeWeapon::GetName() {
	return name;
}

std::string MeleeWeapon::GetDescription() {
	return description;
}

void MeleeWeapon::NormalAttack(int something) {
	something -= 2;
}

void MeleeWeapon::StrongAttack(int something) {
	something -= 5;
}

void MeleeWeapon::SpecialAttack(int something) {
	something -= 8;
}