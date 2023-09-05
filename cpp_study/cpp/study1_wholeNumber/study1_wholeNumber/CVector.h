#pragma once
#include <iostream>
using namespace std;

template <typename T>
class CVector
{
public:
	CVector();

	CVector(int size)
	{

	}

	CVector(int size, T data)
	{

	}

	~CVector();
public:
	int size() 
	{
		return m_size;
	}

	void resize(int size)
	{
		if (m_capacity < size)
			m_capacity = size;
		m_size = size;
	}

	int capacity()
	{
		return m_capacity;
	}

	void clear()
	{

	}

	void reserve(int size)
	{

	}

	void push_back(T data)
	{

	}

	T operator[](int num)
	{
		return m_data[num];
	}

private:
	int m_size;
	int m_capacity;
	T m_data[];
};

/*
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << "size : " << v.size() << ", "
		<< "capacity : " << v.capacity() << endl;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
*/
