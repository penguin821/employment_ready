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

void Pro() // 데이터 생산
{
	while (true)
	{
		{
			unique_lock<mutex> lock(m);
			q.push(100);
		}

		::SetEvent(handle); // Event 를 Signal 상태로 바꿔줌
		this_thread::sleep_for(1000ms);
	}

}

void Con() // 데이터 추출
{
	while (true)
	{
		::WaitForSingleObject(handle, INFINITE); // 해당 핸들의 시그널 상태 확인
		// handle을 우리가 초기화 여부를 자동으로 해서 알아서 Non-Signal 상태로 바뀐다
		// 만약 메뉴얼리셋을 트루로 했다면 ResetEvent(handle); 해줘야함
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
	// 이벤트는 커널 오브젝트의 일종, 그 외 여러 커널 오브젝트들 아래
	// Usage Count = 오브젝트를 몇명이 사용하고 있는지
	// Signal / NonSignal = bool
	// Auto / Manual
	handle = ::CreateEvent(NULL/*보안속성*/, FALSE/*셀프초기화여부*/, FALSE/*초기값설정*/, NULL/*별명*/);

	thread t1(Pro);
	thread t2(Con);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}