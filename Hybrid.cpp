#include "Hybrid.h"

Hybrid::Hybrid(std::string name, int health, int health_taken, int health_taken_2, std::string description) {
	this->name = name;
	this->health = health;
	this->health_taken = health_taken;
	this->health_taken_2 = health_taken_2;
	this->description = description;
}

Hybrid::Hybrid() {

}

Hybrid::~Hybrid() {

}