#pragma once
class CVector
{
public:
	CVector();
	~CVector();
public:
	int size();
	int capacity();


private:
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