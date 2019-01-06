#pragma once
#include "MyString.h"

class Canon
{
public:
	Canon();
	Canon(const MyString& type,const int min, const int max);
	~Canon();

	MyString getType() const { return type_; }
	int getDamage() const;
	int getQuantity() const { return quantity_; }
	void add(int amount);
	bool remove(int amount);

private:
	MyString type_;
	int damage_ = 0;
	int min_damage_ = 0;
	int max_damage_ = 0;
	int quantity_ = 0;
};

