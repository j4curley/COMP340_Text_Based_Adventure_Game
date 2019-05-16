#include "Animal.h"

Animal::Animal(std::string name, int health, int health_taken, int health_taken_2, std::string description) {
	this->name = name;
	this->health = health;
	this->health_taken = health_taken;
	this->health_taken_2 = health_taken_2;
	this->description = description;
}

Animal::Animal() {

}

Animal::~Animal() {

}

int Animal::StoneGas(int something) {
	something = 0;
	std::cout << "You're dead." << std::endl;
	return something;
}
