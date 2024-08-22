#include "PCH.h"
#include <iostream>
#include "CorePCH.h"
#include <thread>
#include <atomic>
#include <mutex>
#include "DeadLock_AccountManager.h"
#include "DeadLock_UserManager.h"

void Func1()
{
	for (int32 i = 0; i < 100; i++)
	{
		DeadLock_UserManager::Instance()->ProcessSave();
	}
}

void Func2()
{
	for (int32 i = 0; i < 100; i++)
	{
		DeadLock_AccountManager::Instance()->ProcessLogin();
	}
}

int main()
{
	thread t1(Func1);
	thread t2(Func2);

	t1.join();
	t2.join();

	/*
	데드락 해결방법
	1. 락 순서를 맞춘다 -> 코드가 방대해지면 갈수록 관리 힘들다
	2. map으로 뮤텍스에 중요도 번호를 매겨 관리한다 -> 결국 이것도
	   사람이 만든거기 때문에 완벽하게 동작 안할 수도 있음
	3. std::lock(m1, m2) = m1.lock() m2.lock()
	   이렇게 하면 m1 m2 중에 락이 걸려야 할 애를 컴파일러가 알아서 판단
	   이후 lock_guard<mutex> g1(m1, adopt_lock);
	   lock_guard<mutex> g1(m2, adopt_lock); 로 락을 푼다
	   adopt_lock = 이미 락 된 상태니 나중에 소멸될때 풀어주기만 해달라
	*/

	cout << "job done" << endl;
}