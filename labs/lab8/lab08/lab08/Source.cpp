#include<iostream>
#include <cmath>
#include<iomanip>
using namespace std;
void main() {
	setlocale(LC_ALL, "ru");
	string name[100];
	int ArrOfWeight[100];
	int ArrOfCost[100];
	int capacity;
	int count;
	cout << "Вместимость рюкзака: ";
	cin >> capacity;
	cout << "Количество товаров: ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "Введите имя товара:";
		cin >>name[i];
		cout << "Вес товара: ";
		cin >> ArrOfWeight[i];
		cout << "Введите стоимость товара:";
		cin >> ArrOfCost[i];
	}
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << " товар:" << endl;
		cout << "Имя товара:" << name[i] << endl;
		cout << "Вес товара:" << ArrOfWeight[i] << endl;
		cout << "Стоимость товара:" << ArrOfCost[i] << endl;
	}
	int** arr = new int* [count + 1];
	for (int i = 0; i < count + 1; i++)
	{
		arr[i] = new int[capacity + 1];
	}
	for (int i = 0; i < count + 1; i++) {
		for (int k = 0; k < capacity + 1; k++) {
			arr[i][k] = 0;
		}
	}
	for (int i = 1; i < count + 1; i++) {
		for (int k = 1; k < capacity + 1; k++) {
			if (k < ArrOfWeight[i - 1]) {
				arr[i][k] = arr[i - 1][k];
			}
			else
				arr[i][k] = max(arr[i - 1][k], arr[i - 1][k - ArrOfWeight[i - 1]] + ArrOfCost[i - 1]);
		}
	}
	cout << "Таблица:" << endl;
	for (int i = 0; i < count + 1; i++) {
		for (int k = 0; k < capacity + 1; k++) {
			cout <<setfill('0') << setw(2) << right << arr[i][k] << ' ';
		}
		cout << endl;
	}
	cout << "Максимальная стоимость предметов,вложенных в рюкзак:" << arr[count][capacity] << endl;
	cout << "Предметы,вложенные в рюкзак:";
	int k = capacity;
	while (count > 0 && capacity > 0)
	{
		if (arr[count][capacity] != arr[count - 1][capacity])
		{
			cout<< name[count - 1] << " ";
			capacity -= ArrOfWeight[count - 1];
		}
		count--;
	}
}