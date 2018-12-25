#include "pch.h"
#include "MyString.h"
#include <exception>

MyString::MyString() {
}

MyString::MyString(const char *string) {
	length = strchr(string, '\0') - string;
	SetString(string, length);
}

MyString::MyString(const char *string, int length) {
	if (length > 0) {
		SetString(string, length);
	}
}

MyString::~MyString() {
	
	delete[] string;
}

MyString& MyString::operator=(const MyString & other) {
	if (this != &other) {
		SetString(other.string, other.length);
	}
	return *this;
}

MyString & MyString::operator=(MyString && other) {
	if (this != &other) {
		delete[] this->string;
		this->string = other.string;
		this->length = other.length;
		other.string = nullptr;
		other.length = 0;
	}
	return *this;
}

bool MyString::operator==(const MyString & other)
{
	int counter = 0;
	for (char *inputPtr = other.string; *inputPtr; ++inputPtr)
	{
		if(*inputPtr != string[counter])
		{
			return false;
		}
		counter++;
	}
	return true;
}

MyString::MyString(const MyString & other)
{
	length = strchr(other.string, '\0') - other.string;
	SetString(other.string, length);
}


MyString::MyString(MyString && other)
{
	this->string = other.string;
	this->length = other.length;
	other.string = nullptr;
	other.length = 0;
}

int MyString::Parse()
{
	return atoi(string);
}


char MyString::GetLetter(int index) const {
	if (index < length && index >= 0) {
		return string[index];
	}
	throw std::out_of_range("out of range");
}

int MyString::GetLength() const {
	return length;
}


void MyString::SetString(const char *string, int length) {
	if (this->length > 0) {
		delete[] this->string;
	}
	this->length = length;
	this->string = new char[length + 1];
	memcpy(this->string, string, length);
	this->string[length] = '\0';
}

