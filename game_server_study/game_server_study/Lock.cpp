#include "PCH.h"

#include <thread>
#include <atomic>
#include <mutex>

vector <int32> v;
// 아토믹은 일반적인 데이터형에서 잘 작동하지만
// atomic<vector <int32>> v 이런식으로 쓰면 제대로 작동 안함
mutex m;

// 매번 직접 어디서 락 걸고 어디서 언락 됐는지 파악 안되고를 방지하기 위해
// RAII ( Resource Acquisition Is Initialization)
// 생성자와 소멸자를 통한 특정 관리를 위한 방법
template <typename T>
class CustomLockGuard
{
public:
    CustomLockGuard(T& m)
    {
        m_mutex = &m;
        m_mutex->lock();
    }
    ~CustomLockGuard()
    {
        m_mutex->unlock();
    }
private:
    T* m_mutex;
};

void Push()
{
    for (int32 i = 0; i < 10'000; i++)
    {
        // m.lock(); // 잠금
        // 만약 다른곳에서 lock에 접근하려고 하면 해당 m.lock()에서 대기하게됨
        // 싱글 스레드화 되는거랑 똑같음
        // 재귀적으로 사용 불가능
        
        // CustomLockGuard<mutex> lg(m); // 선언만 하면 생성자인 락이 걸리고
        // 해당 클래스가 선언된 영역이 끝나면 자동으로 소멸자로 언락함
        // 물론 안전한 대신 부하가 조금 늘어남 (추천)

        //lock_guard<mutex> lg(m); // C++11에서 직접 제공하는 락가드

        unique_lock<mutex> lg(m, defer_lock); // 이런식으로 원하는 성능을 뒤에 넣어주면
        lg.lock(); // 이렇게 원하는 곳에 락을 걸 수 있는 등 추가적인 기능을 해주는 락가드
        // 그냥 락가드 보단 당연히 부하가 조금 늘어남
        v.push_back(i);
        
        //m.unlock(); // 풀기
    }
}

int main()
{
    thread t1(Push);
    thread t2(Push);

    t1.join();
    t2.join();
}