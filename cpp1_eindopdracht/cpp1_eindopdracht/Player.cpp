#include "pch.h"
#include "Player.h"

Player::Player()
{
	playerShip = Ship("test",100,100,4,100,MyString(""));
}

bool Player::playerHasDied() const
{
	return playerShip.get_hp() <= 0;
}

bool Player::playerHas1milGold() const
{
	return gold >= 1000000;
}

void Player::quit()
{
	quit_ = true;
}

bool Player::playerHasQuit() const
{
	return quit_;
}
