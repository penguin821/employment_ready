#include <iostream>
#include <vector>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(rand() % 100);
	}

	// 1. num�̶�� ���ڰ� ���Ϳ� �ִ��� Ȯ���ϴ� ���
	{
		int number = 58;

		for (auto it = v.begin(); it != v.end(); it++)
		{

		}
		
		bool found = false;
		vector<int>::iterator it; // �� �� �ϳ��� ����� ����
	}

	// 2. 11�� ���������� ���ڰ� ���Ϳ� �ִ��� Ȯ���ϴ� ���
	{
		bool found = false;
		vector<int>::iterator it; // �� �� �ϳ��� ����� ����
	}

	// 3. Ȧ���� ������ ����
	{
		int count = 0;
	}

	// 4. ���� �� ��� ���� ��3
	{

	}

	return 0;
}