#include "PCH.h"

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
    // �ü���� ȭ�鿡 hello�� ����޶�� ��û�ϴ°��� 
    // ������ ���ſ� �۾�, System Call (OS Ŀ�� ��û)

    // ������ ���� ��û�� ���������� �ý��� ����
    // ::CreateThread() ó�� ������ �������� ������ ���� ����� ������
    // ������ �� ȯ���� �������� �ٲܰ� �ſ� ������
    // �׷��� C++11 ���� ȯ�� ������� #include <thread>�� �������� ������ ����

    HelloThread();
    //thread t(HelloThread);
    thread t;
    // �� ó�� �����ϸ� �׳� ���ξ����� �ȿ��� ����Ǿ��� ������� �Լ���
    // �Ʒ��� ���ο� �����忡�� ���������� ���ư��� HelloThread �Լ��� �����Ǵ� ��

    auto id1 = t.get_id(); // ������ ������ ID

    t = thread(HelloThread);

    int32 count = t.hardware_concurrency(); // CPU �ھ� ���� ������, 100�۷� ��Ȯ���� ����, ���� ����� ���Ҷ� 0 ��ȯ

    auto id2 = t.get_id();

    t.detach(); // ���״�� ��ü t ��  t�� �����ߴ� �����尡 �и��Ǿ� ��׶��� ������� ��ȯ
    // ���״�� �ڿ��� �� �˾Ƽ� ���ư��� �ִ� �������

    thread t1(HelloThread2, 10);

    vector<thread> v;

    for (int i = 0; i < 10; i++)
        v.push_back(thread(HelloThread2, i));

    for (int i = 0; i < 10; i++)

    {
        if (v[i].joinable())
            v[i].join();
    }

    if (t.joinable()) // �ش� ��ü�� �����ϴ� �����尡 ��ȿ���� �Ǵ�����
        t.join(); // t ������ ���� �۾��� ���������� ����ض�
    // ���� t ������ �ȿ� ���� �ݺ��� ������ ���� �����嵵 ���⼭ ������ ����ٴ� ��

    cout << "hello main" << endl;
}