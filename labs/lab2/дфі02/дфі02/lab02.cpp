#include<iostream>
#include <queue>
#include <stack>
using namespace std;


void BFS(bool temp[10][10], int start) ;
void DFS(bool temp[10][10], int start) ;
void ListOfAdjancency();
void ListOfEdges();


void main() {
	setlocale(LC_CTYPE, "ru");
	bool adjancencyMatrix[10][10] = {
		{0,0,0,0,1,0,0,0,0,0},	//1
		{0,0,0,0,0,0,1,1,0,0},	//2
		{0,0,0,0,0,0,0,1,0,0},	//3
		{0,0,0,0,0,1,0,0,1,0},	//4
		{1,0,0,0,0,1,0,0,0,0},	//5
		{0,0,0,1,1,0,0,0,1,0},	//6
		{0,1,0,0,0,0,0,1,0,0},	//7
		{0,1,1,0,0,0,1,0,0,0},	//8
		{0,0,0,1,0,1,0,0,0,1},	//9
		{0,0,0,0,0,0,0,0,1,0},	//10
	};
	int start;
	bool b = true;
	int counter = 1;
	cout << "сколько раз введешь вершины?";
	cin >> counter;
	while (counter != 0) {
		cout << "\n\nС какой вершины начинать поиск?\n";
		cin >> start;
		cout << "\nПоиск в ширину:\n";
		BFS(adjancencyMatrix, start - 1);
		cout << "\n\nПоиск в глубину:\n";
		DFS(adjancencyMatrix, start - 1);
		counter--;
	}
	ListOfAdjancency();
	ListOfEdges();
}

void DFS(bool temp[10][10], int start) {
	bool visited[10];
	int peaks[10];
	for (int i = 0; i < 10; i++)
	{
		visited[i] = false;
		peaks[i] = i;
	}
	stack <int> q;
	visited[start] = true;
	q.push(peaks[start]);
	int topNow;
	while (!q.empty()) {
		topNow = q.top();
		cout << topNow + 1 << "-->";
		q.pop();
		for (int i = 9; i >= 0; i--)
		{
			if (temp[topNow][i] == true && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
};


void ListOfEdges() {
	int listOfEdges1[10] = { 1,5,4,4,9,2,2,7,3 };
	int listOfEdges2[10] = { 5,6,6,9,10,7,8,8,8 };
	cout << "\nСписок ребер:\n\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "{ " << listOfEdges1[i] << " , " << listOfEdges2[i] << " }, {"
			<< listOfEdges2[i] << " , " << listOfEdges1[i] << "}\n";
	}
};

void ListOfAdjancency() {
	int listOfAdjancency[10][4]{
		{5},
		{7,8},
		{8},
		{6,9},
		{1,6},
		{5,4,6},
		{2,8},
		{2,3,7},
		{4,6,10},
		{9},
	};
	cout << "\n\nсписок смежности:\n\n";
	for (int i = 0; i < 10; i++)
	{
		cout << (i + 1) << "--> {";
		for (int j = 0; j < 4; j++)
		{
			if(listOfAdjancency[i][j]!=0)
			cout <<" " << listOfAdjancency[i][j] << " ";
		}
		cout << "}\n";
	}
}


void BFS(bool temp[10][10], int start) {
	bool visited[10];
	int peaks[10];
	for (int i = 0; i < 10; i++)
	{
		visited[i] = false;
		peaks[i] = i;
	}
	queue <int> q;
	visited[start] = true;
	q.push(peaks[start]);
	int topNow;
	while (!q.empty()) {
		topNow = q.front();
		cout << topNow+1 << " ";
		q.pop();
		for (int i = 0; i < 10; i++)
		{
			if (temp[topNow][i] == true && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
};