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

// CV�� �������� ������Ʈ�̴�, Ŀ�� ������Ʈ �ƴ�
// Ŀ�� ������Ʈ�� ���� �ٸ� ���α׷������� �̺�Ʈ�� ����ȭ ����
// ���� ���� ������Ʈ�� ���α׷� ���ο����� ����
condition_variable cv; // mutex ����� ����, �⺻ ����
// CV�� ���� ���� ���δ�


// #include <condition_variable> // �Ʒ� �ָ� ������ �̰� ����
// condition_variable_any cv; // �� �� �Ϲ����� ����

void Pro() // ������ ����
{
	while (true)
	{
		/* notify �۵� ���
		1. Lock ���
		2. ���� ���� ���� ����
		3. Lock Ǯ��
		4. ���� ���� ���� �ٸ� �����忡�� ���� */

		{
			unique_lock<mutex> lock(m);
			q.push(100);
		}

		cv.notify_one(); // wait ���� �����尡 ������ �� 1���� �����

		//::SetEvent(handle); // Event �� Signal ���·� �ٲ���
	}

}

void Con() // ������ ����
{
	while (true)
	{
		//::WaitForSingleObject(handle, INFINITE); // �ش� �ڵ��� �ñ׳� ���� Ȯ��
		unique_lock<mutex> lock(m);

		cv.wait(lock, []() {return q.empty() == false; });
		/* wait �۵� ���
		1. Lock�� �Ѵ� (�̹� �Ǿ������� ��ŵ)
		2. ���� Ȯ��, ���� �� �ڵ� ����
		3. ���� ���� ���� �� Lock�� Ǯ���ְ� wait �ٿ� ��� ���·� ��ȯ
		4. ��� �ϴٰ� ���� notify_one ���ָ� �ٽ� 1�ܰ���� ���� */

		// WaitForSingleObject�� ���������� ������ ����ϴ°� �ƴ϶� ���� �񱳱��� ���ش�
		// CV ���� ����ũ ���� �����, �׳� �� ���� ���� ���������� �߰��� ���Ƿ� �� �ɰ�
		// �ϴ� ����� �̿� ���ϱ� ����

		// ���ǽ� ���� lock�� �ϸ� notify_one ȣ���� �����ʾҴµ� cv.wait �� �ߵ��Ҷ��� ����
		// �̰� Spurious Wakeup (��¥ ���) �̶�� ��, wait ���°� Ǯ�������°�
		// �װ� �����ϱ� ���� Ȯ���� ���Ƕ��� �ߵ��ǰ� ���ǽ� �Ŵ°�

		//while (q.empty() == false) ���� �ϳ��� ������ ������ ���� while������ ��� ������ �� �Ҹ��Ŵ
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