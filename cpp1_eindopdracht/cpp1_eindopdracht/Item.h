#pragma once
#include "Mystring.h"

class Item
{
public:
	Item() = default;
	Item(MyString itemName_, int itemQuantity_, int itemSize_, int itemPrice_) 
	: itemName(itemName_), itemSize(itemSize_), itemAmount(itemQuantity_), itemPrice(itemPrice_) {};
	~Item() = default;
	MyString itemName;
	int itemSize;
	int itemAmount;
	int itemPrice;
private:

};
