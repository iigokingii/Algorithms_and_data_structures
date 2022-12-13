#include <iostream>
#include<map>
#include<vector>
#include<list>
#include<string>

using namespace std;

struct node {
	int count;
	char symbol='`';
	node* left=NULL, * right=NULL;
	node(node* _left, node*_right) {
		left = _left;
		right = _right;
		count = _left->count + _right->count;
	}
	node(){}
};

struct Cmp {
	bool operator()(node* l, node* r)const {
		return l->count < r->count;
	}
};

vector<int>vect;
map<char, vector<int>> table;

void Table(node* root) {
	if (root != NULL) {
		if (root->left != NULL) {
			vect.push_back(0);
			Table(root->left);
		}
		if (root->right != NULL) {
			vect.push_back(1);
			Table(root->right);
		}
		if (root->symbol != '`') {
			table[root->symbol] = vect;
			vect.pop_back();
		}
	}	
}

void main() {

	setlocale(LC_CTYPE, "ru");
	string stroke;
	cout << "Введите строку для шифровки: ";	//wassup homie chinazes
	getline(cin, stroke);
	map <char, int> m;
	for (int i = 0; i < stroke.length(); i++)
	{
		char tmp = stroke[i];
		m[tmp]++;
	}
	map<char, int >::iterator i;
	cout << "Встречаемость: \n";
	for (i = m.begin(); i != m.end(); ++i)
	{
		cout << i->first << ":" << i->second << endl;
	}
	list<node*>l;
	map<char, int >::iterator ii;
	for (ii = m.begin(); ii != m.end(); ++ii)
	{
		node* tmp = new node;
		tmp->symbol = ii->first;
		tmp->count = ii->second;
		l.push_back(tmp);
	}
	while (l.size() != 1)
	{
		l.sort(Cmp());
		node* tmpLeft;
		node* tmpRight;
		tmpLeft = l.front();
		l.pop_front();
		tmpRight = l.front();
		l.pop_front();
		node* Newtmp = new node(tmpLeft, tmpRight);
		l.push_back(Newtmp);
	}

	node* root = l.back();

	Table(root);
	cout << "символ и его бинарное представление: \n";
	for (int i = 0; i < stroke.length(); i++)
	{
		vector<int>temp = table[stroke[i]];
		cout << stroke[i] << ": ";
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[j];
		}
		cout << endl;
	}
	cout << "Преобразованные данные: ";
	for (int i = 0; i < stroke.length(); i++)
	{
		vector<int>temp = table[stroke[i]];
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[j];
		}
	}
}