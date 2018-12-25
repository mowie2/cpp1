#include "pch.h"
#include "World.h"
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <string>
#include "City.h"

World::World()
{
}

World::~World()
{
	delete[] cities_;
	delete[] ships_;
}

//TODO : loading csv files is not exception safe


void World::load_city_distances()
{
	std::ifstream is(".\\Files\\afstanden tussen steden.csv", std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		const int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is) {
			std::cout << "all characters read successfully." << std::endl;

			auto initial_offset = 0;


			while (initial_offset != length && *(buffer + initial_offset) != '\n')
			{
				const auto new_offset = strchr(buffer+initial_offset,'#')-(buffer + initial_offset);
				if (new_offset > 0) {
					initial_offset += new_offset;
				}
				initial_offset++;
			}

			//count amount of cities
			auto parameter_offset = initial_offset+1;
			while (parameter_offset != length && *(buffer + parameter_offset) != '\n')
			{
				if (*(buffer + parameter_offset) == ';')
				{
					count_cities_++;
				}
				parameter_offset++;
			}

			//check if file is in right format
			auto good = true;
			auto count_rows = 0;
			auto count_col = 0;
			parameter_offset++;
			while (parameter_offset != length)
			{
				if (*(buffer + parameter_offset) == ';')
				{
					count_col++;
				}
				if (*(buffer + parameter_offset) == '\n')
				{
					if(count_col!=count_cities_)
					{
						good = false;
						break;
					}
					count_rows++;
					count_col = 0;
				}
				parameter_offset++;
			}

			//if file is in right format
			if (good && count_rows == count_cities_) {
				auto search_offset = 2 + initial_offset;
				if (count_cities_ > 0) {
					//read city name
					cities_ = new City[count_cities_];
					for (auto i = 0;i < count_cities_ - 1;i++)
					{
						const auto new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
						City temp(std::move(MyString(buffer + search_offset, new_offset)));
						temp.set_distance_count(count_cities_);
						cities_[i] = std::move(temp);
						search_offset += (new_offset + 1);
					}
					const auto last_city = strstr((buffer + search_offset), "\r\n") - (buffer + search_offset);

					City temp(std::move(MyString(buffer + search_offset, last_city)));
					temp.set_distance_count(count_cities_);
					cities_[count_cities_ - 1] = std::move(temp);
					search_offset += (last_city + 2);
					

					//read distance
					for (auto current_index = 0;current_index < (count_cities_ - 1);current_index++) {

						auto &current_city = cities_[current_index];
						//skip name
						search_offset += strstr((buffer + search_offset), ";") - (buffer + search_offset) + 1;
						for (auto i = 0;i < count_cities_ - 1;i++)
						{
							const auto new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
							current_city.set_distance(i, cities_[i].get_name(), MyString(buffer + search_offset, new_offset).Parse());
							std::cout << current_city.get_distance_to(i).get_name().GetString() << std::endl;
							search_offset += (new_offset + 1);
						}
						const auto last_par = strstr((buffer + search_offset), "\r\n") - (buffer + search_offset);
						current_city.set_distance(count_cities_ - 1, cities_[count_cities_ - 1].get_name(), MyString(buffer + search_offset, last_par).Parse());
						search_offset += (last_par + 1);
					}
					auto &current_city = cities_[count_cities_ - 1];
					const auto last_par = length - search_offset;
					current_city.set_distance(count_cities_ - 1, cities_[count_cities_ - 1].get_name(), MyString(buffer + search_offset, last_par).Parse());
					std::cout << current_city.get_distance_to(count_cities_ - 1).get_name().GetString() << std::endl;
					std::cout << current_city.get_distance_to(count_cities_ - 1).get_distance() << std::endl;
				}
				else
				{
					std::cout << "file is not in right format";
				}
			}
		}
		else {
			std::cout << "error: only " << is.gcount() << " could be read" << std::endl;
		}
		
		// ...buffer contains the entire file...
		is.close();
		delete[] buffer;
	}
}

void World::load_item_stock()
{
	std::ifstream is(".\\Files\\goederen hoeveelheid.csv", std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		const int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is) {
			std::cout << "all characters read successfully." << std::endl;

			auto initial_offset = 0;


			while (initial_offset != length && *(buffer + initial_offset) != '\n')
			{
				const auto new_offset = strchr(buffer + initial_offset, '#') - (buffer + initial_offset);
				if (new_offset > 0) {
					initial_offset += new_offset;
				}
				initial_offset++;
			}

			//count amount of items
			auto count_items = 0;
			auto parameter_offset = initial_offset + 1;
			while (parameter_offset != length && *(buffer + parameter_offset) != '\n')
			{
				auto k = buffer + parameter_offset;
				if (*(buffer + parameter_offset) == ';')
				{
					count_items++;
				}
				parameter_offset++;
			}

			//check if file is in right format
			auto good = true;
			auto count_rows = 0;
			auto count_col = 0;
			parameter_offset++;
			while (parameter_offset != length)
			{
				if (*(buffer + parameter_offset) == ';')
				{
					count_col++;
				}
				if (*(buffer + parameter_offset) == '\n')
				{
					if (count_col != count_items)
					{
						good = false;
						break;
					}
					count_rows++;
					count_col = 0;
				}
				parameter_offset++;
			}

			//if file is in right format
			if (good && count_rows == count_cities_) {
				auto search_offset = 2 + initial_offset;
				if (count_items > 0) {

					for (auto c = 0;c < count_cities_;c++) {
						auto&current_city = cities_[c];
						current_city.set_items_count(count_items);
					}

					for (auto i = 0;i < count_items - 1;i++)
					{
						const auto new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
						Item item;
						item.set_name(MyString(buffer + search_offset, new_offset));
						for (auto c = 0;c < count_cities_;c++)
						{
							cities_[c].get_items(i) = item;
							std::cout << cities_[c].get_items(i).get_name().GetString()<<std::endl;
						}
						search_offset += (new_offset + 1);
					}
					const auto last_item = strstr((buffer + search_offset), "\r\n") - (buffer + search_offset);
					Item item;
					item.set_name(MyString(buffer + search_offset, last_item));
					for (auto c = 0;c < count_cities_;c++)
					{
						cities_[c].get_items(count_items-1) = item;
						std::cout << cities_[c].get_items(count_items - 1).get_name().GetString() << std::endl;
					}
					search_offset += (last_item + 2);

					
					//read stock
					for (auto current_index = 0;current_index < (count_cities_ - 1);current_index++) {
						auto k = buffer + search_offset;
						auto &current_city = cities_[current_index];
						//skip name
						search_offset += strstr((buffer + search_offset), ";") - (buffer + search_offset) + 1;
						k = buffer + search_offset;
						for (auto i = 0;i < count_items - 1;i++)
						{
							k = buffer + search_offset;
							auto new_offset = strstr((buffer + search_offset), "-") - (buffer + search_offset);
							const auto min = MyString(buffer + search_offset, new_offset).Parse();
							search_offset += (new_offset + 1);
							
							new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
							const auto max = MyString(buffer + search_offset, new_offset).Parse();
							current_city.get_items(i).init_quantities(min, max);
							search_offset += (new_offset + 1);
						}
						k = buffer + search_offset;
						auto last_par = strstr((buffer + search_offset), "-") - (buffer + search_offset);
						const auto min = MyString(buffer + search_offset, last_par).Parse();
						search_offset += (last_par + 1);

						last_par = strstr((buffer + search_offset), "\r\n") - (buffer + search_offset);
						const auto max = MyString(buffer + search_offset, last_par).Parse();
						current_city.get_items(count_items-1).init_quantities(min, max);
						search_offset += (last_par + 1);
					}
					
					auto &current_city = cities_[count_cities_ - 1];
					for (auto i = 0;i < count_items - 1;i++)
					{
						auto new_offset = strstr((buffer + search_offset), "-") - (buffer + search_offset);
						const auto min = MyString(buffer + search_offset, new_offset).Parse();
						search_offset += (new_offset + 1);

						new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
						const auto max = MyString(buffer + search_offset, new_offset).Parse();
						current_city.get_items(i).init_quantities(min, max);
						search_offset += (new_offset + 1);
					}
					auto last_par = strstr((buffer + search_offset), "-") - (buffer + search_offset);
					const auto min = MyString(buffer + search_offset, last_par).Parse();
					search_offset += (last_par + 1);

					last_par = length - search_offset;
					const auto max = MyString(buffer + search_offset, last_par).Parse();
					current_city.get_items(count_items - 1).init_quantities(min, max);
				}
			}
			else
			{
				std::cout << "file is not in right format";
			}
			
		}
		else {
			std::cout << "error: only " << is.gcount() << " could be read" << std::endl;
		}

		// ...buffer contains the entire file...
		is.close();
		delete[] buffer;
	}
}

void World::load_item_prices()
{
	std::ifstream is(".\\Files\\goederen prijzen.csv", std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		const int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is) {
			std::cout << "all characters read successfully." << std::endl;

			auto initial_offset = 0;


			while (initial_offset != length && *(buffer + initial_offset) != '\n')
			{
				const auto new_offset = strchr(buffer + initial_offset, '#') - (buffer + initial_offset);
				if (new_offset > 0) {
					initial_offset += new_offset;
				}
				initial_offset++;
			}

			//count amount of items
			auto count_items = 0;
			auto parameter_offset = initial_offset + 1;
			while (parameter_offset != length && *(buffer + parameter_offset) != '\n')
			{
				if (*(buffer + parameter_offset) == ';')
				{
					count_items++;
				}
				parameter_offset++;
			}

			//check if file is in right format
			auto good = true;
			auto count_rows = 0;
			auto count_col = 0;
			parameter_offset++;
			while (parameter_offset != length)
			{
				if (*(buffer + parameter_offset) == ';')
				{
					count_col++;
				}
				if (*(buffer + parameter_offset) == '\n')
				{
					if (count_col != count_items)
					{
						good = false;
						break;
					}
					count_rows++;
					count_col = 0;
				}
				parameter_offset++;
			}

			//if file is in right format
			if (good && count_rows == count_cities_) {
				auto search_offset = 2 + initial_offset;
				if (count_items > 0) {

					//read stock
					for (auto current_index = 0;current_index < (count_cities_ - 1);current_index++) {

						auto &current_city = cities_[current_index];
						//skip name
						search_offset += strstr((buffer + search_offset), ";") - (buffer + search_offset) + 1;
						for (auto i = 0;i < count_items - 1;i++)
						{
							auto new_offset = strstr((buffer + search_offset), "-") - (buffer + search_offset);
							const auto min = MyString(buffer + search_offset, new_offset).Parse();
							search_offset += (new_offset + 1);

							new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
							const auto max = MyString(buffer + search_offset, new_offset).Parse();
							current_city.get_items(i).set_prices(min, max);
							search_offset += (new_offset + 1);
						}
						auto last_par = strstr((buffer + search_offset), "-") - (buffer + search_offset);
						const auto min = MyString(buffer + search_offset, last_par).Parse();
						search_offset += (last_par + 1);

						last_par = strstr((buffer + search_offset), "\r\n") - (buffer + search_offset);
						const auto max = MyString(buffer + search_offset, last_par).Parse();
						current_city.get_items(count_items - 1).set_prices(min, max);
						search_offset += (last_par + 1);
					}

					auto &current_city = cities_[count_cities_ - 1];
					for (auto i = 0;i < count_items - 1;i++)
					{
						auto new_offset = strstr((buffer + search_offset), "-") - (buffer + search_offset);
						const auto min = MyString(buffer + search_offset, new_offset).Parse();
						search_offset += (new_offset + 1);

						new_offset = strstr((buffer + search_offset), ";") - (buffer + search_offset);
						const auto max = MyString(buffer + search_offset, new_offset).Parse();
						current_city.get_items(i).set_prices(min, max);
						search_offset += (new_offset + 1);
					}
					auto last_par = strstr((buffer + search_offset), "-") - (buffer + search_offset);
					const auto min = MyString(buffer + search_offset, last_par).Parse();
					search_offset += (last_par + 1);

					last_par = length - search_offset;
					const auto max = MyString(buffer + search_offset, last_par).Parse();
					current_city.get_items(count_items - 1).set_prices(min, max);
				}
			}
			else
			{
				std::cout << "file is not in right format";
			}

		}
		else {
			std::cout << "error: only " << is.gcount() << " could be read" << std::endl;
		}

		// ...buffer contains the entire file...
		is.close();
		delete[] buffer;
	}
}

bool World::load_ships()
{
	std::ifstream is(".\\Files\\schepen.csv", std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		const int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is) {
			std::cout << "all characters read successfully." << std::endl;

			//skip comments
			auto search_comment_index = 0;
			auto last_comment_index = 0;
			auto comments_left = 0;
			auto first_comment_index = strchr(buffer, '#') - buffer;
			while(search_comment_index <length)
			{
				if(buffer[search_comment_index] == '#')
				{
					comments_left++;
				} 
				else if(comments_left > 0 && buffer[search_comment_index] == '\n')
				{
					comments_left--;
					last_comment_index = search_comment_index;
				}
				search_comment_index++;
			}

			//if only comments
			if(comments_left>0)
			{
				std::cout << "wrong data format" << std::endl;
				return false;
			}

			//check if file contains more than header
			const int header_offset = strchr(buffer + last_comment_index, '\n') - (buffer + last_comment_index)+1;
			if (header_offset > length || header_offset < 0)
			{
				//No data;
				std::cout << "no data in file" << std::endl;
				return false;
			}

			//count amount headers
			int header_cols = 1;
			int header_index = last_comment_index;
			while(header_index < header_offset)
			{
				if (buffer[header_index] == ';')
				{
					header_cols++;
				}
				header_index++;
			}


			//check format and empty values
			auto rows = 1;
			auto cols = 1;

			//auto last_data_index = header_offset;
			auto new_data_index = header_offset;
			while(new_data_index < length)
			{
				//todo haal weg
				auto k = buffer + new_data_index;
				auto ll = buffer[new_data_index];
				auto vv = *(buffer + new_data_index) == '\r\n';
				int kkk = 0;
				if(buffer[new_data_index] == ';')
				{
					/*if((new_data_index-last_data_index)==0)
					{
						std::cout << "leeg in col:" << cols << " row:" << rows << std::endl;
						return false;
					}*/
					cols++;
					//last_data_index = new_data_index + 1;
				}
				else if(buffer[new_data_index] == '\r')
				{
					/*if ((new_data_index - last_data_index) == 0)
					{
						std::cout << "leeg in col:" << cols << " row:" << rows << std::endl;
						return false;
					}*/
					if(cols != header_cols)
					{
						std::cout << "mist een column" << std::endl;
						return false;
					}
					cols = 1;
					rows++;
					//last_data_index = new_data_index + 1;

				}
				new_data_index++;
			}



			ships_ = new Ship[header_cols];
			//search parameters
			auto next_parameter_index = header_offset;
			for(int s = 0 ; s<rows;s++){
				//todo haal weg
				auto k = buffer + next_parameter_index;
				auto & current_ship = ships_[s];

				//set type
				auto parameter_length = strchr(buffer + next_parameter_index, ';') - (buffer + next_parameter_index);
				k = buffer + next_parameter_index;
				current_ship.set_type(MyString(buffer + next_parameter_index, parameter_length));
				next_parameter_index += parameter_length+1;

				//set price
				parameter_length = strchr(buffer + next_parameter_index, ';') - (buffer + next_parameter_index);
				k = buffer + next_parameter_index;
				current_ship.set_price(MyString(buffer + next_parameter_index, parameter_length).Parse());
				next_parameter_index += parameter_length + 1;

				//set storage_capacity
				parameter_length = strchr(buffer + next_parameter_index, ';') - (buffer + next_parameter_index);
				k = buffer + next_parameter_index;
				current_ship.set_storage_capacity(MyString(buffer + next_parameter_index, parameter_length).Parse());
				next_parameter_index += parameter_length + 1;

				//set canons
				parameter_length = strchr(buffer + next_parameter_index, ';') - (buffer + next_parameter_index);
				k = buffer + next_parameter_index;
				current_ship.set_canons(MyString(buffer + next_parameter_index, parameter_length).Parse());
				next_parameter_index += parameter_length + 1;

				//set hp
				parameter_length = strchr(buffer + next_parameter_index, ';') - (buffer + next_parameter_index);
				k = buffer + next_parameter_index;
				current_ship.set_hp(MyString(buffer + next_parameter_index, parameter_length).Parse());
				next_parameter_index += parameter_length + 1;

				//set misc
				parameter_length = strchr(buffer + next_parameter_index, '\r\n') - (buffer + next_parameter_index);
				k = buffer + next_parameter_index;
				current_ship.set_misc(MyString(buffer + next_parameter_index, parameter_length));
				next_parameter_index += parameter_length + 2;

				//todo haal weg
				k = buffer + next_parameter_index;
				int vv = 0;
			}

		}
		else {
			std::cout << "error: only " << is.gcount() << " could be read" << std::endl;
			return false;
		}

		// ...buffer contains the entire file...
		is.close();
		delete[] buffer;
	}
}

int World::city_index(const char * name) const
{
	for(auto i = 0; i<count_cities_;i++)
	{
		if(cities_->get_name().equals(name))
		{
			return i;
		}
	}
	return -1;
}

int World::city_index(const MyString & name) const
{
	return city_index(name.GetString());
}

City & World::get_city(const int index) const
{
	if(index>=0 && index<=count_cities_-1)
	{
		return cities_[index];
	} else
	{
		throw std::out_of_range("out of range");
	}
}

void World::read(const char *filepath, char * &par, int &string_length)
{
	std::ifstream is(filepath, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is) {
			std::cout << "all characters read successfully.";
			par = new char[length];
			memcpy(par, buffer, length);
			//par = buffer;
			string_length = length;
		}
		else {
			std::cout << "error: only " << is.gcount() << " could be read";
			//delete[] buffer;
		}


		// ...buffer contains the entire file...
		delete[] buffer;
		is.close();
	}
}

