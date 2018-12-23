#include "pch.h"
#include "City.h"

City::City(const City & other)
{
	this->city_name_ = other.city_name_;
}

City::City(City && other)
{
	this->city_name_ = std::move(other.city_name_);
}

City & City::operator=(const City & other)
{
	if(this != &other)
	{
		this->city_name_ = other.city_name_;
	}
	return *this;
}

City & City::operator=(City && other)
{
	if (this != &other)
	{
		this->city_name_ = std::move(other.city_name_);
	}
	return *this;
}

MyString City::get_name() const
{
	return city_name_;
}
