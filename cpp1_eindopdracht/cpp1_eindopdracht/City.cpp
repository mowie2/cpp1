#include "pch.h"
#include "City.h"

City::~City()
{
	delete[] distances_;
	delete[] items_;
}

City::City(const City & other)
{
	this->city_name_ = other.city_name_;
	if(amount_distances_ > 0)
	{
		delete[] distances_;
	}
	
	amount_distances_ = other.amount_distances_;
	distances_ = new Distance[amount_distances_];
	for (auto d = 0;d < other.amount_distances_;d++)
	{
		distances_[d] = other.distances_[d];
	}

	if (amount_items_ > 0)
	{
		delete[] items_;
	}
	amount_items_ = other.amount_items_;
	items_ = new Item[amount_items_];
	for (auto i = 0;i < other.amount_items_;i++)
	{
		items_[i] = other.items_[i];
	}
}

City::City(City && other)
{
	this->city_name_ = std::move(other.city_name_);
	if (amount_distances_ > 0)
	{
		delete[] distances_;
	}
	this->distances_ = std::move(other.distances_);
	other.distances_ = nullptr;
	amount_distances_ = other.amount_distances_;

	if (amount_items_ > 0)
	{
		delete[] items_;
	}
	items_ = std::move(other.items_);
	other.items_ = nullptr;
	amount_items_ = other.amount_items_;
}

City & City::operator=(const City & other)
{
	if(this != &other)
	{
		this->city_name_ = other.city_name_;
		if (amount_distances_ > 0)
		{
			delete[] distances_;
		}
		amount_distances_ = other.amount_distances_;
		distances_ = new Distance[amount_distances_];
		for (auto i = 0;i < other.amount_distances_;i++)
		{
			distances_[i] = other.distances_[i];
		}

		if (amount_items_ > 0)
		{
			delete[] items_;
		}
		amount_items_ = other.amount_items_;
		items_ = new Item[amount_items_];
		for (auto i = 0;i < other.amount_items_;i++)
		{
			items_[i] = other.items_[i];
		}
	}
	return *this;
}

City & City::operator=(City && other)
{
	if (this != &other)
	{
		this->city_name_ = std::move(other.city_name_);
		if (amount_distances_ > 0)
		{
			delete[] distances_;
		}
		this->distances_ = std::move(other.distances_);
		other.distances_ = nullptr;
		amount_distances_ = other.amount_distances_;

		if (amount_items_ > 0)
		{
			delete[] items_;
		}
		items_ = std::move(other.items_);
		other.items_ = nullptr;
		amount_items_ = other.amount_items_;
	}
	return *this;
}



MyString City::get_name() const
{
	return city_name_;
}

void City::set_distance_count(const int count)
{
	if (amount_distances_ > 0)
	{
		delete[] distances_;
	}
	amount_distances_ = count;
	distances_ = new Distance[count];
}



void City::set_distance(const int index,const MyString name,const int distance)
{
	if (index >= 0 && index <= (amount_distances_ - 1)) {
		distances_[index].set_distance(name, distance);
	}
	else
	{
		throw std::out_of_range("out of range");
	}
}

Distance& City::get_distance_to(const int index) const
{
	if (index >= 0 && index <= (amount_distances_ - 1))
	{
		return distances_[index];
	}
	else
	{
		throw std::out_of_range("out of range");
	}
}

void City::set_items_count(const int count)
{
	if (amount_items_ > 0)
	{
		delete[] items_;
	}
	amount_items_ = count;
	items_ = new Item[count];
}

void City::set_item(const int index, const MyString name, const int min, const int max)
{
	if (index >= 0 && index <= (amount_items_ - 1)) {
		items_[index].set_name(name);
		items_[index].init_quantities(min,max);
	}
	else
	{
		throw std::out_of_range("out of range");
	}
}

Item& City::get_items(const int index) const
{
	if (index >= 0 && index <= (amount_items_ - 1))
	{
		return items_[index];
	}
	else
	{
		throw std::out_of_range("out of range");
	}
}
