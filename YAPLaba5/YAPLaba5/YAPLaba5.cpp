#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class String
{
private:
	char* symbols;
	int size;

	int CountSize(char* str)
	{
		int counter = 0;

		for (int i = 0; str[i] != '\0'; i++)
			counter++;

		return counter;
	}

public:
	String()
	{
		symbols = NULL;
		size = 0;
	}

	String(char* symbols)
	{
		this->symbols = symbols;
		size = CountSize(symbols);
	}

	String(const String& other)
	{
		symbols = other.symbols;
	}

	~String()
	{
		delete symbols;
	}

	int size()
	{
		return size;
	}

	void resize(int n)
	{
		if (n < size) {
			symbols[n] = '\0';
		}
		else if (n > size) {
			for (int i = 0; i < n; i++) {
				symbols[size + i] = ' ';
			}
			symbols[size + n] = '\0';
		}
	}

	void resize(int n, char c)
	{
		if (n < size) {
			symbols[n] = '\0';
		}
		else if (n > size) {
			for (int i = 0; i < n; i++) {
				symbols[size + i] = c;
			}
			symbols[size + n] = '\0';
		}
	}

	void clear()
	{
		delete[] symbols;
	}

	bool empty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}

	void push_back(char c)
	{
		symbols[size] = c;
		symbols[size + 1] = '\0';
	}

	void append(int n, char c)
	{
		for (int i = 0; i < n; i++) {
			symbols[size + i] = c;
		}
		symbols[size + n] = '\0';
	}

	void append(char* str)
	{
		int strSize = CountSize(str);

		for (int i = 0; i < strSize; i++) {
			symbols[size + i] = str[i];
		}

		symbols[size + strSize] = '\0';
	}

	void append(char* str, int pos, int n)
	{
		for (int i = 0; i < n; i++) {
			symbols[pos + i] = str[i];
		}

		symbols[pos + n] = '\0';
	}

	void insert(int start, int n,  char c)
	{
		for (int i = 0; i < n; i++) {
			symbols[start + i] = c;
		}
		symbols[start + n] = '\0';
	}

	void substr(int pos, int count)
	{
		char* str = new char[count];

		for (int i = 0; i < size; i++)
			str[i] = symbols[pos + i];
	}

	void find(char* substr, int pos = 0)
	{

	}
};