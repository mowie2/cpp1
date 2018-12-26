#pragma once
#include "Stock.h"
#include "Canon.h"

class CanonStock : public Stock<Canon>
{
public:
	CanonStock() : Stock() {};
	CanonStock(const Canon& canon) : Stock(canon) {};
	//CanonStock();
};

