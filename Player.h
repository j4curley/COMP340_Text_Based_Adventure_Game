#pragma once

class Player {
public:
	Player(int health);
	Player();
	~Player();
	int GetHealth();
	void TakeHit(int amount);
	int restoreHealth();

private:
	int health;
};