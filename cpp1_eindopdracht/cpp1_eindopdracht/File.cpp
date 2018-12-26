#include "pch.h"
#include "File.h"
#include <iostream>
#include <fstream>
#include <string>

File::File()
{
}


File::~File()
{
}

bool File::init(const char * file_path)
{
	std::ifstream is(file_path, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		const int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is) {
			std::cout << "all characters read successfully." << std::endl;

			auto end_line = '\n';
			auto amount_line_break = 1;

			//count rows
			auto rows = 0;
			auto current_index = 0;
			while (current_index <= length)
			{
				if (buffer[current_index] == '\r')
				{
					end_line = '\r';
					rows++;
					if (buffer[current_index + 1] == '\n') {
						current_index++;
						amount_line_break = 2;
					}
				}
				else if (buffer[current_index] == '\n')
				{
					rows++;
					current_index++;
				}
				current_index++;
			}
			//last line
			rows++;

			//read file
			auto temp_file = MyList<MyString>(rows);
			current_index = 0;
			auto prev_index = 0;
			for(auto r = 0;r<rows-1;r++)
			{
				const auto length_string = strchr(buffer + current_index, end_line) - (buffer + current_index);
				if(length_string<0 || (current_index + length_string)>length)
				{
					//shit
					is.close();
					delete[] buffer;
					return false;
				}
				temp_file[r] = MyString(buffer + current_index, length_string);
				current_index += length_string +amount_line_break;
			}
			if(current_index<=length)
			{
				temp_file[rows-1] = MyString(buffer + current_index,length-current_index);
			} else
			{
				is.close();
				delete[] buffer;
				return false;
			}
			//text_file = std::move(temp_file);

			auto start_row = 0;
			auto end_row = temp_file.get_size();
			for (auto r = 0;r < temp_file.get_size();r++)
			{
				auto k = temp_file[r];
				if (temp_file[r].GetString()[0] == '#')
				{
					start_row++;
				}
				if (temp_file[r].GetLength() == 0)
				{
					end_row--;
					break;
				}
			}

			auto temp_file_2 = MyList<MyList<MyString>>(end_row - start_row);
			auto col = -1;
			for(auto r = start_row;r< end_row;r++)
			{
				auto k = temp_file[r];
				auto col_index = temp_file[r].get_occurrence_index(';');
				const auto row_col = col_index.get_size()+1;
				if(col != -1 && col!=row_col)
				{
					std::cout << "file is missing columns" << std::endl;
					return false;
				}
				col = row_col;
				auto start_index = 0;
				auto row = MyList<MyString>(col);
				for(auto c = 0;c<row_col - 1;c++)
				{
					//todo
					int k = r - start_row;
					const auto end_index = col_index[c];
					row[c] = temp_file[r].subset(start_index,end_index);
					start_index = end_index+1;
				}
				const auto end_index = temp_file[r].GetLength();
				row[row_col - 1] = temp_file[r].subset(start_index, end_index);
				start_index = end_index+1;
				temp_file_2[r-start_row] = row;
			}

			file = std::move(temp_file_2);

		}
		else {
			std::cout << "error: only " << is.gcount() << " could be read" << std::endl;
			is.close();
			delete[] buffer;
			return false;
		}

		// ...buffer contains the entire file...
		is.close();
		delete[] buffer;
		return true;
	}
	std::cout << "file could not be loaded" << std::endl;
	is.close();
	return false;
}
