#include <iostream>
#include "Header.h"

using namespace std;

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 특정 타입에 대해서만 템플릿에 다른 규칙을 적용시키고 싶을때
// 템플릿 특수화

template<>
void Print(Knight a)
{
	cout << "Knight HP : " << a.m_hp << endl;
}

template<typename T1>
T1 Add(T1 a,T1 b)
{
	cout << a + b << endl;
}

template<typename T3, typename T4>
void Print(T3 a, T4 b)
{
	cout << a << " , " << b << endl;
}

int main()
{
	// 함수 포인터의 단점
	// 1. 시그니처가 안맞으면 사용불가 (인자 타입, 인자 갯수 등등)
	// 2. 상태를 가질 수 없음 (어디까지나 포인터인데다가 함수이기 때문)

	// 함수 객체(Functor) : 함수처럼 동작하는 객체
	// 사용 방법 : 자료형 operator()(인자 or 빈칸) 연산자 오버로딩
	Knight k;
	k(); // 서버에서 많이 이용할것

	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1. 함수 템플릿
	// 2. 클래스 템플릿
	Print(50);
	Print(50.f);
	Print(50.0);
	Print("Hello world");
	// 각기 다른 버전을 호출할때마다 컴파일러가 템플릿을 통해서 만들어줌
	// Print<int>(50); 만약 컴파일러가 알아서 만들지말고 특정 자료형으로
	// 만들어줬으면 하면 저렇게 선언하면 된다
	Print("Hello world", 100);

	// 그러나 Print(k) 하면 템플릿이 안타짐 19:22
	// 해결방법 2개, 연산자 오버로딩 or 클래스 템플릿
	Knight k1;
	Print(k1);

	// ==================================================================
	srand(static_cast<unsigned int>(time(NULL)));
	// time은 실질직으로 __int64인데 srand 인자값이 unsigned int 요구하므로
	// 형변환으로 바꿔준것
	Gacha<int, 10> g1;
	for (int i = 0; i < 10; i++)
	{
		g1.m_data[i] = i;
	}
	int val1 = g1.GetRandomData();
	cout << val1 << endl;

	Gacha<int, 20> g2;
	for (int i = 0; i < 20; i++)
	{
		g2.m_data[i] = i;
	}
	int val2 = g2.GetRandomData();
	cout << val2 << endl;

	Gacha<float, 10> g3;
	for (int i = 0; i < 10; i++)
	{
		g3.m_data[i] = i + 0.5f;
	}
	float val3 = g3.GetRandomData();
	cout << val3 << endl;

	Gacha<double, 10> g4;
	for (int i = 0; i < 10; i++)
	{
		g4.m_data[i] = i;
	}
	double val4 = g4.GetRandomData();
	cout << val4 << endl;

	// g1 = g2; 안된다. 
	// 템플릿은 인자가 같아도 인자값이 달라지면 다른 클래스로 인식함


}

//ostream& operator <<(ostream& os, const Knight& copy)
//{
//	os << copy.m_hp;
//	return os;
//}