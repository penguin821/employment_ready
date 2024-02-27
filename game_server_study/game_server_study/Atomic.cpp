#include "PCH.h"

#include <thread>
#include <atomic>

// atomic : All Or Nothing, 다 실행이 되거나 하나도 실행이 안되거나 둘 중 하나만 존재해야하는 연산
// 서버에서도 쓰이지만 데베에서도 쓰임

atomic<int32> sum = 0;
// cpu가 다른애 공유접근 못하게 순서 정해줌

void Add()
{
    for (int32 i = 0; i < 1'000'000; i++)
        sum.fetch_add(1); // 이게 더 안전
    //sum++
}

void Sub()
{
    for (int32 i = 0; i < 1'000'000; i++)
        sum.fetch_add(-1);
    //sum--
}

int main()
{
    Add();
    Sub();
    
    cout << sum << endl;

    thread t1(Add);
    thread t2(Sub);

    t1.join();
    t2.join();
}