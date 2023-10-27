#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
	// key 가 곧 value 일때
	// key 값 하나 저장되어 있음
	set<int> s;

	s.insert(10);
	s.insert(10); // 씹힘
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(60);
	s.insert(70);
	s.insert(80);

	s.erase(40);

	set<int>::iterator findit = s.find(50);
	if (findit != s.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}

	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "------------------------------------------" << endl;

	multimap<int, int> mm; // 중복 키를 허용하는 map

	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));

	// mm[1] = 600 이 문법이 안먹힘

	mm.erase(1); // 키 값이 1인 모든 value가 날라감
	unsigned int count = mm.erase(1); // 이렇게 하면 삭제된 갯수만큼 카운트 올라감

	multimap<int, int>::iterator findIt = mm.find(1);
	// 처음 발견한애 다음꺼 삭제하고 싶으면 ++findIt
	if (findit != s.end())
		mm.erase(findIt); // 이렇게 하면 처음 발견한 애만 삭제

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	// 나중에 auto itPair 로 대체 가능
	itPair = mm.equal_range(1);
	// 키 값이 1인 애의 시작 주소 = first
	// 키 값이 1인 애의 마지막 다음 주소값 = second
	
	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	mm.lower_bound(1); // 키 값이 1인 애의 시작 주소
	mm.upper_bound(1); // 키 값이 1인 애의 마지막 다음 주소값

	multimap<int, int>::iterator itBegin = mm.lower_bound(1);
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);

	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "------------------------------------------" << endl;

	multiset<int> ms; // 중복을 허용하는 set
	// multimap 이랑 돌아가는 방식 같음

	cout << "------------------------------------------" << endl;

	/*
	실무에선 멀티맵 멀티셋 거의 단 한번도 이용안함
	set 같은 경우 서버에서 가끔 플레이어든 몬스터든 ID 목록이 필요한데
	여러개의 ID 중에 내가 찾아야하는 ID를 빨리 찾아야 한다 하면
	set 하나 만들어서 내가 찾아본 ID들을 실시간으로 넣어서
	해당 set를 이용하여 코드를 짜는 방식에서 쓰는 정도?
	*/

	/*
	면접에선 set map 의 구조적인 문제, 세부족인 문제도 나오지만
	경우에 따라서 map 과 multimap의 차이도 물어봄

	따라서 map set multimap multiset의 기본 개념 정도는 숙지해야함
	*/
	return 0;
}