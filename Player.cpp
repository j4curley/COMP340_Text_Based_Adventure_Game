#include "Player.h"

Player::Player(int health) {
	this->health = health;
}

void Player::TakeHit(int amount) {
	health = health - amount;
}

int Player::restoreHealth()
{
	return this->health = 50;
}
Player::Player() {

}

Player::~Player() {

}

int Player::GetHealth() {
	return health;
}