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

	void init_quantities(const int min, const int max);

	void set_prices(const int min, const int max);

	void set_name(const MyString& name);

	MyString get_name() const { return name_; }

	//Item(const MyString name, int quantity) : name_(name), quantity_(quantity) {};
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
