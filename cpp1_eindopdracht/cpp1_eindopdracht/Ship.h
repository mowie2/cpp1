#pragma once
#include "MyString.h"
#include "Item.h"
#include "Canon.h"

class  Ship
{
public:
	Ship() = default;
	Ship(const MyString & type, const int price, const int capacity, const int max_canons, const int hp, const MyString& misc);
	~Ship() = default;

	MyString get_type() const;
	int get_price() const;
	int get_max_items() const;
	int get_max_canons() const;
	int get_hp() const;
	MyString get_misc() const;
	void takeDamage(const int damageAmount);
	MyList<Item> storage;
private:
	MyString size_;
	int price_ = 0;
	int max_items_ = 0;
	int max_canons_ = 0;
	int hp_ = 0;
	MyString charteristics_;
	MyList<Canon> canons_;
};
