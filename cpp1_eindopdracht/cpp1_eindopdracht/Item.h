#pragma once
#include "Mystring.h"

class Item
{
public:
	Item() = default;
	Item(const Item&other )
	{
		this->name_ = other.name_;
		this->quantity_ = other.quantity_;
		this->max_quantity_ = other.max_quantity_;
		this->min_quantity_ = other.min_quantity_;
	}
	Item& operator=(const Item&other)
	{
		if (this != &other) {
			this->name_ = other.name_;
			this->quantity_ = other.quantity_;
			this->max_quantity_ = other.max_quantity_;
			this->min_quantity_ = other.min_quantity_;
		}
		return *this;
	}

	Item(Item&&other)
	{
		this->name_ = std::move(other.name_);
		this->quantity_ = other.quantity_;
		this->max_quantity_ = other.max_quantity_;
		this->min_quantity_ = other.min_quantity_;
	}
	Item& operator=(Item&&other)
	{
		if (this != &other) {
			this->name_ = std::move(other.name_);
			this->quantity_ = other.quantity_;
			this->max_quantity_ = other.max_quantity_;
			this->min_quantity_ = other.min_quantity_;
		}
		return *this;
	}

	void init_quantities(int min,const int max)
	{
		quantity_ = 0;
		min_quantity_ = min;
		max_quantity_ = max;
	}

	void set_name(const MyString& name)
	{
		this->name_ = name;
	}

	MyString get_name() const { return name_; }

	//Item(const MyString name, int quantity) : name_(name), quantity_(quantity) {};
	~Item() = default;
private:
	MyString name_;
	int quantity_ = 0;
	int min_quantity_ = 0;
	int max_quantity_ = 0;
};
