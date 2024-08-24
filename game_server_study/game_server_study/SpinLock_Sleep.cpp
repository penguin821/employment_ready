#include "PCH.h"
#include <iostream>
#include "CorePCH.h"
#include <thread>
#include <atomic>
#include <mutex>
// 면접에 자주 나오는 스핀락
class SpinLock // 락을 획득할때까지 계속 확인하면서 기다림
{
public:
	void lock() // 소문자 = lock_guard 내부 자체에 소문자 lock() unlock()과 연동
	{
		// CAS (Compare And Swap)

		bool expected = false; // CAS 하기 이전의 값
		bool desired = true; // CAS로 바뀌길 원하는 값

		/*CAS 작동방식 슈도코드
		if (m_isLock == expected)
		{
			expected = m_isLock;
			m_isLock = desired;
			return true;
		}
		else
		{
			expected = m_isLock;
			return false;
		}*/

		while (m_isLock.compare_exchange_strong(expected, desired) == false)
		{
			// ()안의 값이 false가 나오면 잠그는걸 실패했다는 뜻이니
			// 잠길때까지 이 안의 반복문을 타고, desired가 트루니 m_isLock도 트루가 됨
			// 즉 아래의 while (m_isLock) {} m_isLock = true; 동작을 한번에 한다.

			expected = false; // 주의! c_e_s가 첫번째 인자는 레퍼런스로 받아서 
			// 매번 바뀌기 때문에 끝나기 전에 다시 처음 값으로 바꿔줘야함

			//this_thread::sleep_for(std::chrono::milliseconds(100));
			this_thread::sleep_for(100ms); // 100ms 동안 준비 큐에 안들어가게 블락 됨
			this_thread::yield(); // this_thread::sleep_for(0ms) 이거랑 같음
			//자신이 받은 타임슬라이스를 쿨하게 양보하고 커널모드로 돌아가 다시 스케쥴링 해라
		}

		///////////////////////////////////////////////////////////////////////////////////

		while (m_isLock)
		{

		}

		// 결과가 엉망인 이유는 요 틈 잠깐 사이에 두 쓰레드가 동시 진입하는
		// 경우가 발생해서 그럼, 결국 잠그는 과정과 잠겼을때 처리하는 과정이 하나로 묶여야함

		m_isLock = true;
	}

	void unlock()
	{
		//m_isLock = false; 상관 없지만 아토믹인지 그냥 변수인지 헷갈리니 아래처럼
		m_isLock.store(false);
	}

private:
	//bool m_isLock = false;
	//volatile bool m_isLock = false; // 마음대로 최적화 하지 말아라
	atomic<bool> m_isLock = false;
	/*
	a=1
	a=2
	a=3
	a=4 했을때 모든 최적화가 적용되는 release 모드로 돌려보면
	컴파일러가 하나 하나 변경하는 과정을 생략하고 바로 a=4만 돌림
	volatile 선언하면 쓸데 없어도 하나하나 다 돌리게 됨 (a=1 a=2 a=3)	

	while (m_isLock)은 우리가 의도적으로 잠김일때 다른 쓰레드가 못건들게
	막으려고 만든 반복문, 그러나 컴파일러가 최적화로 인해 확인할 의미가 없는
	코드로 판단하고 씹어버림. volatile 통해 방지를 하려했지만 결과는 여전히 엉망
	*/
};

int32 sum = 0;
mutex m;
SpinLock sl;

void Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		//lock_guard<mutex> guard(m); // 정상적인 값 출력
		lock_guard<SpinLock> guard(sl); // 비정상적인 값 출력
		sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		//lock_guard<mutex> guard(m);
		lock_guard<SpinLock> guard(sl);
		sum--;
	}
}

int main()
{
	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << sum << endl;
}