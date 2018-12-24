#include "pch.h"
#include "MyString.h"
#include <exception>


MyString::MyString(const char *string) {
	if (this->length > 0) {
		delete[] this->string;
	}
	length = strchr(string, '\0') - string;
	SetString(string, length);
}

MyString::MyString(const char *string, int length) {
	if (this->length > 0) {
		delete[] this->string;
	}
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
		if (this->length > 0) {
			delete[] this->string;
		}
		this->string = other.string;
		this->length = other.length;
		other.string = nullptr;
		other.length = 0;
	}
	return *this;
}

MyString::MyString(const MyString & other) {
	//ToDo::nullPointer
	if (this->length > 0) {
		delete[] this->string;
	}
	SetString(other.string, other.length);
}

MyString::MyString(MyString && other)
{
	if (this->length > 0) {
		delete[] this->string;
	}
	this->string = other.string;
	this->length = other.length;
	other.string = nullptr;
	other.length = 0;
}

bool MyString::equals(const MyString & other) const
{
	if(this->length == other.length)
	{
		for(int i = 0;i<length;i++)
		{
			if(this->string[i] != other.string[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool MyString::equals(const char * other) const
{
	const int other_length = strchr(other, '\0') - other;
	if (this->length == other_length)
	{
		for (auto i = 0;i < length;i++)
		{
			if (this->string[i] != other[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
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

const char * MyString::GetString() const {
	return string;
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

