#include "pch.h"
#include "World.h"
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <string>
#include "City.h"

World::World()
{
}


World::~World()
{
	delete[] cities_;
}

int World::search_parameters(const char *par)
{
	int count = strstr(par, "\r\n") - par;
	par += count;
	int k = 5;
	return 0;
}

int World::search_string_parameter(const char* par, const char * split)
{
	int count = strstr(par, split) - par;
	MyString parameter(par, count);
	par += count;
	return 0;
}

void World::load_cities(const char* par)
{


	auto initial_offset = 0;
	while(*(par + initial_offset) != '\0'&& *(par + initial_offset) != ';')
	{
		initial_offset++;
	}

	auto parameter_offset = initial_offset;
	while(*(par+ parameter_offset)!='\0'&& *(par + parameter_offset)!= '\n')
	{
		if(*(par + parameter_offset) == ';')
		{
			count_cities_++;
		}
		parameter_offset++;
	}

	auto search_offset = 1+initial_offset;
	if (count_cities_ > 0) {
		cities_ = new City[count_cities_];
		for(auto i = 0;i<count_cities_-1;i++)
		{
			auto test = par + search_offset;
			const auto new_offset = strstr((par + search_offset), ";") - (par + search_offset);
			cities_[i] = std::move(City(std::move(MyString(par + search_offset, new_offset))));
			search_offset += (new_offset + 1);
		}
		const auto new_offset = strstr((par + search_offset), "\r\n") - (par + search_offset);
		cities_[count_cities_-1] = std::move(City(std::move(MyString(par + search_offset, new_offset))));
		search_offset += (new_offset + 1);
	}
}


void World::read(const char *filepath)
{
	std::ifstream is(filepath, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is)
			std::cout << "all characters read successfully.";
		else
			std::cout << "error: only " << is.gcount() << " could be read";


		// ...buffer contains the entire file...

		int offset = 0;

		while (*(buffer+offset) != ';') {
			offset++;
		}
		search_parameters((buffer+ offset));
		load_cities(buffer);

		is.close();
		delete[] buffer;

	}
}

