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
	 
	deque<int> dq;

	dq.push_back(1);
	// capacity 없음, 여유분 잡는게 아니라 리스트처럼 새 데이터 묶는거라
	dq.push_front(2);

	return 0;
}