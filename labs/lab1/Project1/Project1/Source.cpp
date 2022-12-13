#include<iostream>
using namespace std;
void hanoi(int start, int finish, int n) {
	if (n == 1) {
		cout << "передвинут диск 1 со стержня " << start << " на стержень " << finish << ".\n";
	}
	else {
		int temp = 6 - start - finish;
		hanoi(start, temp, n - 1);
 		cout << "передвинут диск " << n << " со стержня " << start << " на стержень " << finish << ".\n";
		hanoi(temp, finish, n - 1);
	}
}
void main() {
	setlocale(LC_CTYPE, "ru");
	int n, finish, start;
	cout << "стержень с которого необходимо передвигать: ";
	cin >> start;
	cout << "cтержень, на который необходимо передвинуть: ";
	cin >> finish;
	cout << "кол-во дисков: ";
	cin >> n;
	hanoi(start, finish, n);
	return;
}