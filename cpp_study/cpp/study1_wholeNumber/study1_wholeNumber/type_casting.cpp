#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	/*
	1. static_cast
	2. dynamic_cast
	3. const_cast
	4. reinterpret_cast
	*/

	// 1. static_cast : 타입 원치겡 비춰볼 때 상식적인 캐스팅만 허용
	// int <-> float
	// 부모* -> 자식* 다운캐스팅 (단 안정성은 보장 못함)

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	// 부모->자식, 자식->부모
	Player* p = new Knight();
	Knight* k = static_cast<Knight*>(p);

	// 2. dynamic_cast : 상속 관계에서의 안전 형변환
	// RTTI (RunTime Type Information)
	// 프로그램 실행 중에 개체의 형식이 결정될 수 있도록 하는 메커니즘
	// 다형성을 활용하는 방식, 실행 중에 타입을 확인할 수 있음
	// 따라서 다형성을 성립해야 다이나믹 캐스트를 이용할 수 있음
	// virtual 함수를 무조건 이용해야 객체의 메모리에 가상 함수 테이블
	// (vftable) 주소가 기입되면서 다형성을 성립함
	// ★★만약 잘못된 타입으로 캐스팅하면 nullptr 반환해줌★★
	// 이를 이용해서 맞는 타입으로 캐스팅 했는데 확인가능

	Knight* k1 = dynamic_cast<Knight*>(p);

	// 그렇다면 확인까지 다해주는 다이나믹 쓰는게 훨 낫지 않냐?
	// 확인까지 해주다보니 코드가 더 무겁고 시간도 오래 걸림
	// 부모에 타입 멤버를 만들어줘서 자식들이 어떤 타입인지
	// 저장시켜서 비교는 그걸로 하고 형변환은 static_cast 쓰는게 일반적

	// 3. const_cast : const를 붙이거나 뗄때 쓴다

	// 4. reinterpret_cast : 가장 강력하고 위험한 형태의 캐스팅
	// 포인터랑 전혀 관계없는 다른 타입으로 변환
	__int64 address = (__int64)k1;
	__int64 address = reinterpret_cast<__int64>(k1);
	Dog* d = reinterpret_cast<Dog*>(k1);
	// 스태틱이나 다이나믹은 두 클래스 간 뭔가 상관관계가 있어야
	// 하지만 reinterpret은 보이는것 처럼 전혀 상관 없는 클래스
	// 사이도 강제로 바꿔줌
	
	void* p = malloc(1000);
	Dog* dd = (Dog*)p; // C 스타일
	Dog* dd = reinterpret_cast<Dog*>(p); // 이럴때 종종 사용

	// 이제는 (Dog*) 이런식의 C스타일 형변환은 잊고
	// 위 4가지 형변환을 활용해야함
}