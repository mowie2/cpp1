#pragma once
#include "Mystring.h"

class Item
{
public:
	Item() = default;
	Item(const Item&other);
	Item& operator=(const Item&other);
	Item(Item&&other);
	Item& operator=(Item&&other);

	void set_name(const MyString& name);
	MyString get_name() const;

	void set_quantities(const int min, const int max);
	int get_min_quantities() const;
	int get_max_quantities() const;

	void set_prices(const int min, const int max);
	int get_min_price() const;
	int get_max_price() const;

	void enter_city();
	~Item() = default;

private:
	MyString name_;
	int quantity_ = 0;
	int min_quantity_ = 0;
	int max_quantity_ = 0;
	int price_ = 0;
	int min_price_ = 0;
	int max_price_ = 0;
};
