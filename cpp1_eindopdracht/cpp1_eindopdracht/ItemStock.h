#pragma once
#include "Item.h"
#include "Stock.h"

class ItemStock:public Stock<Item>
{
public:
	
	//CityStock() = default;
	ItemStock() : Stock() {};
	ItemStock(const Item& item) :Stock(item) {};
	/*
	Item& get_item();

	void set_quantities(const int min, const int max);
	int get_min_quantities() const;
	int get_max_quantities() const;

	void set_prices(const int min, const int max);
	int get_min_price() const;
	int get_max_price() const;
private:
	Item item_;
	int min_quantity_ = 0;
	int max_quantity_ = 0;
	int price_ = 0;
	int min_price_ = 0;
	int max_price_ = 0;*/
};

