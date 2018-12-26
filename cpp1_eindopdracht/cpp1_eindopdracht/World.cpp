#include "pch.h"
#include "World.h"
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <string>
#include "City.h"
#include "File.h"

World::World()
{
}

World::~World()
{
	//delete[] cities_;
	//delete[] ships_;
}

//TODO : loading csv files is not exception safe

int World::city_index(const char * name)
{
	for (auto i = 0; i < count_cities_;i++)
	{
		if (cities_[i].get_name().equals(name))
		{
			return i;
		}
	}
	return -1;
}

int World::city_index(const MyString & name)
{
	return city_index(name.GetString());
}

City & World::get_city(const int index)
{
	if (index >= 0 && index <= count_cities_ - 1)
	{
		return cities_[index];
	}
	else
	{
		throw std::out_of_range("out of range");
	}
}

void World::load_cities(MyList<MyString>& cities)
{
	cities_ = MyList<City>(cities.get_size() - 1);
	for (auto c = 0; c < cities.get_size() - 1;c++)
	{
		cities_[c].set_name(cities[c + 1]);
		std::cout << cities_[c].get_name().GetString() << std::endl;
	}
}


bool World::load_city_distances(MyList<MyList<MyString>> data)
{
	for (auto r = 1;r < data.get_size();r++)
	{
		cities_[r - 1].distances = MyList<Distance>(data[0].get_size());
		for (auto c = 0;c < data[r].get_size();c++)
		{
			cities_[r - 1].distances[c] = Distance(data[0][c], data[r][c].Parse());
			std::cout << cities_[r - 1].distances[c].get_name().GetString() << std::endl;
			std::cout << cities_[r - 1].distances[c].get_distance() << std::endl;
		}
	}
	return true;
}

void World::load_items(MyList<MyString>& items)
{
	if (cities_.get_size() == 0) {
		std::cout << "there are no cities" << std::endl;
	}
	else {
		for (auto c = 0;c < cities_.get_size();c++) {
			cities_[c].items = MyList<Item>(items.get_size());
			for (auto i = 1;i < items.get_size();i++)
			{
				cities_[c].items[i].set_name(items[i]);
				std::cout << cities_[c].items[i].get_name().GetString() << std::endl;
			}
		}
	}
}

bool World::load_item_amount(MyList<MyList<MyString>> data)
{
	for (auto r = 1;r < data.get_size();r++)
	{
		for (auto c = 1;c < data[r].get_size();c++)
		{
			auto index = data[r][c].get_occurrence_index('-');
			if (index.get_size() != 1)
			{
				std::cout << "no - sign found" << std::endl;
				return false;
			}
			const auto min = data[r][c].subset(0, index[0]).Parse();
			const auto max = data[r][c].subset(index[0] + 1, data[r][c].GetLength()).Parse();
			cities_[r - 1].items[c].set_quantities(min, max);
			std::cout << cities_[r - 1].items[c].get_min_quantities() << std::endl;
			std::cout << cities_[r - 1].items[c].get_max_quantities() << std::endl;
		}
	}
	return true;
}

bool World::load_item_price(MyList<MyList<MyString>> data)
{
	for (auto r = 1;r < data.get_size();r++)
	{
		for (auto c = 1;c < data[r].get_size();c++)
		{
			auto index = data[r][c].get_occurrence_index('-');
			if (index.get_size() != 1)
			{
				std::cout << "no - sign found" << std::endl;
				return false;
			}
			const auto min = data[r][c].subset(0, index[0]).Parse();
			const auto max = data[r][c].subset(index[0] + 1, data[r][c].GetLength()).Parse();
			cities_[r - 1].items[c].set_prices(min, max);
			std::cout << cities_[r - 1].items[c].get_min_price() << std::endl;
			std::cout << cities_[r - 1].items[c].get_max_price() << std::endl;
		}
	}
	return true;
}

void World::load_ships(MyList<MyList<MyString>> data)
{
	ships_ = MyList<Ship>(data.get_size());
	for (auto r = 1;r < data.get_size();r++)
	{
		ships_[r - 1] = Ship(
			data[r][0], 
			data[r][1].Parse(), 
			data[r][2].Parse(), 
			data[r][3].Parse(), 
			data[r][4].Parse(), 
			data[r][5]
		);
	}
}

bool World::read()
{
	//check if files are loaded
	File city_distance;
	const auto d = city_distance.init(".\\Files\\afstanden tussen steden.csv");
	File item_amount;
	const auto a = item_amount.init(".\\Files\\goederen hoeveelheid.csv");
	File item_price;
	const auto p = item_price.init(".\\Files\\goederen prijzen.csv");
	File ships;
	const auto s = ships.init(".\\Files\\schepen.csv");
	if (!d || !a || !p || !s)
	{
		std::cout << "not all files could be read" << std::endl;
		return false;
	}

	//checks amount cities are correct; 
	const auto check1 = city_distance.file[0].get_size() == city_distance.file.get_size();
	const auto check2 = city_distance.file.get_size() == item_amount.file.get_size() && city_distance.file.get_size() == item_price.file.get_size();

	//check amount items are correct;
	const auto check3 = item_amount.file[0].get_size() == item_price.file[0].get_size();

	//check if all parameters are available in file ships
	const auto check4 = ships.file[0].get_size() == 6;

	if (check1 && check2 && check3 && check4) {
		load_ships(ships.file);

		load_cities(city_distance.file[0]);
		load_city_distances(city_distance.file);
		load_items(item_amount.file[0]);

		load_item_amount(item_amount.file);
		load_item_price(item_price.file);

	}
	else
	{
		std::cout << "files do not follow same format" << std::endl;
		return false;
	}
	return true;
}