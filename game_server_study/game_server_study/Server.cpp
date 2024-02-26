#include "PCH.h"
#include "CorePCH.h"

#include <thread>

void HelloThread()
{
    cout << "hi thread" << endl;
}

void HelloThread2(int num)
{
    cout << num << endl;
}

int main()
{
    // cout << "hello" << endl;
    // 운영체제에 화면에 hello를 띄워달라고 요청하는거임 
    // 굉장히 무거운 작업, System Call (OS 커널 요청)
    
    // 쓰레드 생성 요청도 마찬가지고 시스템 콜임
    // ::CreateThread() 처음 윈도우 종속적인 쓰레드 생성 방법도 있지만
    // 리눅스 등 환경이 변했을때 바꿀게 매우 많아짐
    // 그래서 C++11 부터 환경 상관없이 #include <thread>로 공용적인 쓰레드 생성
    
    HelloThread();
    //thread t(HelloThread);
    thread t;
    // 위 처럼 선언하면 그냥 메인쓰레드 안에서 선언되었다 사라지는 함수고
    // 아래는 새로운 쓰레드에서 병렬적으로 돌아가는 HelloThread 함수가 생성되는 것

    auto id1 = t.get_id(); // 쓰레드 마다의 ID

    t = thread(HelloThread);

    int32 count = t.hardware_concurrency(); // CPU 코어 개수 얼마인지, 100퍼로 정확하진 않음, 정보 출력을 못할땐 0 반환

    auto id2 = t.get_id();

    t.detach(); // 말그대로 객체 t 와  t에 선언했던 스레드가 분리되어 백그라운드 쓰레드로 변환
    // 말그대로 뒤에서 지 알아서 돌아가고 있는 스레드로

    thread t1(HelloThread2, 10);

    vector<thread> v;

    for (int i = 0; i < 10; i++)
        v.push_back(thread(HelloThread2, i));

    for (int i = 0; i < 10; i++)

    {
        if (v[i].joinable())
            v[i].join();
    }

    if (t.joinable()) // 해당 객체가 관리하는 스레드가 유효한지 판단해줌
        t.join(); // t 쓰레드 내부 작업이 끝낼때까지 대기해라
    // 만약 t 쓰레드 안에 무한 반복문 있으면 메인 쓰레드도 여기서 영원히 멈춘다는 뜻

    cout << "hello main" << endl;
}