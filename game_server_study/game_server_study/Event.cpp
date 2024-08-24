#include "PCH.h"
#include <iostream>
#include "CorePCH.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h> // event

mutex m;
queue<int32> q;
HANDLE handle;

void Pro() // ������ ����
{
	while (true)
	{
		unique_lock<mutex> lock(m);
		q.push(100);
	}
	this_thread::sleep_for(100ms);
}

void Con() // ������ ����
{
	while (true)
	{
		unique_lock<mutex> lock(m);
		if (q.empty() == false)
		{
			int32 data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	handle = ::CreateEvent(NULL/*���ȼӼ�*/, FALSE/*�ڵ��ʱ�ȭ����*/, FALSE/*�ʱⰪ����*/, NULL/*����*/);

	thread t1(Pro);
	thread t2(Con);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}