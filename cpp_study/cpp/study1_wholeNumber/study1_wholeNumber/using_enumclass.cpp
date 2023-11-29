#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 2 템플릿
template<typename T> // 현재 함수 안이라 빨간줄
//typedef void // 템플릿에 typedef 지정할 수 없다고 나옴
using List = std::list<T>;


enum PlayerType : short // 이런식으로 원하는 바이트 단위 가능
{
	None,
	Knight,
	Archer,
	PT_Knight
};

enum MonsterType // unscoped enum
{
	//None, // 재정의 했다고 오류남
	Mush,
	Venom,
	MT_Mush // 그래서 이런식으로 앞에 구분지어줌
};

enum class OBtype
{
	None,
	player,
	Mon,
	Pro
};


int main()
{
	// using
	// 1 직관성
	typedef void (*MyFunc)();
	using MyFunc = void(*)();

	typedef vector<int>::iterator vecit;
	using Vecit = vector<int>::iterator;

	List<int> li;
	li.push_back(10);
	li.push_back(20);
	li.push_back(30);

	// enum class (scoped enum)
	// 1. 이름공간 관리 (scoped)
	// 2. 암묵적인 변환 금지
	double val = PT_Knight;
	// double val1 = player; 정의되어 있지 않다고 뜸
	double val2 = static_cast<double>(OBtype::player);
}