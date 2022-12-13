#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "ru");
	const int length=9;
	int start=-1;
	string answer;
	char points[length] = { 'A','B','C','D','E','F','G','H','I', };
	int matrixOfWeight[length][length]{
		{0,7,10,0,0,0,0,0,0},		//A1
		{7,0,0,0,0,9,27,0,0},		//B2
		{10,0,0,0,31,8,0,0,0},		//C3
		{0,0,0,0,32,0,0,17,21},		//D4
		{0,0,31,32,0,0,0,0,0},		//E5
		{0,9,8,0,0,0,0,11,0},		//F6
		{0,27,0,0,0,0,0,0,15},		//G7
		{0,0,0,17,0,11,0,0,15},		//H8
		{0,0,0,21,0,0,15,15,0},		//I9
	};
	int pass[length];
	bool visited[length];
	cout << "Введи начальную вершину:\n";
	cin >> answer;
	for (int i = 0; i < length; i++)
	{
		if (points[i] == answer[0]) {
			start = i;
			break;
		}
	}
	if (start == -1)
		return main();
	
	for (int i = 0; i <length; i++)
	{
		visited[i] = false;
		pass[i] = INT32_MAX;
	}
	visited[start] = true;
	pass[start] = 0;
	int sum[length];
	int temp;
	int min=0;
	do
	{
		for (int i = 0; i < length; i++)
		{
			if (!visited[i] && matrixOfWeight[start][i] != 0) {
				sum[i] = min + matrixOfWeight[start][i];
				if (sum[i] < pass[i]) {
					pass[i] = sum[i];
				}
			}
		}
		min = 100;
		for (int i = 0; i < length; i++)
		{
			if (!visited[i] && min > pass[i]) {
				min = pass[i];
				temp = i;
			}
		}
		if (min == 100) {
			break;
		}
		visited[temp] = true;
		start = temp;
	} while (visited[start]);
	cout << "путь из " << answer << " во все другие вершины:\n";
	for (int i = 0; i < length; i++)
	{
		cout << answer << "-->" << points[i] << ":" << pass[i]<<"\n";
	}
};