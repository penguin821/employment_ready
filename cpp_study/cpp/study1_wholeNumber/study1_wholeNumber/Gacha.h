#pragma once
#include <iostream>
using namespace std;

template<typename T,int SIZE>
class Gacha
{
public:
	T GetRandomData()
	{
		cout << "gacha all" << endl;
		int idx = rand() % SIZE;
		return m_data[idx];
	}
public:
	T m_data[SIZE];
};

// Ŭ�������� double�� Ÿ�Կ� ���ؼ��� ����ó���� �ϰ���� ���
// ���ø� Ư��ȭ
template<int SIZE>
class Gacha<double, SIZE>
{
public:
	double GetRandomData()
	{
		cout << "gacha double" << endl;
		int idx = rand() % SIZE;
		return m_data[idx];
	}
public:
	double m_data[SIZE];
};