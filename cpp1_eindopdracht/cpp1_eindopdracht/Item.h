#pragma once
#include "Mystring.h"

class Item
{
public:
	Item() = default;

	Item(const MyString& name);

	Item(const Item&other);
	Item& operator=(const Item&other);
	Item(Item&&other);
	Item& operator=(Item&&other);

	MyString get_name() const;

	void set_quantity(const int quantity);
	int get_quantity() const;

	~Item() = default;
private:
	MyString name_;
	int quantity_ = 0;
};
