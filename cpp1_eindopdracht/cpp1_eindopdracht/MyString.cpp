#include "pch.h"
#include "MyString.h"
#include <exception>


MyString::MyString(const char *string) {
	length_ = strchr(string, '\0') - string;
	SetString(string, length_);
}

MyString::MyString(const char *string, const int length) {
	SetString(string, length);
}

MyString::~MyString() {
	delete[] string_;
}

MyString& MyString::operator=(const MyString & other) {
	if (this != &other) {
		SetString(other.string_, other.length_);
	}
	return *this;
}

MyString & MyString::operator=(MyString && other) {
	if (this != &other) {
		if (this->length_ > 0) {
			delete[] this->string_;
		}
		this->string_ = other.string_;
		this->length_ = other.length_;
		other.string_ = nullptr;
		other.length_ = 0;
	}
	return *this;
}

MyString::MyString(const MyString & other) {
	SetString(other.string_, other.length_);
}

MyString::MyString(MyString && other)
{
	if (this->length_ > 0) {
		delete[] this->string_;
	}
	this->string_ = other.string_;
	this->length_ = other.length_;
	other.string_ = nullptr;
	other.length_ = 0;
}

bool MyString::equals(const MyString & other) const
{
	if (this->length_ == other.length_)
	{
		for (int i = 0;i < length_;i++)
		{
			if (this->string_[i] != other.string_[i])
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
	if (this->length_ == other_length)
	{
		for (auto i = 0;i < length_;i++)
		{
			if (this->string_[i] != other[i])
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
	return atoi(string_);
}

char MyString::GetLetter(int index) const {
	if (index < length_ && index >= 0) {
		return string_[index];
	}
	throw std::out_of_range("out of range");
}

int MyString::get_occurrence(const char search) const
{
	auto count = 0;
	for (auto i = 0;i < length_;i++)
	{
		if (string_[i] == search)
		{
			count++;
		}
	}
	return count;
}

const char * MyString::GetString() const {
	return string_;
}

MyList<int> MyString::get_occurrence_index(const char search) const
{
	const auto count = get_occurrence(search);
	if (count > 0)
	{
		auto index = 0;
		MyList<int> indexes(count);
		for (auto i = 0;i < length_;i++)
		{
			if (string_[i] == search)
			{
				indexes[index] = i;
				index++;
			}
		}
		return indexes;
	}
	return MyList<int>();
}

MyString MyString::subset(const int start, const int end) const
{
	const auto check1 = start <= end;
	const auto check2 = start >= 0 && start <= length_;
	const auto check3 = end >= 0 && end <= length_;
	if (check1 && check2 && check3)
	{
		return MyString((string_ + start), (end - start));
	}
	throw std::out_of_range("out of range");
}

int MyString::GetLength() const {
	return length_;
}


void MyString::SetString(const char *string, int length) {
	if (length < 0) {
		throw std::exception("length may not be lower than 0");
	}
	if (this->length_ > 0) {
		delete[] this->string_;
	}
	this->length_ = length;
	this->string_ = new char[length + 1];
	memcpy(this->string_, string, length);
	this->string_[length] = '\0';
}

