#pragma once
#include "pch.h"
#include "MyList.h"
#include <iostream>

class MyString
{
public:
	MyString() = default;
	MyString(const char* string);
	MyString(const char* string, int length);
	~MyString();

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);
	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	MyString(const MyString& other);
	MyString(MyString&& other);

	bool equals(const MyString& other) const;
	bool equals(const char* other) const;
	bool contains(const MyString& other) const;
	bool contains(const char* other) const;

	int Parse();

	char get_letter(int index) const;
	int get_occurrence(char search) const;
	const char* GetString() const;

	MyList<int> get_occurrence_index(char search) const;
	MyString subset(int start, int end) const;
	int GetLength() const;
private:
	char* string_ = nullptr;
	int length_ = 0;
	void SetString(const char* string, int length);
};
