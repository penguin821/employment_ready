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

	// ���� = �Լ� ��ü�� ����� ����

	// ���� ���� ����
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
			cout << "������ ID : " << findif->m_id << endl;
	}

	// ���� ��� ����
	{
		// �̷������� �����ε� ���� ����
		// Ŭ���� (closure) = ���ٿ� ���� ����������� ������� ��ü
		auto isUniqueLamda =
		[](Item& item)->int {return item.m_rarity == Rarity::Unique; }; // ���� ǥ����
		// ���� ���� ���ϴ� �ڷ������� ����ֱ� ���ϸ� ()->�ڷ���{} ���� ����

		auto findif = find_if(v.begin(), v.end(), isUniqueLamda);
		auto findif = find_if(v.begin(), v.end(), 
			[](Item& item){return item.m_rarity == Rarity::Unique; });
	}

	// ���ٿ� ���� �ް� ������
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
		// [] ĸó : �Լ� ��ü ���ο� ������ �����ϴ� ����� ����
		// �⺻ ĸ�� ��� : ��(����) ���(=), ���� ���(&)
		auto ItemFindLambda = [=](Item& item) {return item.m_id == find_id; };
		// �̷� ������ �ܺ� ������ �ٷ� �޾ƿ� �� �ִ�

		int itemid = 4;
		Rarity rare = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		auto ItemFindLambda1 = [=](Item& item) {
			return item.m_id == itemid && item.m_rarity==rare &&
				item.m_type==type; }; // �̷������� �ѹ��� �������� ����

		// ���� �������� ĸ�ĸ� �ٸ��� �޾ƿ��� �ʹ�
		auto ItemFindLambda2 = [=, &rare](Item& item) {
			return item.m_id == itemid && item.m_rarity == rare &&
				item.m_type == type; }; // ��� ����, ������ ����

		auto ItemFindLambda3 = [&itemid,&rare,type](Item& item) {
			return item.m_id == itemid && item.m_rarity == rare &&
				item.m_type == type; }; // ���̵� ��� ����, Ÿ���� ����

		// C++ ���� ĸ�Ŀ� ���� �ϳ��ϳ� ��� ĸ������ ���ִ°�
		// �Ǽ��� �����ϰ� �ð������� �����ϱ⵵ ���ϴ�
		// Ŭ���� ���ο��� ���ٷ� �ɹ������� ���� this �����Ϳ� ��������
		// �����簡 �� �� ����, �� �⺻ ĸ�� ��� ������ [=][&] �����ϸ� ��������
	}

	return 0;
}