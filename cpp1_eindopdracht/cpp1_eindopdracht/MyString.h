#pragma once
#include "pch.h"
#include "MyList.h"
#include <iostream>

class MyString
{
public:
	MyString() = default;
	MyString(const char *string);
	MyString(const char *string, int length);
	~MyString();

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);
	MyString(const MyString& other);
	MyString(MyString&& other);

	bool equals(const MyString&other) const;
	bool equals(const char* other) const;

	int Parse();

	char GetLetter(int index) const;
	int get_occurrence(const char search) const;
	const char * GetString() const;

	MyList<int> get_occurrence_index(const char search) const;
	MyString subset(const int start, const int end) const;
	int GetLength() const;
private:
	//todo nullptr
	char *string_ = '\0';
	int length_ = 0;
	void SetString(const char* string, int length);
};

