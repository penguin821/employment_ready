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

// 클래스에서 double인 타입에 대해서면 예외처리를 하고싶은 경우
// 템플릿 특수화
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