#include <iostream>
#include <vector>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;
	for (int i = 0; i < 30; i++)
	{
		v.push_back(rand() % 30);
	}
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "===============================================" << endl;
	// 1. num�̶�� ���ڰ� ���Ϳ� �ִ��� Ȯ���ϴ� ���
	{
		int number = 25;
		bool found = false;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it == number)
			{
				found = true;
				cout << *it << endl;
				break;
			}
		}
	}
	cout << "===============================================" << endl;
	// 2. 11�� ���������� ���ڰ� ���Ϳ� �ִ��� Ȯ���ϴ� ���
	{
		bool found = false;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			if ((*it) % 11 == 0 && (*it!=0))
			{
				found = true;
				cout << "found : " << *it << endl;
				break;
			}
		}

		vector<int>::iterator it; // �� �� �ϳ��� ����� ����
	}
	cout << "===============================================" << endl;
	// 3. Ȧ���� ������ ����
	{
		int count = 0;
		int even = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if ((*it) % 2 != 0)
				count++;
		}
		cout << count << endl;
	}
	cout << "===============================================" << endl;
	// 4. ���� �� ��� ���� ��3
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			(*it) *= 3;
		}
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
	}

	return 0;
}