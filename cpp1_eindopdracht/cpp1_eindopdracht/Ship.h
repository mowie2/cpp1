#pragma once
#include "MyString.h"

class  Ship
{
public:
	Ship() = default;
	~Ship() = default;
	void set_type(const MyString & type)
	{
		this->type_ = type;
	}
	void set_price(const int price)
	{
		this->price_ = price;
	}
	void set_storage_capacity(const int capacity)
	{
		this->storage_capacity_ = capacity;
	}
	void set_canons(const int canons)
	{
		this->canons_ = canons;
	}
	void set_hp(const int hp)
	{
		this->hp_ = hp;
	}
	void set_misc(const MyString& misc)
	{
		this->misc_ = misc;
	}

private:
	MyString type_;
	int price_ = 0;
	int storage_capacity_ = 0;
	int canons_ = 0;
	int hp_ = 0;
	MyString misc_;
};