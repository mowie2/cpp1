// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "World.h"
#include <iostream>
#include "MyString.h"
#include "file.h"

void test() {
	std::cout << "Hello World!\n";
	World fr;
	//int k;
	//char * j;
	//fr.read(".\\Files\\afstanden tussen steden.csv",j,k);
	//std::cout << j;
	//fr.load_city_distances();
	//fr.load_item_stock();
	//fr.load_item_prices();
	//fr.load_ships();
	//auto k = fr.ships_[0];
	//int h = std::atoi("");
	//int vv = 0;
	File f;
	MyString kaka(";;;j;;");
	auto count = kaka.get_occurrence_index('j');
	;

	for (int i = 0;i < count.get_size();i++)
	{
		std::cout << count[i];
		std::cout << kaka.subset(0, 6).GetString();
	}
	fr.read();
	auto& test = fr.ships_[0];
	//f.init(".\\Files\\afstanden tussen steden.csv");
}

int main()
{
	test();
	_CrtDumpMemoryLeaks();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
