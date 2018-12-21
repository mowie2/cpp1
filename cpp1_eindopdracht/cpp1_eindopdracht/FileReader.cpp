#include "pch.h"
#include "FileReader.h"
#include "MyString.h"
#include <iostream>
#include <fstream>

FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

void FileReader::searchParameters(char* &par)
{
	par++;
	
}

MyString FileReader::searchStringParameter(char* &par, const char * split)
{
	int count = strstr(par, split) - par;
	MyString parameter(par, count);
	par += count;
	return parameter;
}


void FileReader::read(const char *filepath)
{
	std::ifstream is(filepath, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is)
			std::cout << "all characters read successfully.";
		else
			std::cout << "error: only " << is.gcount() << " could be read";


		// ...buffer contains the entire file...

		int offset = 0;

		while (*(buffer+offset) != ';') {
			offset++;
		}


		is.close();
		delete[] buffer;
		_CrtDumpMemoryLeaks();
	}
}

