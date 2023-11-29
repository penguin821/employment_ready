#include <iostream>
#include <vector>
#include <map>
#include "Knight.h"
using namespace std;

void test(int a)
{
	cout << endl;
}

void test(int* a)
{
	cout << endl;
}

int main()
{
	// auto
	{
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
	}
	// 중괄호 초기화
	{
		int a = 0;
		int b(0);
		int c{ 0 };

		Knight k1;
		Knight k2 = k1; // 복사 생성자 (대입이 아님)
		Knight k3(k2);
		Knight k4{ k3 };

		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);

		vector<int> v2(3,1); // 1만 3개 들어감
		vector<int> v3{ 1,2,3,4 };
		int arr[] = { 1,2,3,4 }; // 처럼 들어간다
		// 1. 즉 컨테이너와 잘 어울리는 초기화 방법이다.
		
		// 2. 축소 변환을 방지해줌
		int x = 0;
		double z = x;
		double y{ x }; // 축소 변환 필요하다고 에러뜸
		
		// 3. initializer list
		Knight k4(); // 이건 k4 클래스 변수가 아니라 k4 함수호출임
		Knight k4{};
		// Knight k5{ 1,2,3 }; 얘도 벡터처럼 이런식으로 초기화하고 싶으면
		// Knight (initializer_list<int> a) 생성자 만들어주면 됨
		// 다만 문제는 이걸 만들면 인자 1,2,3개짜리 받는 생성자 따로 만들어줘도
		// 무조건 이니셜라이저 리스트 생성자만 탐, 그것만 주의
	}

	// nullptr

	{
		int* ptr = NULL; // Null은 사실상 0이랑 같다
		test(0);
		test(NULL); // NULL이 상수 인자 받는 함수로 들어가버림
		test(nullptr);

		// nullptr 쓰는 이유, 위와 같은 오동작 방지 + 가독성
		nullptr_t a; // auto 쓰면 얘로 바뀜
	}
	return 0;
}