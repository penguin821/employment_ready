#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	// auto
	vector<int> v;
	for (auto it = v.begin(); it != v.end(); it++) // vector<int>::iterator ���� ���� �ѹ濡 �ذ�
	{
		cout << *it << endl;
	}

	// ��������!!!!!!!!!!!!!!
	// auto�� const �� &(����)�� �����Ѵ�
	auto a = 1;
	int& ref = a;
	const int ref1 = a;

	for (vector<int>::size_type it = 0; it < v.size(); it++) // vector<int>::iterator ���� ���� �ѹ濡 �ذ�
	{
		int& data = v[it];
		data = 100; // �̷��� �ϸ� �����Ͱ� 100���� �ٲ�

		auto data = v[it];
		data = 200; // �̷��� �ϸ� ������ ���õǾ �ȹٲ�
	}


	return 0;
}