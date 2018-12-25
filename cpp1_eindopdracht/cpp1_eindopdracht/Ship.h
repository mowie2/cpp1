#pragma once
#include "Inventory.h"

class  Ship
{
public:
	Ship() = default;
	~Ship() = default;
private:
	Inventory inventory_;
};
