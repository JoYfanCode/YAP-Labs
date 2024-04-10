#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class String
{
private:
	char* symbols;
	int size;

	const int LIMIT_SIZE = 100;

	int CountSize(char* str)
	{
		int counter = 0;

		for (int i = 0; str[i] && str[i] != '\0'; i++)
			counter++;

		return counter;
	}

public:
	String()
	{
		symbols = new char[LIMIT_SIZE];
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
		size = other.size;
	}

	~String() {}

	int GetSize()
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

		size = n;
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

		size = n;
	}

	void clear()
	{
		delete symbols;
		size = 0;
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
		size++;
	}

	void append(int n, char c)
	{
		for (int i = 0; i < n; i++)
			symbols[size + i] = c;

		symbols[size + n] = '\0';
		size += n;
	}

	void append(char* str)
	{
		int strSize = CountSize(str);

		for (int i = 0; i < strSize; i++) {
			symbols[size + i] = str[i];
		}

		symbols[size + strSize] = '\0';
		size += strSize;
	}

	friend ifstream& operator>>(ifstream& in, String& str)
	{
		in >> str.symbols;

		int counter = 0;

		for (int i = 0; str.symbols[i] && str.symbols[i] != '\0'; i++)
			counter++;

		str.size = counter;
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const String& str)
	{
		for (int i = 0; i < str.size; i++)
			out << str.symbols[i];

		return out;
	}

	bool operator==(const String& str)
	{
		cout << size << " " << str.size << endl;
		if (size != str.size)
			return false;

		for (int i = 0; i < size; i++) {
			cout << symbols[i] << " " << str.symbols[i] << endl;
			if (symbols[i] != str.symbols[i])
				return false;
		}
			

		return true;
	}

	void operator=(const String& str)
	{
		symbols = str.symbols;
		size = str.size;
	}

	String operator+(const String& other) const
	{
		int strSize = 0;

		for (int i = 0; other.symbols[i] != '\0'; i++)
			strSize++;

		for (int i = 0; i < strSize; i++) {
			symbols[size + i] = other.symbols[i];
		}

		symbols[size + strSize] = '\0';

		return String(symbols);
	}

	char& operator[](int i)
	{
		return symbols[i];
	}
};

int main()
{
	int key = 0;
	const int LIMIT_SIZE = 100;
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> key;

	if (key == 1) { // Default constructor
		String str;
		out << str;
	}
	else if (key == 2) { // Initialization constructor
		char text[LIMIT_SIZE];
		in >> text;
		String str = String(text);
		out << str;
	}
	else if (key == 3) { // Copy constructor
		char text[LIMIT_SIZE];
		String str1 = String(text);
		String str2 = String(str1);
		out << str2;
	}
	else if (key == 4) { // ==
		String str, str2;
		in >> str;
		in >> str2;

		if (str == str2)
			out << "Equal";
		else
			out << "Not equal";
	}
	else if (key == 5) { // =
		String str1, str2;
		in >> str1;
		str2 = str1;
		out << str2;
	}
	else if (key == 6) { // +
		String str1, str2;
		in >> str1 >> str2;
		out << str1 + str2;
	}
	else if (key == 7) { // resize
		String str;
		in >> str;
		str.resize(10, '1');
		out << str;
	}
	else if (key == 8) { // push_back
		String str;
		in >> str;
		str.push_back('1');
		out << str;
	}
	else if (key == 9) { // append
		String str;
		char* text = new char[LIMIT_SIZE];
		in >> str >> text;
		str.append(text);
		out << str;
	}
	else if (key == 10) { // GetSize
		String str;
		in >> str;
		out << str.GetSize();
	}

	in.close();
	out.close();

	return 0;
}