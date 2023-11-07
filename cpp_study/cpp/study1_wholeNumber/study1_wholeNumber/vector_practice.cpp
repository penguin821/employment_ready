#include <iostream>
#include <vector>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(rand() % 100);
	}

	// 1. num이라는 숫자가 벡터에 있는지 확인하는 기능
	{
		int number = 58;

		for (auto it = v.begin(); it != v.end(); it++)
		{

		}
		
		bool found = false;
		vector<int>::iterator it; // 둘 중 하나로 결과물 도출
	}

	// 2. 11로 나뉘어지는 숫자가 벡터에 있는지 확인하는 기능
	{
		bool found = false;
		vector<int>::iterator it; // 둘 중 하나로 결과물 도출
	}

	// 3. 홀수인 숫자의 개수
	{
		int count = 0;
	}

	// 4. 벡터 내 모든 숫자 곱3
	{

	}

	return 0;
}