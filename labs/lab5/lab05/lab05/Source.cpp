#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define edge pair<int,int>


void prim() {
	int matrixOfWeight[8][8]{
		{ 0, 2, 0, 8, 2, 0, 0, 0},
		{ 2, 0, 3,10, 5, 0, 0, 0},
		{ 0, 3, 0, 0,12, 0, 0, 7},
		{ 8,10, 0, 0,14, 3, 1, 0},
		{ 2, 5,12,14, 0,11, 4, 8},
		{ 0, 0, 0, 3,11, 0, 6, 0},
		{ 0, 0, 0, 1, 4, 6, 0, 9},
		{ 0, 0, 7, 0, 8, 0, 9, 0}
	};
	bool checking[8];
	int min = INT_MAX;
	int indexI;
	int indexJ;
	bool clear[8];
	bool usedWeigths[8];
	for (int i = 0; i < 8; i++)
	{
		checking[i] = false;
		clear[i] = false;
		usedWeigths[i] = false;
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (min > matrixOfWeight[i][j] && matrixOfWeight[i][j] != 0)
			{
				min = matrixOfWeight[i][j];
				indexI = i;
				indexJ = j;
			}
		}
	}
	for (int h = 0; h < 8; h++)
	{
		checking[indexI] = true;
		checking[indexJ] = true;
		usedWeigths[indexI] = true;
		for (int i = 0; i < 8; i++)
		{
			if (i == indexI && !clear[i] || i == indexJ && !clear[i]) {
				for (int j = 0; j < 8; j++)
				{
					if (i == indexI && j == indexJ)
						matrixOfWeight[i][j] = min;
					else {
						matrixOfWeight[i][j] = 0;
					}

				}
				clear[i] = true;
			}
		}
		min = INT_MAX;


		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (checking[j] && matrixOfWeight[i][j] != 0 && matrixOfWeight[i][j] < min) {
					if (!usedWeigths[i]) {
						min = matrixOfWeight[i][j];
						indexI = i;
						indexJ = j;
					}
				}
			}
		}
	}
	cout << "Прим: "<<endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (matrixOfWeight[i][j] != 0) {
				cout << i + 1 << "--->";
				cout << j + 1 << ": " << matrixOfWeight[i][j] << endl;
			}
		}
	}
}

vector<pair<int, edge>> G;
vector<pair<int, edge>> T;
int* parent;
int V;
void add(int u, int v, int w);
int find_set(int i);
void kruskal();
void print();

int find_set(int i) {
	if (i == parent[i])
		return i;
	else
		return find_set(parent[i]);
}

void add(int u, int v, int w) {
	G.push_back(make_pair(w, edge(u, v)));
}
void kruskal() {
	parent = new int[8];
	for (int i = 0; i < 8; i++)
		parent[i] = i;

	int uRep, vRep;
	sort(G.begin(), G.end()); 
	for (int i = 0; i < G.size(); i++) {
		uRep = find_set(G[i].second.first);
		vRep = find_set(G[i].second.second);
		if (uRep != vRep) {
			T.push_back(G[i]);
			parent[uRep] = parent[vRep];

		}
	}
}
void print() {
	cout << "Крускал: " << endl;
	cout << "Edge :" << " Weight" << endl;
	for (int i = 0; i < T.size(); i++) {
		cout << T[i].second.first + 1 << " - " << T[i].second.second + 1 << " : "
			<< T[i].first;
		cout << endl;
	}
}

void main() {
	setlocale(LC_CTYPE, "ru");
	prim();

	add(0, 1, 2);
	add(0, 4, 2);
	add(0, 3, 8);
	add(1, 0, 2);
	add(1, 4, 5);
	add(1, 2, 3);
	add(2, 1, 3);
	add(2, 4, 12);
	add(2, 7, 7);
	add(3, 0, 8);
	add(3, 1, 10);
	add(3, 4, 14);
	add(3, 5, 3);
	add(4, 0, 2);
	add(4, 1, 5);
	add(4, 2, 12);
	add(4, 7, 8);
	add(4, 6, 4);
	add(4, 5, 11);
	add(4, 3, 14);
	add(5, 3, 3);
	add(5, 4, 11);
	add(5, 6, 6);
	add(6, 5, 6);
	add(6, 3, 1);
	add(6, 4, 4);
	add(6, 7, 9);
	add(7, 6, 9);
	add(7, 4, 8);
	add(7, 2, 7);
	kruskal();
	print();
}