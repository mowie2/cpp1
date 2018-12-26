#pragma once
#include "MyString.h"
#include "Item.h"

class  Ship
{
public:
	Ship() = default;
	Ship(const MyString & type, const int price, const int capacity, const int canons, const int hp, const MyString& misc);
	~Ship() = default;

	MyString get_type() const;
	int get_price() const;
	int get_storage_capacity() const;
	int get_canons() const;
	int get_hp() const;
	MyString get_misc() const;
	void takeDamage(const int damageAmount);
	MyList<Item> storage;
private:
	MyString type_;
	int price_ = 0;
	int storage_capacity_ = 0;
	int canons_ = 0;
	int hp_ = 0;
	MyString misc_;
};
