#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int health_taken, int health_taken_2, std::string description) {
	this->name = name;
	this->health = health;
	this->health_taken = health_taken;
	this->health_taken_2 = health_taken_2;
	this->description = description;
}

Enemy::Enemy()
{

}

Enemy::~Enemy() {

}

std::string Enemy::GetName() {
	return this->name;
}

int Enemy::GetHealth() {
	return this->health;
}

int Enemy::GetHealthTaken() {
	return this->health_taken;
}

int Enemy::GetHealthTaken2() {
	return this->health_taken_2;
}

std::string Enemy::GetDescription() {
	return this->description;
}

//When player attacks using a certain weapon, this happens

int Enemy::TakeHit(int amount) {
	health = health - amount;
	return health;
}

/* What is in the Attack method right now is just a placeholder. When we get it to actually attack, this line will be removed. */

int Enemy::Attack(int something, int health_taken) {
	something = something - health_taken;
	return something;
}

void Enemy::Add(Item* item) {
	enemyInv.push_back(item);
}

void Enemy::Loot(Inventory* thing) {
	for (int i = 0; i < enemyInv.size(); i++) {
		thing->add(enemyInv[i]);
	}
}

