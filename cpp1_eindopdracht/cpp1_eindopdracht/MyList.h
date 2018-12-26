#pragma once
#include <exception>

template<typename T>
class MyList
{
public:
	MyList()
	{
	}

	MyList(int size)
	{
		if (size < 0) {
			throw std::exception("size may not be lower than 0");
		}
		this->size_ = size;
		this->list_ = new T[size];
	}

	MyList(const MyList & other)
	{
		if (size_ > 0)
		{
			delete[] list_;
		}
		size_ = other.size_;
		list_ = new T[size_];
		for (auto element = 0;element < size_;element++)
		{
			list_[element] = other.list_[element];
		}
	}

	MyList(MyList && other)
	{
		if (size_ > 0)
		{
			delete[] list_;
		}
		list_ = std::move(other.list_);
		other.list_ = nullptr;
		size_ = other.size_;
		other.size_ = 0;
	}

	MyList & operator=(const MyList & other)
	{
		if (this != &other)
		{
			if (size_ > 0)
			{
				delete[] list_;
			}
			size_ = other.size_;
			list_ = new T[size_];
			for (auto element = 0;element < size_;element++)
			{
				list_[element] = other.list_[element];
			}
		}
		return *this;
	}

	MyList & operator=(MyList && other)
	{
		if (this != &other)
		{
			if (size_ > 0)
			{
				delete[] list_;
			}
			list_ = std::move(other.list_);
			other.list_ = nullptr;
			size_ = other.size_;
			other.size_ = 0;
		}
		return *this;
	}

	~MyList() {
		delete[] list_;
	}

	T& operator[](const int index)
	{
		if (index >= 0 && index < size_)
		{
			return list_[index];
		}
		throw std::out_of_range("out of range");
	}

	int get_size() const
	{
		return size_;
	}


private:
	int size_ = 0;
	T* list_ = nullptr;
};

