#include <iostream>

using namespace std;

class RefCountBlock
{
	// ���� � �ϰ��ִ����� ���� ī��Ʈ�� ���� �޸𸮷� ���� ���� ������
public:
	int m_refCount = 1;
	int m_weakCount = 1; // weak_ptr ���ÿ��� �߰���
};

template<typename T>
class Shared_Ptr
{
	// �ش� �����͸� ����� �����ϰ� �ִ��� ��� ����
	// �ݵ�� �ش� ��ü�� �ƹ��� �����ϰ� ���� ������ delete ��
public:
	Shared_Ptr(){} // ���� �ƹ��͵� �ȳ־��ָ� nullptr�� �����ۿ�
	Shared_Ptr(T* ptr) : m_ptr(ptr)
	{
		if (m_ptr)
		{
			m_refBlock = new RefCountBlock();
			cout << "Ref Count : " << m_refBlock->m_refCount << endl;
		}
	}
	Shared_Ptr(const Shared_Ptr& sptr) : m_ptr(sptr.m_ptr), m_refBlock(sptr.m_refBlock)
	{
		if (m_ptr)
		{
			m_refBlock->m_refCount++;
			cout << "Ref Count : " << m_refBlock->m_refCount << endl;
		}
	}
	~Shared_Ptr()
	{
		if (m_ptr)
		{
			m_refBlock->m_refCount--;
			cout << "Ref Count : " << m_refBlock->m_refCount << endl;

			if (!m_refBlock->m_refCount)
			{
				delete m_ptr;
				// delete m_refBlock;
				// weak_ptr ���� shared_ptr�� �ٸ��� ����� ���ܵд�
				cout << "Delete Data" << endl;
			}
		}
	}
public:
	void operator=(const Shared_Ptr& sptr)
	{
		m_ptr = sptr.m_ptr;
		m_refBlock = sptr.m_refBlock;
		if (m_ptr)
		{
			m_refBlock->m_refCount++;
			cout << "Ref Count : " << m_refBlock->m_refCount << endl;
		}
	}

public:
	T* m_ptr = nullptr;
	RefCountBlock* m_refBlock = nullptr;
};

class Knight
{
public:
	Knight() { cout << "����Ʈ ����" << endl; }
	~Knight() { cout << "����Ʈ �Ҹ�" << endl; }
public:
	void Attack()
	{
		if (m_target.expired() == false) // �� �����Ͱ� ��ȿ�ϴٸ�
		{
			//m_target->m_hp -= m_damage;
			shared_ptr<Knight> sptr = m_target.lock();
			sptr->m_hp -= m_damage;
		}
	}
public:
	int m_hp = 100;
	int m_damage = 10;
	//Knight* m_target = nullptr;
	//shared_ptr<Knight> m_target = nullptr;
	weak_ptr<Knight> m_target = nullptr;
};

int main()
{
	// ����Ʈ ������ : �����͸� �˸´� ��å�� ���� �����ϴ� ��ü
	// shared_ptr, weak_ptr, unique_ptr
	// shared �� �ٽ�, weak �� ���� ����, ����ũ�� ����

	//Shared_Ptr<Knight> k2;
	//{
	//	Shared_Ptr<Knight> k1(new Knight());
	//	k2 = k1;
	//}

	//shared_ptr<Knight> k1(new Knight());
	shared_ptr<Knight> k1 = make_shared<Knight>(); // ����� ������ �����Ҷ� �̰� �� ����
	// �޸� ����� �ѹ��� �������
	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->m_target = k2;
	}
	// �̷��� �޸� ���� ������ ���͵� �Ҹ���� �ʰ� �ִٰ�
	k1->Attack();
	// ���⼭ return 0; �Ҷ� �Ǿ ī��Ʈ�� 0�ΰ� Ȯ���ϰ� �ѹ��� knight�� delete��

	// ����
	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->m_target = k2;
		k2->m_target = k1;
		// �̷��� ���ΰ� ���θ� �ٶ󺸴� ��ȯ������ �Ǿ������ 
		// �Ѵ� ref count�� 2�� �Ǿ��ٰ� k2�� �޸� ���� ������ ���͹����鼭 1�����Ͽ�
		// k1 = 2, k2 = 1 ī��Ʈ�� �Ǹ鼭 �Ѵ� ������ �Ҹ��� ���ع���
		
		// k1->m_target = nullptr;
		// k2->m_target = nullptr;
		
		// �׷��� �̷������� ��ȯ������ �ѹ� ��������Ѵ�
		// �װſ� ���� �ٸ���� �� �ϳ��� weak_ptr ��

		// weak_ptr ������ knight ��ü�� �Ҹ� ��ü���� ������ ���ֱ� ������ ��ȯ������ ���Ͼ
		// ��, �����ֱ⿡ ���ؼ� �����ο��� / �׷��� ����Ϸ��� ��������� üũ�� �ؼ�
		// �ٽ� shared_ptr�� ��ȯ�ؼ� ����ؾ��ϴ� ���ŷο�

		// �׳� �޸� ������ ���ϰ� �ϰ�ʹ� -> share
		// �޸� ���������� �����ο� ���� �ʹ� -> share + weak
	}

}

