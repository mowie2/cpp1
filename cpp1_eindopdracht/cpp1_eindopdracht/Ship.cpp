#include "pch.h"
#include "Ship.h"

Ship::Ship(const MyString & type, const int price, const int capacity, const int max_canons, const int hp, const MyString & misc)
{
	this->shipNameSize = type;
	this->price_ = price;
	this->max_items_ = capacity;
	this->max_canons_ = max_canons;
	this->hp_ = hp;
	canons_ = MyList<Canon>(3);
	canons_[0] = Canon("licht",0,2);
	canons_[1] = Canon("middelgroot",0,3);
	canons_[2] = Canon("zwaar",0,6);
	this->charteristics_ = misc;
}

MyString Ship::get_type() const
{
	return shipNameSize;
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
	return charteristics_;
}

void Ship::takeDamage(const int damageAmount)
{
	hp_ -= damageAmount;

	if(hp_ < 0)
	{
		hp_ = 0;
	}
}
