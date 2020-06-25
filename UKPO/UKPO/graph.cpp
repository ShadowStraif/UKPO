#include "iostream"
#include <queue> // �������
#include <stack> // ����
#include <string>
using namespace std;

struct Edge 
{
	int begin;
	int end;
};

bool check_number(int n) //�������� �� ����� 
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
		cout << "������";
		return "������";
	}
	queue<int> Queue;
	stack<Edge> Edges;
	Edge e;
	Queue.push(frs - 1); // �������� � ������� ������ �������
	while (!Queue.empty())
	{
		int node = Queue.front(); // ��������� �������
		Queue.pop();
		nodes[node] = 2; // �������� �� ��� ����������
		for (int j = 0; j < 7; j++)
		{
			if (mas[node][j] == 1 && nodes[j] == 0)
			{ // ���� ������� ������� � �� ����������
				Queue.push(j); // ��������� �� � �������
				nodes[j] = 1; // �������� ������� ��� ������������
				e.begin = node;
				e.end = j;
				Edges.push(e);
				if (node == lst) break;
			}
		}
		
	}
	string res;
	cout << "���� �� ������� " << lst + 1 << endl;
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
		cout << "���� �����������" << endl;
		res = "���� �����������";
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
	int nodes[7]; // ������� �����
	for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
		nodes[i] = 0;

	cout << "������� ��������� �������: "; //�������� ��������, ������� � ��������� ������� ����
	cin >> frs;
	while (!check_number(frs))
	{
		cout << "������ �����, ����������,��������� �������: ";
		cin >> frs;
	}
	cout << "������� �������� �������:  ";
	cin >> lst;
	while (!check_number(lst))
	{
		cout << "������ �����, ����������,��������� �������: ";
		cin >> lst;
	}
	lst--;
	
 bfs(frs, lst, nodes, mas);
	
	system("pause");
	return 0;
}