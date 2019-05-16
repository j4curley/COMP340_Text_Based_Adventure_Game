#include "Firearm.h"

Firearm::Firearm(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

Firearm::Firearm() {

}

Firearm::~Firearm() {

}

std::string Firearm::GetName() {
	return name;
}

std::string Firearm::GetDescription() {
	return description;
}

void Firearm::NormalAttack(int something) {
	something -= 5;
}

void Firearm::StrongAttack(int something) {
	something -= 8;
}

void Firearm::RapidFire(int something) {
	something -= 10;
}