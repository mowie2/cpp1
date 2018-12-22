#include "pch.h"
#include "World.h"
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <string>

World::World()
{
}


World::~World()
{
}

int World::searchParameters(const char *par)
{
	int count = strstr(par, "\r\n") - par;
	par += count;
	int k = 5;
	return 0;
}

int World::searchStringParameter(const char* par, const char * split)
{
	int count = strstr(par, split) - par;
	MyString parameter(par, count);
	par += count;
	return 0;
}

int World::load_cities(const char* par)
{
	int offset = 0;
	while(*(par + offset) != '\0'&& *(par + offset) != ';')
	{
		offset++;
	}
	
	while(*(par+offset)!='\0'&& *(par + offset)!= '\n')
	{
		if(*(par + offset) == ';')
		{
			count_cities++;
		}
		offset++;
	}

	if (count_cities > 0) {
		cities = new City[count_cities];
	}

	return 0;
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
		searchParameters((buffer+ offset));
		load_cities(buffer);

		is.close();
		delete[] buffer;
		_CrtDumpMemoryLeaks();
	}
}

