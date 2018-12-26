#pragma once
#include "MyList.h"
#include "MyString.h"
class File
{
public:
	File();
	~File();
	bool init(const char * file_path);
	MyList<MyString> text_file;
	MyList<MyList<MyString>> file;
	char end_line;
};

