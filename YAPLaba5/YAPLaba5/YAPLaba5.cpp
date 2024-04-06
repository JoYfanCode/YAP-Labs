#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class String
{
private:
	char* symbols;

public:
	String()
	{
		symbols = NULL;
	}

	String(char* symbols)
	{
		this->symbols = symbols;
	}

	String(const String& other)
	{
		symbols = other.symbols;
	}

	~String()
	{
		delete symbols;
	}
};