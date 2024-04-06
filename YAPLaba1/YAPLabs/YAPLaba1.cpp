#include <iostream>
#include <fstream>

using namespace std;

double Count(double* Arr, double b, double d, int Length)
{
	double Result = 1;
	int CountElements = 0;

	for (int i = 0; i < Length; i++)
	{
		if (Arr[i] >= b && Arr[i] <= d) {
			Result *= Arr[i];
			CountElements++;
		}
	}

	if (CountElements == 0)
		return 0;
	else
		return Result;
}

int main()
{
	int length = 0;
	double b = 0;
	double d = 0;

	ifstream in;
	ofstream out;

	in.open("input.txt");
	if (!in.is_open())
	{
		cout << "Error! File cannot be opened" << endl;
		return 0;
	}

	double tmp;
	while (in >> tmp)
		length++;
	in.close();

	double* Arr = new double[length];	// Dynamic array

	in.open("input.txt");
	while (!in.eof())			// Write items from the file
	{
		in >> b;
		in >> d;
		for (int i = 0; i < length - 2; i++)
			in >> Arr[i];
	}
	in.close();
	
	out.open("output.txt");			// Output	
	out.precision(15);
	out << Count(Arr, b, d, length - 2);
	out.close();

	delete[] Arr;							// Releasing the memory

	return 0;
}