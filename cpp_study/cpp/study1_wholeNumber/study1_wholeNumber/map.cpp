#include <iostream>
#include <map>
using namespace std;

class Player
{
	int m_id;
};

int main()
{
	// 10만명 플레이어가 입장한다 치면 push back으로 해주면 됨
	// 그러나 그 중 5만명이 랜덤으로 퇴장하고 나머지 5만명 중에서
	// 원하는 플레이어 아이디를 검색하려면?
	// 그냥 처음부터 다 하나하나 찾아보는 수 밖에 없음;;
	
	// list vector 같은 선형 구조의 치명적인 단점
	// 원하는 조건의 데이터를 빠르고 효율적으로 찾을 수 없다

	// map은 연관 컨테이너, 균형 이진 트리(AVL), 노드 기반
	
	class Node
	{
		Node* m_left;
		Node* m_right;

		//int m_key;
		//Player* m_value;
		pair<int, Player*> m_data;
	};
	srand(static_cast<unsigned int>(time(nullptr)));
	// map은 key 와 value로 구성
	map<int, int> m;

	// 10만 입장
	for (int i = 0; i < 100'000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randVal = rand() % 50000;

		// 맵의 erase 방법은 4가지가 있음
		// erase by key
		m.erase(randVal);
	}

	// 원하는 값 찾기
	map<int, int>::iterator findIt = m.find(10000);
	// ()안은 키값, find의 결과값은 이터레이터임
	if (findIt != m.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}

	// 똑같은 키 값을 중복 erase 한다면?
	// 똑같은 키값을 erase 하면 나중에 들어온 명령이 그냥 씹히고 큰 문제는 발생안함

	// 똑같은 키 값, 다른 value 값을 중복 insert 한다면?
	// 얘도 나중에 입력된 명령 덮어쓰기가 아니라 그냥 씹힘
	// 따라서 값을 변경하고 싶으면 이 방법을 사용하면 안됨

	// map의 순환
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		int key = it->first;
		int value = it->second;

		cout << key << " , " << value << endl;
	}

	// 원하는 값이 있는지 확인하고 없으면 추가, 있다면 수정하고 싶으면
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end()) // 찾았다면
	{
		findIt->second = 200; // 수정
	}
	else // 없다면
	{
		m.insert(make_pair(10000, 200)); // 추가
	}

	// 그냥 m[숫자] 연산자 이용해서 찾으면 되지 않냐?
	m[10000] = 200; // 이거도 위에와 같은 역할을 한다
	// 1만 키값을 가진애가 없으면 200 value로 추가하고
	// 1만 키값을 가진애가 있으면 200 value로 수정하고

	// m[] 연산자 주의사항
	// 만약 검색하거나 호출한답 시고

	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}
	// 이래버리면 m[ ] 에 기존에 없었던 키값이 호출만 되더라도
	// 지 마음대로 해당 키값과 0 value 값으로 해서 map에 추가시켜버린다
	// 매우 조심할것

	// 단순 이터레이터 기준으로 순회한다 치면
	// 연속된 데이터가 한 뭉치로 저장되어 있는 벡터가 map보다 효율적
	// 그러나 삽입 삭제 검색을 한다고 쳤을때 avl트리로 구성된 map이
	// 연속된 데이터가 아니라 각자의 영역이 트리로 연결되어있는 것이므로
	// 벡터보다 더 효율적이다
}