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
	����� �ذ���
	1. �� ������ ����� -> �ڵ尡 ��������� ������ ���� �����
	2. map���� ���ؽ��� �߿䵵 ��ȣ�� �Ű� �����Ѵ� -> �ᱹ �̰͵�
	   ����� ����ű� ������ �Ϻ��ϰ� ���� ���� ���� ����
	3. std::lock(m1, m2) = m1.lock() m2.lock()
	   �̷��� �ϸ� m1 m2 �߿� ���� �ɷ��� �� �ָ� �����Ϸ��� �˾Ƽ� �Ǵ�
	   ���� lock_guard<mutex> g1(m1, adopt_lock);
	   lock_guard<mutex> g1(m2, adopt_lock); �� ���� Ǭ��
	   adopt_lock = �̹� �� �� ���´� ���߿� �Ҹ�ɶ� Ǯ���ֱ⸸ �ش޶�
	*/

	cout << "job done" << endl;
}