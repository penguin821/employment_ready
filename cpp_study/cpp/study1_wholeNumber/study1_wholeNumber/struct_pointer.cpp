#include <iostream>
#include "Header.h"
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

bool IsRareItem(Item* item)
{
	return item->m_rarity > 2;
}

Item* SearchItem(Item items[], int count, bool(*select)(Item* item))
{
	for (int i = 0; i < count; i++)
	{
		Item* tem = &items[i];
		// 조건
		if (select(tem))
			return tem;
	}
	return nullptr;
}

int main()
{
	// <함수 포인터>
	/*
	1. 포인터		*
	2. 변수이름		pointer
	3. 데이터 타입	int
	*/
	int a = 10;
	typedef int DATA;
	DATA* pointer = &a;

	typedef int(FUNC_A)(int a, int b); // 옛날 문법
	typedef int(FUNC_B)(int, int); // 옛날 문법
	using FUNC_A = int(int, int);
	using FUNC_B = int(int a, int b); // 요즘 문법, 모던 c++

	/*
	1. 포인터		*
	2. 변수이름		fn
	3. 데이터 타입	함수(인자는 int 2개 받아 int 반환하는)
	*/
	int result = Add(2, 3); // 함수의 이름은 함수의 시작 주소(배열과 유사)
	cout << result << endl;
	FUNC_A* fn = Add; // C언어 호환성 덕분에 & 생략 가능
	FUNC_A* fn = &Add; // 근데 습관적으로 붙이는게 더 좋음
	// FUNC_A* fn = Sub;
	// 함수 포인터를 이용하면 이거 하나만 바꿔주면 얘를 이용한 동작이 다바뀜
	result = fn(2, 3);
	cout << result << endl;
	result = (*fn)(2, 3); // (*함수명) 이건 접근 연산자, 함수 포인터에선 이렇게 해도 함수 주소임

	Item items[10] = {};
	items[3].m_rarity = 3;
	Item* rareItem = SearchItem(items, 10, IsRareItem);  
	
	// ---------------------------------------------------------------------
	// <클래스 맴버 함수 포인터>
	typedef int(*FUNC_B)(int, int); // 함수 포인터
	typedef int(Object::*m_FUNC)(); // 멤버 함수 포인터
	Knight k;
	k.GetHp();
	m_FUNC mf = &Object::GetHp;
	(k.*mf)();

	Knight* k1 = new Knight();
	(*k1.*mf)();
	(k1->*mf)();
	delete k1;
}