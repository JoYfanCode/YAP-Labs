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

		for (int i = 0; str[i] && str[i] != '\0'; i++)
			counter++;

		return counter;
	}

public:
	String()
	{
		symbols = new char[100];
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
		delete symbols;
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
		for (int i = 0; i < n; i++)
			symbols[size + i] = c;

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
		//
	}

	friend ifstream& operator>>(ifstream& in, String& str) // перегрузка оператора ввода
	{
		in >> str.symbols;

		int counter = 0;

		for (int i = 0; str.symbols[i] && str.symbols[i] != '\0'; i++)
			counter++;

		str.size = counter;
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const String& str)  // перегрузка оператора вывода
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
};

int main()
{
	int key, tmp;
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> key;

	char text[100];
	char text2[100];
	//in.getline(text, 100, '\0');
	//in >> text;
	//in >> text2;
	

	if (key == 1) { // Конструктор по умолчанию
		String str;
		out << str;
	}
	else if (key == 2) { // Конструктор инициализации
		String str = String(text);
		out << str;
	}
	else if (key == 3) { // Copy constructor
		String str = String(text);
		String str2 = String(str);
		out << str2;
	}
	else if (key == 4) { // =
		//String str = String(text);
		//char text2[100];
		//in.getline(text2, 100, '\0');
		//String str2 = String(text2);
		String str, str2;
		in >> str;
		in >> str2;

		out << str << endl;
		out << str2 << endl;

		if (str == str2)
			out << "Equal";
		else
			out << "Not equal";
	}

	in.close();
	out.close();

	return 0;
}