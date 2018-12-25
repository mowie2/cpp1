#pragma once

#include "Item.h"
#include "MyString.h"

class Inventory
{
public:
	Inventory();
	Inventory(int size);
	~Inventory();
	void add(MyString name, int amount);
	void remove(MyString name, int amount);
	//TODO: rule of 5 needs to be implemented
	// because we are using a deconstructor
private:
	Item* items_;
	int inventorySize = 0;
	void init();
};
