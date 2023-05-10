#include <iostream>
using namespace std;

unsigned char flag; // 부호 비트 생각해서 웬만하면 음수 안되게 생성

int main()
{
	// 게임 서버에서 아이디를 발급할때
	// 그 아이디에 온갖 게임 정보를 구겨넣을때 씀
	// - 대표적으로 Bitflag

	/*
	~ : bitwise not
		단일 숫자의 모든 비트를 대상으로 0은 1, 1은 0으로 뒤바꿈

	& : bitwise and
		두 숫자의 모든 비트 쌍을 대상으로 and 처리

	| : bitwise or
		두 숫자의 모든 비트 쌍을 대상으로 or 처리

	^ : bitwise xor
		두 숫자의 모든 비트 쌍을 대상으로 xor 처리
		두 숫자가 같으면 0 다르면 1로 처리

	<< : 비트 좌측 이동
		비트열을 N만큼 왼쪽으로 이동
		왼쪽의 넘치는 N개의 비트는 버림, 새로 생성되는 N개의 비트는 0
		*2룰 할 때 자주 보임 (*2를 할때 컴파일러가 주로 이렇게 처리함)
		 
	>> : 비트 우측 이동
		비트열을 N만큼 오른쪽으로 이동
		오른쪽의 넘치는 N개의 비트는 버림
		왼쪽에서 생서되는 N개의 비트는
			- 부호 비트가 존재할 경우 부호 비트를 따라감 (부호 있는 정수라면 이 부분을 유의)


	*/

	// 실습 0b0000 에 [무적][변이][스턴][에어본] 상태 이상 넣을거임

	// 무적 상태일때
	flag = (1 << 3);
	cout << flag << endl;
	// flag = 8 해서 1000(2) 만들 수 있지만 나중에 
	// 64비트 가까이 쓰면 어떻게 매번 정수값을 알아서 넣을것인가?
	// 
	const int INVINCIBLE = 3;
	const int STUNED = 2;

	flag = (1 << INVINCIBLE);

	// 변이 상태 추가 (무적 + 변이)
	flag |= (1 << 2);
	cout << flag << endl;

	// 무적인지 확인하고 싶다? (다른 상태는 관심없음)
	// bitmask (맞는지 아닌지 마스크를 대봐서 확인한다)
	unsigned char mask = (1 << INVINCIBLE);
	bool bIsInvinsible = ((flag & mask) != 0);

	// 무적이거나 스턴 상태인지 확인하고 싶다?
	mask = ((1 << INVINCIBLE) | (1 << STUNED));
	bool bIsInvinsibleAndStuned = ((flag & mask) != 0);

}