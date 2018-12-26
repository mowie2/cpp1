#include "pch.h"
#include "Ship.h"

Ship::Ship(const MyString & type, const int price, const int capacity, const int canons, const int hp, const MyString & misc)
{
	this->size_ = type;
	this->price_ = price;
	this->storage_capacity_ = capacity;
	this->canons_ = canons;
	this->hp_ = hp;
	this->charteristics_ = misc;
}

MyString Ship::get_type() const
{
	return size_;
}

int Ship::get_price() const
{
	return price_;
}

int Ship::get_storage_capacity() const
{
	return storage_capacity_;
}

int Ship::get_canons() const
{
	return canons_;
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
