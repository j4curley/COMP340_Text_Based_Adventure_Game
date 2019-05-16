#include "Spells.h"

Spells::Spells(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

Spells::Spells() {

}

Spells::~Spells() {

}

std::string Spells::GetName() {
	return name;
}

std::string Spells::GetDescription() {
	return description;
}

void Spells::SnowSpell(int something) {
	something -= 10;
}

void Spells::FireSpell(int something) {
	something -= 12;
}

void Spells::ThunderSpell(int something) {
	something -= 15;
}