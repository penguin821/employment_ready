#pragma once
#include <iostream>
using namespace std;

template <typename T>
class CVector
{
public:
	CVector()
	{
		m_size = 0;
		m_capacity = 0;
	}

	CVector(int size)
	{
		m_size = size;
		m_capacity = size;
	}

	CVector(int size, T data)
	{
		m_size = size;
		m_capacity = size;
		T m_data = new T;
	}

	~CVector();
public:
	int size() 
	{
		return m_size;
	}

	int capacity()
	{
		return m_capacity;
	}

	void reserve(int size)
	{

	}

	void push_back(T data)
	{
		if (m_capacity < m_size)
		if (m_size < 1)
		{

		}
	}

	T operator[](int num)
	{
		return m_data[num];
	}

	T begin()
	{

	}

	T end()
	{

	}

	class iterator
	{

	private:
		T* node;
	};

	//CVector operator=(const CVector& copy)
	//{
	//	m_pos = copy.m_pos;
	//	m_pet = new Pet(*copy.m_pet);
	//	return *this;
	//}

private:
	int m_size;
	int m_capacity;
	T m_data[];
};

/*
	CVector v;
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
	for (CVector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
*/
