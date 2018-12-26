#pragma once
#include "MyString.h"

class Canon
{
public:
	Canon();
	Canon(const MyString& type,const int min, const int max);
	~Canon();
private:
	MyString type_;
	int damage_ = 0;
	int min_damage_ = 0;
	int max_damage_ = 0;
};

