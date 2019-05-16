#pragma once
#include "Weapon.h"

class Firearm : public Weapon {
public:
	Firearm(std::string name, std::string description);
	Firearm();
	~Firearm();
	std::string GetName();
	std::string GetDescription();
	void NormalAttack(int something);
	void StrongAttack(int something);
	void RapidFire(int something);
protected:
	std::string name, description;
};