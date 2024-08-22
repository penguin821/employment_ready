#include "PCH.h"

#include <thread>
#include <atomic>
#include <mutex>

vector <int32> v;
// ������� �Ϲ����� ������������ �� �۵�������
// atomic<vector <int32>> v �̷������� ���� ����� �۵� ����
mutex m;

// �Ź� ���� ��� �� �ɰ� ��� ��� �ƴ��� �ľ� �ȵǰ� �����ϱ� ����
// RAII ( Resource Acquisition Is Initialization)
// �����ڿ� �Ҹ��ڸ� ���� Ư�� ������ ���� ���
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
        // m.lock(); // ���
        // ���� �ٸ������� lock�� �����Ϸ��� �ϸ� �ش� m.lock()���� ����ϰԵ�
        // �̱� ������ȭ �Ǵ°Ŷ� �Ȱ���
        // ��������� ��� �Ұ���
        
        // CustomLockGuard<mutex> lg(m); // ���� �ϸ� �������� ���� �ɸ���
        // �ش� Ŭ������ ����� ������ ������ �ڵ����� �Ҹ��ڷ� �����
        // ���� ������ ��� ���ϰ� ���� �þ (��õ)

        //lock_guard<mutex> lg(m); // C++11���� ���� �����ϴ� ������

        unique_lock<mutex> lg(m, defer_lock); // �̷������� ���ϴ� ������ �ڿ� �־��ָ�
        lg.lock(); // �̷��� ���ϴ� ���� ���� �� �� �ִ� �� �߰����� ����� ���ִ� ������
        // �׳� ������ ���� �翬�� ���ϰ� ���� �þ
        v.push_back(i);
        
        //m.unlock(); // Ǯ��
    }
}

int main()
{
    thread t1(Push);
    thread t2(Push);

    t1.join();
    t2.join();
}