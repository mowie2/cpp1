#pragma once

template <typename T>
class Stock
{
public:
	Stock() = default;

	Stock(T item) { this->item_ = item; };

	T& get_item() { return item_; };

	void set_quantities(const int min, const int max)
	{
		min_quantity_ = min;
		max_quantity_ = max;
	}

	int get_min_quantities() const { return min_quantity_; }
	int get_max_quantities() const { return max_quantity_; }

	void set_prices(const int min, const int max)
	{
		min_price_ = min;
		max_price_ = max;
	}

	int get_Price() const { return price_; }

	void set_Price(int price) { price_ = price; }
	int get_min_price() const { return min_price_; }
	int get_max_price() const { return max_price_; }
private:
	T item_;
	int min_quantity_ = 0;
	int max_quantity_ = 0;
	int price_ = 0;
	int min_price_ = 0;
	int max_price_ = 0;
};
