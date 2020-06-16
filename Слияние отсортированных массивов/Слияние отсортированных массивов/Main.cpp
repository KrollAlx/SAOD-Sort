#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int countCompares = 0;

void initArray(int*& arr, int& N, const string& fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл" << endl;
	}
	else
	{
		cout << "Файл " << fileName << endl;
		file >> N;
		arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			file >> arr[i];
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	file.close();
}

void merge(const int* c, const int* d, const int N, const int M, int* f)
{
	int i, j, k;
	i = j = k = 0;
	while (i < N && j < M)
	{
		if (c[i] > d[j])
		{
			countCompares++;
			f[k++] = c[i++];
		}
		else
		{
			f[k++] = d[j++];
		}
	}
	while (i < N)
	{
		f[k++] = c[i++];
	}
	while (j < M)
	{
		f[k++] = d[j++];
	}
}

void write(const int* arr, const int N)
{
	ofstream file("f.txt");
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл" << endl;
	}
	else
	{
		file << N << endl;
		cout << "Итоговый файл: ";
		for (int i = 0; i < N; i++)
		{
			file << arr[i] << " ";
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	file.close();
}

int main()
{
	setlocale(LC_ALL, "ru");

	int* c; int p;
	int* d; int q;

	initArray(c, p, "c.txt");
	initArray(d, q, "d.txt");

	int* f = new int[p + q];
	
	merge(c, d, p, q, f);
	write(f, p + q);
	cout << "Количество сравнений " << countCompares << endl
		<< "p + q = " << p + q << endl;

	delete[] c;
	delete[] d;
	delete[] f;
	system("pause");
	return 0;
}