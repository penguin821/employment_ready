#include <iostream>
#include <vector>

using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item();
	Item(int id, Rarity rare, ItemType type)
	{
		m_id = id;
		m_rarity = rare;
		m_type = type;
	}
	~Item();
public:
	int m_id = 0;
	Rarity m_rarity = Rarity::Common;
	ItemType m_type = ItemType::None;
};
	

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 만드는 문법

	// 람다 배우기 이전
	{
		struct isUniqueItem
		{
			bool operator()(Item& item)
			{
				return item.m_rarity == Rarity::Unique;
			}
		};

		auto findif = find_if(v.begin(), v.end(), isUniqueItem());
		if (findif != v.end())
			cout << "아이템 ID : " << findif->m_id << endl;
	}

	// 람다 배운 이후
	{
		// 이런식으로 뱐수로도 선언 가능
		// 클로저 (closure) = 람다에 의해 실행시점에서 만들어진 객체
		auto isUniqueLamda =
		[](Item& item)->int {return item.m_rarity == Rarity::Unique; }; // 람다 표현식
		// 만약 내가 원하는 자료형으로 뱉어주길 원하면 ()->자료형{} 으로 가능

		auto findif = find_if(v.begin(), v.end(), isUniqueLamda);
		auto findif = find_if(v.begin(), v.end(), 
			[](Item& item){return item.m_rarity == Rarity::Unique; });
	}

	// 람다에 인자 받고 싶을때
	{
		struct isItemFind
		{
			isItemFind(int id) :m_id(id)
			{

			}

			bool operator()(Item& item)
			{
				return item.m_id == m_id;
			}

			int m_id;
		};
		int find_id = 4;
		auto findif = find_if(v.begin(), v.end(), isItemFind(find_id));

		//////////////////////
		// [] 캡처 : 함수 객체 내부에 변수를 저장하는 개념과 유사
		// 기본 캡쳐 모드 : 값(복사) 방식(=), 참조 방식(&)
		auto ItemFindLambda = [=](Item& item) {return item.m_id == find_id; };
		// 이런 식으로 외부 변수를 바로 받아올 수 있다

		int itemid = 4;
		Rarity rare = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		auto ItemFindLambda1 = [=](Item& item) {
			return item.m_id == itemid && item.m_rarity==rare &&
				item.m_type==type; }; // 이런식으로 한번에 여러개도 가능

		// 만약 변수별로 캡쳐를 다르게 받아오고 싶다
		auto ItemFindLambda2 = [=, &rare](Item& item) {
			return item.m_id == itemid && item.m_rarity == rare &&
				item.m_type == type; }; // 레어만 참조, 나머진 복사

		auto ItemFindLambda3 = [&itemid,&rare,type](Item& item) {
			return item.m_id == itemid && item.m_rarity == rare &&
				item.m_type == type; }; // 아이디 레어만 참조, 타입은 복사

		// C++ 에선 캡쳐에 변수 하나하나 어떻게 캡쳐할지 써주는게
		// 실수도 방지하고 시각적으로 이해하기도 편하다
		// 클래스 내부에서 람다로 맴버변수를 쓸때 this 포인터에 가려져서
		// 대참사가 날 수 있음, 즉 기본 캡쳐 모드 통으로 [=][&] 웬만하면 쓰지말것
	}

	return 0;
}