#include "pch.h"
#include "Player.h"

Player::Player()
{
	playerShip = Ship("test",100,100,4,100,MyString("hoi"));
}

bool Player::playerhasDied()
{
	return playerShip.get_hp() <= 0;
}

bool Player::playerHas1milGold()
{
	return gold >= 1000000;
}
