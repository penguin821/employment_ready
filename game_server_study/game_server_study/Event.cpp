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
		{
			unique_lock<mutex> lock(m);
			q.push(100);
		}

		::SetEvent(handle); // Event �� Signal ���·� �ٲ���
		this_thread::sleep_for(1000ms);
	}

}

void Con() // ������ ����
{
	while (true)
	{
		::WaitForSingleObject(handle, INFINITE); // �ش� �ڵ��� �ñ׳� ���� Ȯ��
		// handle�� �츮�� �ʱ�ȭ ���θ� �ڵ����� �ؼ� �˾Ƽ� Non-Signal ���·� �ٲ��
		// ���� �޴��󸮼��� Ʈ��� �ߴٸ� ResetEvent(handle); �������
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
	// �̺�Ʈ�� Ŀ�� ������Ʈ�� ����, �� �� ���� Ŀ�� ������Ʈ�� �Ʒ�
	// Usage Count = ������Ʈ�� ����� ����ϰ� �ִ���
	// Signal / NonSignal = bool
	// Auto / Manual
	handle = ::CreateEvent(NULL/*���ȼӼ�*/, FALSE/*�����ʱ�ȭ����*/, FALSE/*�ʱⰪ����*/, NULL/*����*/);

	thread t1(Pro);
	thread t2(Con);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}