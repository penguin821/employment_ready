#include <iostream>
#include <vector>

#include <algorithm>

/*
find
find_if
count
count_if
all_of
any_of
none_of
for_each
remove
remove_if
*/

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

		//-------------------------------------------------
		auto it = find(v.begin(), v.end(), number); // ��ã���� v.end() ����
		if (it != v.end())
			cout << *it << endl;
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

		//-------------------------------------------------
		struct Divide11
		{
			bool operator()(int n)
			{
				return (n % 11) == 0;
			}
		};

		auto it = find_if(v.begin(), v.end(), Divide11());
		auto it1 = find_if(v.begin(), v.end(), [](int n) {return (n % 11) == 0; }); // ���ٸ� ��� ����

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

		//-------------------------------------------------

		count = count_if(v.begin(), v.end(), [](int n) {return (n % 2) != 0; }); // ��� ���ͷ����� �ƴϰ� std��
		cout << count << endl;
		// ��� �����Ͱ� Ȧ���Դϱ�?
		bool is = all_of(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
		bool is1 = any_of(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
		bool is2 = none_of(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
	}
	cout << "===============================================" << endl;
	// 4. ���� �� ��� ���� ��3
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			(*it) *= 3;
			cout << *it << endl;
		}

		//-------------------------------------------------
		cout << "===============================================" << endl;
		for_each(v.begin(), v.end(), [](int& n) {return n *= 3; });
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
	}
	cout << "===============================================" << endl;
	// Ȧ���� �����͸� �ϰ� ����
	{
		/*
		remove ���� ���ǻ���
		���Ϳ� 1 4 3 5 8 2 �� ����ִ� ġ��
		remove Ȧ�� ������ ���빰��
		4 8 2 �� �Ǵ°� �ƴ϶� 4 8 2 5 8 2 �� �ȴ�

		remove �۵� ����� ���� ������ �����ϰ� ��ĭ ���ܿ��ִ°� �ƴ϶� (��ȿ�����̹Ƿ�)  
		�����ϸ� �ȵǴ� �����͸� �հ������� ���������� �����ؿ´�
		�׷��� Ȧ���� �ƴ� 482�� 1,2,3��°ĭ�� �����ؿ°�
		��, �׹�°ĭ���� �ʿ���� �����͵� ���̶�°�

		���� remove�� ����� ����Ϸ���
		*/
		int num = 4;

		auto it = remove(v.begin(), v.end(), num);
		auto it1 = remove_if(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
		// �̷��� �ϸ� ���ͷ����Ͱ� �ʿ���� ������ �������� ����Ŵ
		v.erase(it, v.end());

		// �ѹ濡 �ذ��Ϸ���
		v.erase(remove_if(v.begin(), v.end(), [](int n) {return (n % 2) != 0; }), v.end());
	}


	return 0;
}