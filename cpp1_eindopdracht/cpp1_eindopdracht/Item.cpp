#include "pch.h"
#include "Item.h"

Item::Item(const MyString & name)
{
	this->name_ = name;
}

Item::Item(const Item & other)
{
	this->name_ = other.name_;
	this->quantity_ = other.quantity_;
}

Item & Item::operator=(const Item & other)
{
	if (this != &other) {
		this->name_ = other.name_;
		this->quantity_ = other.quantity_;
	}
	return *this;
}

Item::Item(Item && other)
{
	this->name_ = std::move(other.name_);
	this->quantity_ = other.quantity_;
}

Item & Item::operator=(Item && other)
{
	if (this != &other) {
		this->name_ = std::move(other.name_);
		this->quantity_ = other.quantity_;
	}
	return *this;
}

MyString Item::get_name() const
{
	return name_;
}

