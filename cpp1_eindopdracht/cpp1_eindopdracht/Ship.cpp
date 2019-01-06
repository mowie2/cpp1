#include "pch.h"
#include "Ship.h"

Ship::Ship(const MyString & type, const int price, const int capacity, const int max_canons, const int hp, const MyString & misc)
{
	this->shipName_ = type;
	this->price_ = price;
	this->max_items_ = capacity;
	this->max_canons_ = max_canons;
	this->hp_ = hp;

	light_ = Canon("licht", 0, 2);
	mid_ = Canon("middelgroot", 0, 3);
	heavy_ = Canon("zwaar", 0, 6);
	this->characteristics_ = misc;
}

MyString Ship::get_type() const
{
	return shipName_;
}

int Ship::get_price() const
{
	return price_;
}

int Ship::get_max_items() const
{
	return max_items_;
}

int Ship::get_max_canons() const
{
	return max_canons_;
}

int Ship::get_hp() const
{
	return hp_;
}

MyString Ship::get_misc() const
{
	return characteristics_;
}

void Ship::takeDamage(const int damageAmount)
{
	hp_ -= damageAmount;

	if(hp_ < 0)
	{
		hp_ = 0;
	}
}

Canon Ship::getLightCanons() const
{
	return light_;
}

Canon Ship::getMidCanons() const
{
	return mid_;
}

Canon Ship::getHeavyCanons() const
{
	return heavy_;
}

int Ship::calculateFleeChance(const Ship & other) const
{
	if (characteristics_.contains("licht"))
	{
		if (other.characteristics_.contains("licht"))
		{
			return 50;
		}
		if (other.characteristics_.contains("log"))
		{
			return 75;
		}
		return 60;

	}
	if (characteristics_.contains("log"))
	{
		if (other.characteristics_.contains("licht"))
		{
			return 5;
		}
		if (other.characteristics_.contains("log"))
		{
			return 30;
		}
		return 15;
	}
	if (characteristics_.equals("")) {
		if (other.characteristics_.contains("licht"))
		{
			return 30;
		}
		if (other.characteristics_.contains("log"))
		{
			return 55;
		}
		return 40;
	}
	return 0;
}

int Ship::calculateDamage() const
{
	return light_.getDamage()+mid_.getDamage()+heavy_.getDamage();
}
