#include "stdafx.h"
#include "CppUnitTest.h"
#include "../UKPO/graph.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest1)
	{
	public:

	

		TEST_METHOD(Way17) //����� ���� � ����� � ����������� ���� ������� ���������� ������
		{

			int frs = 1;
			int lst = 7;

			int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 0 },
					  { 1, 0, 1, 1, 0, 0, 0 },
					  { 1, 1, 0, 0, 0, 0, 0 },
					  { 0, 1, 0, 0, 1, 0, 0 },
					  { 0, 0, 0, 1, 0, 1, 0 },
					  { 0, 0, 0, 0, 1, 0, 0 },
					  { 0, 0, 0, 0, 0, 0, 0 } };
			int nodes[7]; // ������� �����
			for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
			{
				nodes[i] = 0;
			}
			lst--;
			string expected = "���� �����������";
			Assert::AreEqual(expected, bfs(frs, lst, nodes, mas));

		}


		TEST_METHOD(NormG25) //����� ���� � ����� � ���������� ���-� ������ � �����
		{

			int frs = 2;
			int lst = 5;

			int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 0 },
					  { 1, 0, 1, 1, 0, 0, 0 },
					  { 1, 1, 0, 0, 0, 0, 0 },
					  { 0, 1, 0, 0, 1, 0, 0 },
					  { 0, 0, 0, 1, 0, 1, 0 },
					  { 0, 0, 0, 0, 1, 0, 1 },
					  { 0, 0, 0, 0, 0, 0, 0 } };
			int nodes[7]; // ������� �����
			for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
			{
				nodes[i] = 0;
			}
			lst--;
			string expected = "5 <- 4 <- 2";
			Assert::AreEqual(expected, bfs(frs, lst, nodes, mas));

		}



		TEST_METHOD(Empty) //����� ���� � ������ �����
		{

			int frs = 1;
			int lst = 4;

			int mas[7][7] = { { 0, 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0, 0 },
					  {0, 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0, 0 } };
			int nodes[7]; // ������� �����
			for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
			{
				nodes[i] = 0;
			}
			lst--;
			string expected = "���� �����������";
			Assert::AreEqual(expected, bfs(frs, lst, nodes, mas));

		}

		TEST_METHOD(way02) //����� ���� �� �������������� �������
		{

			int frs = 0;
			int lst = 2;

			int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 0 },
					  { 1, 0, 1, 1, 0, 0, 0 },
					  { 1, 1, 0, 0, 0, 0, 0 },
					  { 0, 1, 0, 0, 1, 0, 0 },
					  { 0, 0, 0, 1, 0, 1, 0 },
					  { 0, 0, 0, 0, 1, 0, 0 },
					  { 0, 0, 0, 0, 0, 0, 0 } };
			int nodes[7]; // ������� �����
			for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
			{
				nodes[i] = 0;
			}
			lst--;
			string expected = "������";
			Assert::AreEqual(expected, bfs(frs, lst, nodes, mas));

		}


		TEST_METHOD(way0) //���� ����������� 
		{

			int frs = 2;
			int lst = 8;

			int mas[7][7] = {NULL};
			int nodes[7]; // ������� �����
			for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
			{
				nodes[i] = 0;
			}
			lst--;
			string expected = "������";
			Assert::AreEqual(expected, bfs(frs, lst, nodes, mas));

		}



	};


}