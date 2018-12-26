#include "pch.h"
#include "CityStock.h"

CityStock::CityStock(Item item)
{
	this->item_ = item;
}

Item CityStock::get_item() const
{
	return item_;
}

void CityStock::set_quantities(const int min, const int max)
{
	min_quantity_ = min;
	max_quantity_ = max;
}

int CityStock::get_min_quantities() const
{
	return min_quantity_;
}

int CityStock::get_max_quantities() const
{
	return max_quantity_;
}

void CityStock::set_prices(const int min, const int max)
{
	min_price_ = min;
	max_price_ = max;
}

int CityStock::get_min_price() const
{
	return min_price_;
}

int CityStock::get_max_price() const
{
	return max_price_;
}
