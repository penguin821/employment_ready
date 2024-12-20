#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Knight knight1(1,2); // 기본 생성자

	Knight knight2 = knight1; // 복사 생성자
	Knight knight3(knight2);

	knight2 = knight1; // 복사 대입 연산자

	// 잘 돌아감, 즉 클래스끼리 복사생성은 암시적으로도 가능함
	// [얕은 복사] 멤버 데이터를 비트열 단위로 똑같이 복사 (메모리 영역값 그대로 복사)
	// 그러나 맴버 변수로 포인터나 참조형 데이터가 있는 순간 얘기가 달라짐
	// 포인터의 값이랑 포인터가 가르키는 주소값도 그대로 복사되기 때문에
	// 셋다 같은 포인터를 가리킴
	// delete 한다던가 포인터로 가리키는 값을 바꾸면 복사된 애들 다 바뀜

	// 그래서 이번에 배운 복사 생성자, 복사 대입 연산자를 통해
	// 동적할당으로 데이터 멤버변수를 만들어주자
	// 그럼 각자 다른 주소값에 참조하는 대상도 따로 복사해서 만들어줌
	// [깊은 복사] 멤버 데이터가 참조, 주소값일때 데이터를 새로 만들어줌
	// 새로운 객체를 생성해서 걔를 각자 따로 가리키게 만듦

	// -------------------------------------------------------

	/*
	- 암시적 복사 단계
	1. 부모 클래스 복사 생성자 호출
	2. 멤버 클래스 복사 생성자 호출
	3. 멤버가 기본 타입일 경우 메모리 복사(얇은 복사)

	- 명시적 복사 단계
	1. 부모 클래스의 <기본> 생성자 호출
	2. 멤버 클래스의 <기본> 생성자 호출
	그래서 자식 클래스에 복사 생성자를 만들어 주면
	부모 클래스로부터 물려받은 맴버랑 멤버 클래스는 정상적으로 복사가 안됨
	왜냐 기본 생성자를 호출하니까,
	그래서 자식 복사 생성자에 부모와 멤버 클래스의 복사생성자를 추가 기입 해줘야함
	*/

	// -------------------------------------------------------

	/*
	- 암시적 복사 대입 연산자
	1. 부모 클래스 복사 대입 연산 호출
	2. 멤버 클래스 복사 대입 연산 호출
	3. 멤버가 기본 타입일 경우 메모리 복사(얇은 복사)

	- 명시적 복사 대입 연산자
	얘는 진짜 아무것도 안해줘서 걍 내가 복사 대입 연산자 만들때
	모든 클래스형과 부모 자식 계승 멤버들 다 고려해서 초기화 해줘야함
	*/
}