#pragma once
#include "MyString.h"
#include "Item.h"

class  Ship
{
public:
	Ship() = default;
	Ship(const MyString & type, const int price, const int capacity, const int canons, const int hp, const MyString& misc);
	~Ship() = default;
	int getHealth();
private:
	MyString type_;
	int price_ = 0;
	int storage_capacity_ = 0;
	int canons_ = 0;
	int hp_ = 0;
	MyList<Item> storage_;
	MyString misc_;
};
