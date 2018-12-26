#include "pch.h"
#include "Item.h"

Item::Item(const Item & other)
{
	this->name_ = other.name_;
	this->quantity_ = other.quantity_;
	this->max_quantity_ = other.max_quantity_;
	this->min_quantity_ = other.min_quantity_;
}

Item & Item::operator=(const Item & other)
{
	if (this != &other) {
		this->name_ = other.name_;
		this->quantity_ = other.quantity_;
		this->max_quantity_ = other.max_quantity_;
		this->min_quantity_ = other.min_quantity_;
	}
	return *this;
}

Item::Item(Item && other)
{
	this->name_ = std::move(other.name_);
	this->quantity_ = other.quantity_;
	this->max_quantity_ = other.max_quantity_;
	this->min_quantity_ = other.min_quantity_;
}

Item & Item::operator=(Item && other)
{
	if (this != &other) {
		this->name_ = std::move(other.name_);
		this->quantity_ = other.quantity_;
		this->max_quantity_ = other.max_quantity_;
		this->min_quantity_ = other.min_quantity_;
	}
	return *this;
}

void Item::set_quantities(const int min, const int max)
{
	min_quantity_ = min;
	max_quantity_ = max;
}

void Item::set_prices(const int min, const int max)
{
	min_price_ = min;
	max_price_ = max;
}

int Item::get_min_price() const
{
	return min_price_;
}

int Item::get_max_price() const
{
	return max_price_;
}

void Item::set_name(const MyString & name)
{
	this->name_ = name;
}

MyString Item::get_name() const
{
	return name_;
}

int Item::get_min_quantities() const
{
	return min_quantity_;
}

int Item::get_max_quantities() const
{
	return max_quantity_;
}