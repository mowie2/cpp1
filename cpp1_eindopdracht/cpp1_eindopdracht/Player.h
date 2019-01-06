#pragma once
#include "Ship.h"

class Player
{
public:
	Player();
	~Player() = default;

	int gold = 0;
	Ship playerShip;
	bool quit_ = false;

	bool playerHasDied() const;
	bool playerHas1milGold() const;
	void quit();
	bool playerHasQuit() const;
private:
};
