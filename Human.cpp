#include "Human.h"

Human::Human(std::string name, int health, int health_taken, int health_taken_2, std::string description) {
	this->name = name;
	this->health = health;
	this->health_taken = health_taken;
	this->health_taken_2 = health_taken_2;
	this->description = description;
}


Human::Human() {

}

Human::~Human() {

}



int Human::MummysCurse(int something) {
	while (something != 0) {
		Sleep(100);
		something -= 1;
		std::cout << something << std::endl;
	}
	std::cout << "You're dead." << std::endl;
	return something;
}

int Human::restoreHealth()
{
	return this->health = 50;
}

int Human::Infection(int something) {
	while (something != 0) {
		Sleep(500);
		something -= 2;
		std::cout << something << std::endl;
	}
	std::cout << "You're dead." << std::endl;
	return something;
}