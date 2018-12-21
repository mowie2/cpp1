#pragma once
#include "Mystring.h"

class Item
{
public:
	Item(const MyString name, const int itemsize, int quantity) : name_(name), itemSize_(itemsize), quantity_(quantity) {};
	~Item() = default;
private:
	const MyString name_;
	const int itemSize_;
	int quantity_;
};
