#include<iostream>
using namespace std;
void hanoi(int start, int finish, int n) {
	if (n == 1) {
		cout << "���������� ���� 1 �� ������� " << start << " �� �������� " << finish << ".\n";
	}
	else {
		int temp = 6 - start - finish;
		hanoi(start, temp, n - 1);
 		cout << "���������� ���� " << n << " �� ������� " << start << " �� �������� " << finish << ".\n";
		hanoi(temp, finish, n - 1);
	}
}
void main() {
	setlocale(LC_CTYPE, "ru");
	int n, finish, start;
	cout << "�������� � �������� ���������� �����������: ";
	cin >> start;
	cout << "c�������, �� ������� ���������� �����������: ";
	cin >> finish;
	cout << "���-�� ������: ";
	cin >> n;
	hanoi(start, finish, n);
	return;
}