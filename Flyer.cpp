#include "Flyer.h"

Flyer::Flyer(std::string name, int health, int health_taken, int health_taken_2, std::string description) {
	this->name = name;
	this->health = health;
	this->health_taken = health_taken;
	this->health_taken_2 = health_taken_2;
	this->description = description;
}

Flyer::Flyer() {

}

Flyer::~Flyer() {

}

int Flyer::Claws(int something, int health_taken_2) {
	something -= health_taken_2;
	return something;
}
