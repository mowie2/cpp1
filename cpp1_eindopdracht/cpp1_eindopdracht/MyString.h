#pragma once
#include "pch.h"
#include <iostream>

class MyString
{
public:
	MyString() = default;
	MyString(const char *string);
	MyString(const char *string, int length);
	~MyString() = default;

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);
	MyString(const MyString& other);
	MyString(MyString&& other);

	int Parse();

	char GetLetter(int index) const;
	int GetLength() const;
private:
	char *string = '\0';
	int length;
	void SetString(const char* string, int length);
};

