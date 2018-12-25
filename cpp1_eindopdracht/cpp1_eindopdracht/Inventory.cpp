#include "pch.h"

#include "Inventory.h"


Inventory::Inventory(int size)
{
	items_ = new Item[size];
	inventorySize = size;
	init();
}

Inventory::~Inventory()
{
	delete[] items_;
}

void Inventory::add(MyString name, int amount)
{
	
	for (int x = 0; x < inventorySize; x++)
	{
		if(items_[x].itemName == name)
		{
			items_[x].itemAmount += amount;
		}
	}
	
}

void Inventory::remove(MyString name, int amount)
{
	for (int x = 0; x < inventorySize; x++)
	{
		if (items_[x].itemName == name)
		{
			items_[x].itemAmount -= amount;

			if(items_[x].itemAmount <= 0)
			{
				items_[x].itemAmount = 0;
			}
		}
	}
}

void Inventory::init()
{
	//TODO: dymaische maken
	items_[0] = Item("bakstenen", 0, 0, 0);
	items_[1] = Item("laken", 0, 0, 0);
	items_[2] = Item("cacao", 0, 0, 0);
	items_[3] = Item("katoen", 0, 0, 0);
	items_[4] = Item("verfstof", 0, 0, 0);
	items_[5] = Item("vis", 0, 0, 0);
	items_[6] = Item("hennep", 0, 0, 0);
	items_[7] = Item("aardapples", 0, 0, 0);
	items_[8] = Item("rum", 0, 0, 0);
	items_[9] = Item("zout", 0, 0, 0);
	items_[10] = Item("suiker", 0, 0, 0);
	items_[11] = Item("tabak", 0, 0, 0);
	items_[12] = Item("graan", 0, 0, 0);
	items_[13] = Item("vlees", 0, 0, 0);
	items_[14] = Item("hout", 0, 0, 0);
}
