#include "iostream"
#include <queue> // очередь
#include <stack> // стек
#include <string>
using namespace std;

struct Edge 
{
	int begin;
	int end;
};

bool check_number(int n) //проверка на число 
{
	if (cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		return false;

	}
	else return true;
}


string bfs(int frs, int lst,int nodes[7],int mas[7][7])
{
	if (frs > 7 || frs < 1 || lst > 6 || lst < 1 || mas==NULL)
	{
		cout << "Ошибка";
		return "Ошибка";
	}
	queue<int> Queue;
	stack<Edge> Edges;
	Edge e;
	Queue.push(frs - 1); // помещаем в очередь первую вершину
	while (!Queue.empty())
	{
		int node = Queue.front(); // извлекаем вершину
		Queue.pop();
		nodes[node] = 2; // отмечаем ее как посещенную
		for (int j = 0; j < 7; j++)
		{
			if (mas[node][j] == 1 && nodes[j] == 0)
			{ // если вершина смежная и не обнаружена
				Queue.push(j); // добавляем ее в очередь
				nodes[j] = 1; // отмечаем вершину как обнаруженную
				e.begin = node;
				e.end = j;
				Edges.push(e);
				if (node == lst) break;
			}
		}
		
	}
	string res;
	cout << "Путь до вершины " << lst + 1 << endl;
	cout << lst + 1;
	int cnt=0;
	int i = 0;
	while (!Edges.empty()) {

		e = Edges.top();
		Edges.pop();
		if (e.end == lst) {
			if (cnt == 0)
			{
				res += to_string(lst + 1);
				cnt++;
			}
			
			lst = e.begin;
			cout << " <- " << lst + 1;
			res += " <- ";
			res += to_string(lst + 1);
		    cnt++;
	
		}

	}
	
			
	if (cnt == 0)
	{
		cout << "Путь отсутствует" << endl;
		res = "Путь отсутствует";
	}
	cout << endl;
	cout << "res: " << res;

	return res;
}


int main()
{
	system("chcp 1251");
	system("cls");
	int lst,frs;

	int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 0 },
	                  { 1, 0, 1, 1, 0, 0, 0 },
	                  { 1, 1, 0, 0, 0, 0, 0 },
	                  { 0, 1, 0, 0, 1, 0, 0 },
	                  { 0, 0, 0, 1, 0, 1, 0 },
	                  { 0, 0, 0, 0, 1, 0, 1 },
	                  { 1, 0, 0, 0, 0, 0, 0 } };
	int nodes[7]; // вершины графа
	for (int i = 0; i < 7; i++) // исходно все вершины равны 0
		nodes[i] = 0;

	cout << "Введите начальную вершину: "; //добавить проверки, вынести в отдельную функцию ввод
	cin >> frs;
	while (!check_number(frs))
	{
		cout << "Ошибка ввода, пожалуйста,повторите попытку: ";
		cin >> frs;
	}
	cout << "Введите конечную вершину:  ";
	cin >> lst;
	while (!check_number(lst))
	{
		cout << "Ошибка ввода, пожалуйста,повторите попытку: ";
		cin >> lst;
	}
	lst--;
	
 bfs(frs, lst, nodes, mas);
	
	system("pause");
	return 0;
}