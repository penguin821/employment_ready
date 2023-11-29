#include <iostream>
#include <vector>
#include <map>
#include "Knight.h"
using namespace std;

void test(int a)
{
	cout << endl;
}

void test(int* a)
{
	cout << endl;
}

int main()
{
	// auto
	{
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
	}
	// �߰�ȣ �ʱ�ȭ
	{
		int a = 0;
		int b(0);
		int c{ 0 };

		Knight k1;
		Knight k2 = k1; // ���� ������ (������ �ƴ�)
		Knight k3(k2);
		Knight k4{ k3 };

		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);

		vector<int> v2(3,1); // 1�� 3�� ��
		vector<int> v3{ 1,2,3,4 };
		int arr[] = { 1,2,3,4 }; // ó�� ����
		// 1. �� �����̳ʿ� �� ��︮�� �ʱ�ȭ ����̴�.
		
		// 2. ��� ��ȯ�� ��������
		int x = 0;
		double z = x;
		double y{ x }; // ��� ��ȯ �ʿ��ϴٰ� ������
		
		// 3. initializer list
		Knight k4(); // �̰� k4 Ŭ���� ������ �ƴ϶� k4 �Լ�ȣ����
		Knight k4{};
		// Knight k5{ 1,2,3 }; �굵 ����ó�� �̷������� �ʱ�ȭ�ϰ� ������
		// Knight (initializer_list<int> a) ������ ������ָ� ��
		// �ٸ� ������ �̰� ����� ���� 1,2,3��¥�� �޴� ������ ���� ������൵
		// ������ �̴ϼȶ����� ����Ʈ �����ڸ� Ž, �װ͸� ����
	}

	// nullptr

	{
		int* ptr = NULL; // Null�� ��ǻ� 0�̶� ����
		test(0);
		test(NULL); // NULL�� ��� ���� �޴� �Լ��� ������
		test(nullptr);

		// nullptr ���� ����, ���� ���� ������ ���� + ������
		nullptr_t a; // auto ���� ��� �ٲ�
	}
	return 0;
}