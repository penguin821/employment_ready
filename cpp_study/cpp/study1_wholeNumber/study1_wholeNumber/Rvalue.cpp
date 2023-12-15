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

	Knight(Knight&& knight) // 이동 생성자
	{
		cout << "knight&&" << endl;
	}

	~Knight()
	{
		if (m_pet)
			delete m_pet;
	}

	void PrintInfo()
	{
		// read only만 가능
	}

	void ConstPrintInfo() const
	{
		// m_hp = 200; const라 안됨
	}

	void operator=(const Knight& knight)
	{
		cout << "operator= const Knight&" << endl;

		m_hp = knight.m_hp;
		//m_pet = knight.m_pet; // 이렇게 하면 펫 마저도 똑같이 복사되어버린다 (얕은 복사)
		if (knight.m_pet) // 복사대상이 펫을 소유중이라면
			m_pet = new Pet(*knight.m_pet); // 깊은복사, 문제는 이렇게 복사해야할 값이 많아질수록
		// 비효율적이다, 그리고 이렇게 밖에 할 수 없었던 이유는 knight값을 건드는 순간 원본도 건드려서 함부러 수정 못함
		
	}

	void operator=(Knight&& knight) noexcept // noexcept 얘는 에러를 일으키지 않을거라고 힌트주는것
	{
		cout << "operator= Knight&&" << endl;

		// 얕은 복사 방식으로 해도 아무 문제가 없음
		m_hp = knight.m_hp;
		m_pet = knight.m_pet;
		knight.m_pet = nullptr;
	}

public:
	int m_hp = 100;
	Pet* m_pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	knight.m_hp = 200; // 수정해봤자 복사라 원본 안바뀜
	// 지금이야 hp 하나지만 복사해야할 맴버가 많아질수록 비효율적임
	// 따라서 모든걸 다 복사해야하고 원본도 못넘겨줌
}

void TestKnight_LValueRef(Knight& knight)
{
	knight.m_hp = 200; // 이제 복사가 아니라 원본을 가져옴
}

void TestKnight_ConstLValueRef(const Knight& knight)
{
	//knight.m_hp = 200; // const라 이제 원본값 가져오는것만 되고 수정 못함
	//knight.PrintInfo(); // const 형식이 아니라고 에러남
	knight.ConstPrintInfo();
}

// =========================================================================================
// 그래서 모던 C++11으로 넘어오면서 오른값을 참조받을 수 있게 해주는 문법이 생김
void TestKnight_RValueRef(Knight&& knight) // 함수호출 이후에 knight는 이용 안할거니까 니 마음대로 해도 된다
// = 이동 대상이 되었다
{
	knight.m_hp = 200;
	knight.PrintInfo();
}
// =========================================================================================

int main()
{
	/*
	왼값(lvalue) vs 오른값(rvalue)
	왼값(lvalue)	: 단일식울 넘어서 계속 지속되는 개체
	오른값(rvalue)	: lvalue가 아닌 나머지 (임시 값(임시객체 포함), 열거형, 람다, i++ 등)
	*/

	int a = 3;
	// 3 = a;
	// (a++) = 5;
	// 위에 두개 다 에러남, 이런식으로 오른값 왼값 나눔

	Knight k1;
	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight()); // 임시객체는 말 그대로 지속성 없는 임시값이기 때문에 에러남
	TestKnight_ConstLValueRef(Knight());
	//TestKnight_RValueRef(k1); // 이제 왼값을 못받음
	TestKnight_RValueRef(Knight()); // 이제 왼값을 못받음

	// 문법만 다를뿐 결론적으로 Copy 제외하고 셋 다 똑같이 참조하는게 다임

	Knight k2;
	k2.m_pet = new Pet();
	k2.m_hp = 1000;

	Knight k3;
	k3 = static_cast<Knight&&>(k2); // 원본은 날려도 된다, 즉 k2를 k3로 이동시키는것
	k3 = move(k2); // 오른값 참조로 캐스팅한거랑 동작 같음
	// 이거 이용해서 유니크 포인터도 옮길 수 있음
}