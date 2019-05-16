#pragma once
#include "Weapon.h"

class MeleeWeapon : public Weapon {
public:
	MeleeWeapon(std::string name, std::string description);
	MeleeWeapon();
	~MeleeWeapon();
	std::string GetName();
	std::string GetDescription();
	void NormalAttack(int something);
	void StrongAttack(int something);
	void SpecialAttack(int something);
protected:
	std::string name, description;
};