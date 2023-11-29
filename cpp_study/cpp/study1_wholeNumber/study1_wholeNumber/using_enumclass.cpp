#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 2 ���ø�
template<typename T> // ���� �Լ� ���̶� ������
//typedef void // ���ø��� typedef ������ �� ���ٰ� ����
using List = std::list<T>;


enum PlayerType : short // �̷������� ���ϴ� ����Ʈ ���� ����
{
	None,
	Knight,
	Archer,
	PT_Knight
};

enum MonsterType // unscoped enum
{
	//None, // ������ �ߴٰ� ������
	Mush,
	Venom,
	MT_Mush // �׷��� �̷������� �տ� ����������
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
	// 1 ������
	typedef void (*MyFunc)();
	using MyFunc = void(*)();

	typedef vector<int>::iterator vecit;
	using Vecit = vector<int>::iterator;

	List<int> li;
	li.push_back(10);
	li.push_back(20);
	li.push_back(30);

	// enum class (scoped enum)
	// 1. �̸����� ���� (scoped)
	// 2. �Ϲ����� ��ȯ ����
	double val = PT_Knight;
	// double val1 = player; ���ǵǾ� ���� �ʴٰ� ��
	double val2 = static_cast<double>(OBtype::player);
}