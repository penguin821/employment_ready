#include "PCH.h"

#include <thread>
#include <atomic>

// atomic : All Or Nothing, �� ������ �ǰų� �ϳ��� ������ �ȵǰų� �� �� �ϳ��� �����ؾ��ϴ� ����
// ���������� �������� ���������� ����

atomic<int32> sum = 0;
// cpu�� �ٸ��� �������� ���ϰ� ���� ������

void Add()
{
    for (int32 i = 0; i < 1'000'000; i++)
        sum.fetch_add(1); // �̰� �� ����
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