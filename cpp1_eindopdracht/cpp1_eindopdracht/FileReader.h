#pragma once
#include "Mystring.h" 

class FileReader
{	
public:
	FileReader();
	~FileReader();
	void read(const char * filepath);
	void searchParameters(char* &par);
	MyString searchStringParameter(char* &par, const char * split);
};

