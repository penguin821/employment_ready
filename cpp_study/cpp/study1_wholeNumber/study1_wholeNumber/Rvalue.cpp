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

	Knight(Knight&& knight) // �̵� ������
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
		// read only�� ����
	}

	void ConstPrintInfo() const
	{
		// m_hp = 200; const�� �ȵ�
	}

	void operator=(const Knight& knight)
	{
		cout << "operator= const Knight&" << endl;

		m_hp = knight.m_hp;
		//m_pet = knight.m_pet; // �̷��� �ϸ� �� ������ �Ȱ��� ����Ǿ������ (���� ����)
		if (knight.m_pet) // �������� ���� �������̶��
			m_pet = new Pet(*knight.m_pet); // ��������, ������ �̷��� �����ؾ��� ���� ����������
		// ��ȿ�����̴�, �׸��� �̷��� �ۿ� �� �� ������ ������ knight���� �ǵ�� ���� ������ �ǵ���� �Ժη� ���� ����
		
	}

	void operator=(Knight&& knight) noexcept // noexcept ��� ������ ����Ű�� �����Ŷ�� ��Ʈ�ִ°�
	{
		cout << "operator= Knight&&" << endl;

		// ���� ���� ������� �ص� �ƹ� ������ ����
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
	knight.m_hp = 200; // �����غ��� ����� ���� �ȹٲ�
	// �����̾� hp �ϳ����� �����ؾ��� �ɹ��� ���������� ��ȿ������
	// ���� ���� �� �����ؾ��ϰ� ������ ���Ѱ���
}

void TestKnight_LValueRef(Knight& knight)
{
	knight.m_hp = 200; // ���� ���簡 �ƴ϶� ������ ������
}

void TestKnight_ConstLValueRef(const Knight& knight)
{
	//knight.m_hp = 200; // const�� ���� ������ �������°͸� �ǰ� ���� ����
	//knight.PrintInfo(); // const ������ �ƴ϶�� ������
	knight.ConstPrintInfo();
}

// =========================================================================================
// �׷��� ��� C++11���� �Ѿ���鼭 �������� �������� �� �ְ� ���ִ� ������ ����
void TestKnight_RValueRef(Knight&& knight) // �Լ�ȣ�� ���Ŀ� knight�� �̿� ���ҰŴϱ� �� ������� �ص� �ȴ�
// = �̵� ����� �Ǿ���
{
	knight.m_hp = 200;
	knight.PrintInfo();
}

// =========================================================================================

template<typename T> // ���� ���ø��� ������ �����Ѵٸ�?
void Test_TemForwardRef(T&& param)
{
	// const T&& param�� �ϰԵǸ� ������ ������ ������ �����ϰ� �ٲ�
	// ��Ȳ�� ���� �ް����� ������������ �� �Ǵ� ������ ���������� ��

	// �׷� param�� �ް� ������ ������ ���� ó����
	// ���������� ������ ���� ó���� �Ϸ��� �׻� ���� ���� ��ɾ ����
	TestKnight_Copy(std::foward<T>(param)); // foward �Լ��� 
}


int main()
{
	/*
	�ް�(lvalue) vs ������(rvalue)
	�ް�(lvalue)	: ���ϽĿ� �Ѿ ��� ���ӵǴ� ��ü
	������(rvalue)	: lvalue�� �ƴ� ������ (�ӽ� ��(�ӽð�ü ����), ������, ����, i++ ��)
	*/

	int a = 3;
	// 3 = a;
	// (a++) = 5;
	// ���� �ΰ� �� ������, �̷������� ������ �ް� ����

	Knight k1;
	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight()); // �ӽð�ü�� �� �״�� ���Ӽ� ���� �ӽð��̱� ������ ������
	TestKnight_ConstLValueRef(Knight());
	//TestKnight_RValueRef(k1); // ���� �ް��� ������
	TestKnight_RValueRef(Knight()); // ���� �ް��� ������

	// ������ �ٸ��� ��������� Copy �����ϰ� �� �� �Ȱ��� �����ϴ°� ����

	Knight k2;
	k2.m_pet = new Pet();
	k2.m_hp = 1000;

	Knight k3;
	k3 = static_cast<Knight&&>(k2); // ������ ������ �ȴ�, �� k2�� k3�� �̵���Ű�°�
	k3 = move(k2); // ������ ������ ĳ�����ѰŶ� ���� ����
	// �̰� �̿��ؼ� ����ũ �����͵� �ű� �� ����

	// =========================================================================================

	Test_TemForwardRef(k1); // ���� ���ø��� �ް� ������ �����Ѱ� �� �� ����.
	Test_TemForwardRef(move(k1));
	auto&& k4 = k3; // �̰ŵ� �ް� ������ �ٲ������
	// �� auto template ó�� ���� ����(type deduction) �Ͼ���� �߻�
	// ���� ���� : �츮�� �־��ִ� �������� ������ �����ִ� �۾� 
	// �׷� ���� �� ���� �ǰ� �س���? �и� ��Ű�� �׸�ŭ ������ ��������
	// �׸��� ���� Ư���� ���ڷ� ���� ���� ���� ������ �������� �Լ��� ������

	Knight& k5 = k4;
	Knight&& k6 = move(k5);
	// TestKnight_RValueRef(k6) �ϸ� ���� ���� ���, k6�� �ް� ����ϱ� ����
	// ������ : �ް��� �ƴϴ� = ���ϽĿ��� ����� ����� �� ����
	// ������ ���� : �������� ������ �� �ִ� ���� Ÿ��
	// �� k6�� ������ ���� Ÿ���̶� �������� ������ �� ������
	// �׷��ٰ� �ؼ� k6 ��ü�� �������� �ƴϴ�, k6 ���Ϸ� ��� �����ϱ� ������ �ް�
	TestKnight_RValueRef(move(k6));
	// move�� ���� k6�� �ѹ� ���̰� ���� �������̴� ��������� �������� ��


}