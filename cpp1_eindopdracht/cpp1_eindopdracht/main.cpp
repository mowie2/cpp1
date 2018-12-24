// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "World.h"
#include <iostream>
#include "MyString.h"
#include "City.h"

void test(){
	std::cout << "Hello World!\n";
	World fr;
	//int k;
	//char * j;
	//fr.read(".\\Files\\afstanden tussen steden.csv",j,k);
	//std::cout << j;
	fr.load_city_distances();
	fr.load_item_stock();
	
	//delete &fr.get_city(0);
	auto c = City(MyString("yolo"));
	fr.get_city(0) = c;

	//fr.get_city(0).get_name();
	std::cout<<fr.get_city(5).get_name().GetString()<<std::endl;
	std::cout << fr.get_city(5).get_name().GetString() << std::endl;
	const char * k = new char(5);
	delete[] k;
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
