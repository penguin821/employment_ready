#include <iostream>
#include <algorithm>

using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{
		cout << "knight" << endl;
	}

	Knight(const Knight& knight) // ���� ������
	{
		cout << "const knight&" << endl;
	}

	Knight(Knight&& knight) noexcept // �̵� ������
	{
		cout << "knight&&" << endl;
	}

public:
	int m_hp = 100;
	Pet* m_pet = nullptr;
};

void TestKnight_RValueRef(Knight&& knight)
{

}

int main()
{

}