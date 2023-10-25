#include <iostream>
#include <deque>
using namespace std;

int main()
{
	// 시퀀스 컨테이너 : 데이터가 삽입 순서대로 나열되는 형태
	// 종류 : vector list deque

	// deque : double ended queue 데크
	// 가끔 서버 버퍼 만들어줄때 사용하는 사람이 있긴함 (잘 이용 안함)
	
	// 벡터처럼 배열(데이터의 묶음)처럼 사용되나 데이터 추가시
	// 메모리 할당 정책이 다름
	// 
	// capacity 없음, 여유분 잡는게 아니라 리스트처럼 새 데이터 묶는거라 
	
	deque<int> dq(3,1);
	// [1 1 1 a] a는 빈칸


	dq.push_back(2);
	// [1 1 1 2]
	dq.push_back(2);
	// [1 1 1 2]
	// [2 a a a]

	dq.push_front(3);
	// [a a a 3]
	// [1 1 1 2]
	// [2 a a a]
	dq.push_front(3);
	// [a a 3 3]
	// [1 1 1 2]
	// [2 a a a]

	// 중간 삽입-삭제 (bad - bad)
	// 삽입 하거나 삭제하면 발생하는 밀림 현상과 빈 공간을 해결하기 위해
	// 벡터처럼 밀거나 땡겨온다
	
	// 처음 끝 삽입-삭제 (good - good)

	// 임의 접근 (good)
	// 4칸 한덩어리 마다 정보가 저장되어 있어서
	// 접근할때 해당 덩어리에 먼저 접근 후 안에서 원하는 원소를
	// 찾아내는 구조라 임의 접근도 효율적

	// 결론 : 양 옆으로 접근이 삽입 삭제, 접근이 가능한 벡터다

	return 0;
}