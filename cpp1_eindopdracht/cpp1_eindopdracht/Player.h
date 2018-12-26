#pragma once
#include "Ship.h"

class Player
{
public:
	Player();
	~Player() = default;

	int gold = 0;
	Ship playerShip;

	bool playerhasDied();
	bool playerHas1milGold();
private:
};
