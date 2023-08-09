#pragma once
#include <iostream>

template <typename T>
class CVector
{
public:
	CVector();
	CVector(int size);
	CVector(int size, T data);
	~CVector();
public:
	int size();
	void resize(int size);
	int capacity();
	void clear();
	void reserve(int size);
	void push_back(T data);
	T operator()(int num);
	ostream operator<<(ostream& os, )
private:
	int m_size;
	int m_capacity;
	T m_data[m_size];
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