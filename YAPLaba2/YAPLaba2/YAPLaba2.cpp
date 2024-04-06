#include <iostream>
#include <fstream>

using namespace std;

double** Transposition(double** Matrix, int n, int m)
{
	double** T_Matrix = new double* [m];
	for (int i = 0; i < m; i++)
		T_Matrix[i] = new double[n];

	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			T_Matrix[i][j] = Matrix[j][i];
		}
	}

	return T_Matrix;
}

int main()
{
	int fileLength = 0;
	int n = 0;
	int m = 0;

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
		fileLength++;
	in.close();

	double* Data = new double[fileLength]; // Dynamic array

	in.open("input.txt");
	while (!in.eof()) // Write elements from the file
	{
		in >> n;
		in >> m;
		for (int i = 0; i < fileLength - 2; i++)
			in >> Data[i];
	}
	in.close();

	double** Matrix = new double* [n];
	for (int i = 0; i < n; i++)
		Matrix[i] = new double[m];

	int currentIndex = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Matrix[i][j] = Data[currentIndex];
			currentIndex++;
		}
	}

	out.open("output.txt"); // Output	
	out.precision(15);

	double** T_Matrix = Transposition(Matrix, n, m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << T_Matrix[i][j] << " ";
		}
	}

	out.close();

	for (int i = 0; i < n; i++) // Releasing the memory
		delete[] Matrix[i];
	delete[] Matrix;
	for (int i = 0; i < m; i++)
		delete[] T_Matrix[i];
	delete[] T_Matrix;
	delete[] Data;

	return 0;
}