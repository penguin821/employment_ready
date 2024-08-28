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

// CV는 유저레벨 오브젝트이다, 커널 오브젝트 아님
// 커널 오브젝트는 서로 다른 프로그램끼리도 이벤트로 동기화 가능
// 유저 레벨 오브젝트는 프로그램 내부에서만 가능
condition_variable cv; // mutex 헤더에 포함, 기본 버전
// CV는 락과 같이 쓰인다


// #include <condition_variable> // 아래 애를 쓰려면 이걸 선언
// condition_variable_any cv; // 좀 더 일반적인 버전

void Pro() // 데이터 생산
{
	while (true)
	{
		/* notify 작동 방식
		1. Lock 잡고
		2. 공유 변수 값을 수정
		3. Lock 풀고
		4. 조건 변수 통해 다른 쓰레드에게 통지 */

		{
			unique_lock<mutex> lock(m);
			q.push(100);
		}

		cv.notify_one(); // wait 중인 쓰레드가 있으면 딱 1개를 깨운다

		//::SetEvent(handle); // Event 를 Signal 상태로 바꿔줌
	}

}

void Con() // 데이터 추출
{
	while (true)
	{
		//::WaitForSingleObject(handle, INFINITE); // 해당 핸들의 시그널 상태 확인
		unique_lock<mutex> lock(m);

		cv.wait(lock, []() {return q.empty() == false; });
		/* wait 작동 방식
		1. Lock을 한다 (이미 되어있으면 스킵)
		2. 조건 확인, 만족 시 코드 진행
		3. 조건 만족 안할 시 Lock을 풀어주고 wait 줄에 대기 상태로 전환
		4. 대기 하다가 누가 notify_one 해주면 다시 1단계부터 진행 */

		// WaitForSingleObject와 유사하지만 무조건 대기하는게 아니라 조건 비교까지 해준다
		// CV 쓸때 유니크 락을 써야함, 그냥 락 가드 쓰면 유동적으로 중간에 임의로 락 걸고
		// 하는 기능을 이용 못하기 때문

		// 조건식 없이 lock만 하면 notify_one 호출을 하지않았는데 cv.wait 가 발동할때가 있음
		// 이걸 Spurious Wakeup (가짜 기상) 이라고 함, wait 상태가 풀려버리는것
		// 그걸 방지하기 위해 확실한 조건때만 발동되게 조건식 거는것

		//while (q.empty() == false) 이젠 하나로 묶였기 때문에 밖의 while문으로 모든 데이터 다 소모시킴
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