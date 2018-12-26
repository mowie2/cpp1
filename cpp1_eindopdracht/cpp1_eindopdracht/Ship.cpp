#include "pch.h"
#include "Ship.h"

Ship::Ship(const MyString & type, const int price, const int capacity, const int canons, const int hp, const MyString & misc)
{
	this->type_ = type;
	this->price_ = price;
	this->storage_capacity_ = capacity;
	this->canons_ = canons;
	this->hp_ = hp;
	this->misc_ = misc;
}

int Ship::getHealth()
{
	return hp_;
}
