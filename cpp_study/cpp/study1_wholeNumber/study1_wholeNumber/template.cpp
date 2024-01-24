#include <iostream>
#include "Header.h"

using namespace std;

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// Ư�� Ÿ�Կ� ���ؼ��� ���ø��� �ٸ� ��Ģ�� �����Ű�� ������
// ���ø� Ư��ȭ

template<>
void Print(Knight a)
{
	cout << "Knight HP : " << a.m_hp << endl;
}

template<typename T1>
T1 Add(T1 a,T1 b)
{
	cout << a + b << endl;
}

template<typename T3, typename T4>
void Print(T3 a, T4 b)
{
	cout << a << " , " << b << endl;
}

int main()
{
	// �Լ� �������� ����
	// 1. �ñ״�ó�� �ȸ����� ���Ұ� (���� Ÿ��, ���� ���� ���)
	// 2. ���¸� ���� �� ���� (�������� �������ε��ٰ� �Լ��̱� ����)

	// �Լ� ��ü(Functor) : �Լ�ó�� �����ϴ� ��ü
	// ��� ��� : �ڷ��� operator()(���� or ��ĭ) ������ �����ε�
	Knight k;
	k(); // �������� ���� �̿��Ұ�

	// ���ø� : �Լ��� Ŭ������ ���� Ʋ
	// 1. �Լ� ���ø�
	// 2. Ŭ���� ���ø�
	Print(50);
	Print(50.f);
	Print(50.0);
	Print("Hello world");
	// ���� �ٸ� ������ ȣ���Ҷ����� �����Ϸ��� ���ø��� ���ؼ� �������
	// Print<int>(50); ���� �����Ϸ��� �˾Ƽ� ���������� Ư�� �ڷ�������
	// ����������� �ϸ� ������ �����ϸ� �ȴ�
	Print("Hello world", 100);

	// �׷��� Print(k) �ϸ� ���ø��� ��Ÿ�� 19:22
	// �ذ��� 2��, ������ �����ε� or Ŭ���� ���ø�
	Knight k1;
	Print(k1);

	// ==================================================================
	srand(static_cast<unsigned int>(time(NULL)));
	// time�� ���������� __int64�ε� srand ���ڰ��� unsigned int �䱸�ϹǷ�
	// ����ȯ���� �ٲ��ذ�
	Gacha<int, 10> g1;
	for (int i = 0; i < 10; i++)
	{
		g1.m_data[i] = i;
	}
	int val1 = g1.GetRandomData();
	cout << val1 << endl;

	Gacha<int, 20> g2;
	for (int i = 0; i < 20; i++)
	{
		g2.m_data[i] = i;
	}
	int val2 = g2.GetRandomData();
	cout << val2 << endl;

	Gacha<float, 10> g3;
	for (int i = 0; i < 10; i++)
	{
		g3.m_data[i] = i + 0.5f;
	}
	float val3 = g3.GetRandomData();
	cout << val3 << endl;

	Gacha<double, 10> g4;
	for (int i = 0; i < 10; i++)
	{
		g4.m_data[i] = i;
	}
	double val4 = g4.GetRandomData();
	cout << val4 << endl;

	// g1 = g2; �ȵȴ�. 
	// ���ø��� ���ڰ� ���Ƶ� ���ڰ��� �޶����� �ٸ� Ŭ������ �ν���


}

//ostream& operator <<(ostream& os, const Knight& copy)
//{
//	os << copy.m_hp;
//	return os;
//}