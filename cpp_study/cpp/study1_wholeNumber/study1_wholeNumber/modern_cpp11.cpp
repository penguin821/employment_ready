#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	// auto
	vector<int> v;
	for (auto it = v.begin(); it != v.end(); it++) // vector<int>::iterator 같은 형식 한방에 해결
	{
		cout << *it << endl;
	}

	// 주의할점!!!!!!!!!!!!!!
	// auto는 const 와 &(참조)를 무시한다
	auto a = 1;
	int& ref = a;
	const int ref1 = a;

	for (vector<int>::size_type it = 0; it < v.size(); it++) // vector<int>::iterator 같은 형식 한방에 해결
	{
		int& data = v[it];
		data = 100; // 이렇게 하면 데이터가 100으로 바뀜

		auto data = v[it];
		data = 200; // 이렇게 하면 참조가 무시되어서 안바뀜
	}


	return 0;
}