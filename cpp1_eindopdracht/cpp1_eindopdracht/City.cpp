#include "pch.h"
#include "City.h"


City::City(const MyString& name)
{
	this->city_name_ = name;
	canons_ = MyList<CanonStock>(3);
	canons_[0] = CanonStock(Canon("licht", 0, 2));
	canons_[1] = CanonStock(Canon("middelgroot", 0, 3));
	canons_[2] = CanonStock(Canon("zwaar", 0, 6));
}

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
