#include "pch.h"
#include "City.h"
#include "Player.h"

/*
City::~City()
{
}

City::City(const City & other)
{
	this->city_name = other.city_name;
	this->distances = other.distances;
	this->items = other.items;
}

City::City(City && other)
{
	this->city_name = std::move(other.city_name);
	this->distances = std::move(other.distances);
	this->items = std::move(other.items);
}

City & City::operator=(const City & other)
{
	if(this != &other)
	{
		this->city_name = other.city_name;
		this->distances = other.distances;
		this->items = other.items;
	}
	return *this;
}

City & City::operator=(City && other)
{
	if (this != &other)
	{
		this->city_name = std::move(other.city_name);
		this->distances = std::move(other.distances);
		this->items = std::move(other.items);
	}
	return *this;
}*/

void City::set_name(const MyString& name)
{
	this->city_name_ = name;
}

MyString City::get_name() const
{
	return city_name_;
}

void City::buyShip(Player& p)
{
	p.playerShip = Ship(
		"light", 100, 200, 6, 1000, "geen"
	);
}
