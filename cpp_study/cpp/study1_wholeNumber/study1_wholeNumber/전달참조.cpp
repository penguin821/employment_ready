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

	Knight(const Knight& knight) // 복사 생성자
	{
		cout << "const knight&" << endl;
	}

	Knight(Knight&& knight) noexcept // 이동 생성자
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