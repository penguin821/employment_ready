#include <iostream>

using namespace std;

class RefCountBlock
{
	// 참조 몇개 하고있는지에 대한 카운트는 공용 메모리로 따로 빼서 관리함
public:
	int m_refCount = 1;
	int m_weakCount = 1; // weak_ptr 사용시에만 추가됨
};

template<typename T>
class Shared_Ptr
{
	// 해당 포인터를 몇명이 참조하고 있는지 계속 추적
	// 반드시 해당 객체를 아무도 참고하고 있지 않을때 delete 함
public:
	Shared_Ptr(){} // 만약 아무것도 안넣어주면 nullptr랑 같은작용
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
				// weak_ptr 사용시 shared_ptr과 다르게 블록을 남겨둔다
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
	Knight() { cout << "나이트 생성" << endl; }
	~Knight() { cout << "나이트 소멸" << endl; }
public:
	void Attack()
	{
		if (m_target.expired() == false) // 이 포인터가 유효하다면
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
	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체
	// shared_ptr, weak_ptr, unique_ptr
	// shared 가 핵심, weak 가 단점 보완, 유니크가 별도

	//Shared_Ptr<Knight> k2;
	//{
	//	Shared_Ptr<Knight> k1(new Knight());
	//	k2 = k1;
	//}

	//shared_ptr<Knight> k1(new Knight());
	shared_ptr<Knight> k1 = make_shared<Knight>(); // 쉐어드 포인터 선언할땐 이게 더 좋음
	// 메모리 블록을 한번에 만들어줌
	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->m_target = k2;
	}
	// 이렇게 메모리 공간 밖으로 나와도 소멸되지 않고 있다가
	k1->Attack();
	// 여기서 return 0; 할때 되어서 카운트가 0인걸 확인하고 한번에 knight를 delete함

	// 단점
	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->m_target = k2;
		k2->m_target = k1;
		// 이렇게 서로가 서로를 바라보는 순환구조가 되어버리면 
		// 둘다 ref count가 2가 되었다가 k2가 메모리 공간 밖으로 나와버리면서 1감소하여
		// k1 = 2, k2 = 1 카운트가 되면서 둘다 영원히 소멸을 안해버림
		
		// k1->m_target = nullptr;
		// k2->m_target = nullptr;
		
		// 그래서 이런식으로 순환구조를 한번 끊어줘야한다
		// 그거에 대한 다른방법 중 하나가 weak_ptr 임

		// weak_ptr 장점은 knight 객체의 소멸 자체에는 영향을 안주기 때문에 순환구조가 안일어남
		// 즉, 생명주기에 대해서 자유로워짐 / 그러나 사용하려면 명시적으로 체크를 해서
		// 다시 shared_ptr로 변환해서 사용해야하는 번거로움

		// 그냥 메모리 관리만 편하게 하고싶다 -> share
		// 메모리 구조에서도 자유로워 지고 싶다 -> share + weak
	}

}

