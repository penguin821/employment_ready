#include <iostream>
#include <vector>
#include "CVector.h"

using namespace std;

int main()
{
	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << "size : " << v.size() << ", " << "capacity : " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "-------------------" << endl;

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	cout << "----------------------------------------------" << endl;

	CVector<int> cv;

	for (int i = 0; i < 100; i++)
	{
		cv.push_back(i);
		cout << "size : " << cv.size() << ", " << "capacity : " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << cv[i] << endl;
	}

	cout << "-------------------" << endl;

	for (vector<int>::iterator iter = cv.begin(); iter != cv.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	return 0;
}