#include <iostream>
using namespace std;

void main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	int* buff = new int[N];
	int* path = new int[N];
	for (int i = 0; i < N; i++)
	{
		buff[i] = 1;
		path[i] = -1;
	}
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		arr[i] = 1 + rand() % 20;
		cout << arr[i] << " ";

	}
	cout << endl;


	for (int j = 1; j < N; j++) {
		for (int k = 0; k < j; k++) {
			if (arr[j] > arr[k]) {
				if (buff[j] <= buff[k]) {
					buff[j] = buff[k] + 1;
					path[j] = k;
				}
			}
		}
	}

	int max = 0;
	int check = 0;
	for (int i = 0; i < N; i++)
	{
		if (buff[i] > max)
		{
			check = i;
			max = buff[i];
		}
	}
	cout << max << endl;


	for (int i = 0; i < N; i++)
	{
		cout << buff[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < N; i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;


	int out[100];
	for (int i = max; i >= 0; i--)
	{
		out[i] = arr[check];
		check = path[check];
	}
	for (int i = 1; i < max + 1; i++)
	{
		cout << out[i] << " ";
	}
	delete[] arr;
	delete[] buff;
	delete[] path;
}

