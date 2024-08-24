#include "PCH.h"
#include <iostream>
#include "CorePCH.h"
#include <thread>
#include <atomic>
#include <mutex>
// ������ ���� ������ ���ɶ�
class SpinLock // ���� ȹ���Ҷ����� ��� Ȯ���ϸ鼭 ��ٸ�
{
public:
	void lock() // �ҹ��� = lock_guard ���� ��ü�� �ҹ��� lock() unlock()�� ����
	{
		// CAS (Compare And Swap)

		bool expected = false; // CAS �ϱ� ������ ��
		bool desired = true; // CAS�� �ٲ�� ���ϴ� ��

		/*CAS �۵���� �����ڵ�
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
			// ()���� ���� false�� ������ ��״°� �����ߴٴ� ���̴�
			// ��涧���� �� ���� �ݺ����� Ÿ��, desired�� Ʈ��� m_isLock�� Ʈ�簡 ��
			// �� �Ʒ��� while (m_isLock) {} m_isLock = true; ������ �ѹ��� �Ѵ�.

			expected = false; // ����! c_e_s�� ù��° ���ڴ� ���۷����� �޾Ƽ� 
			// �Ź� �ٲ�� ������ ������ ���� �ٽ� ó�� ������ �ٲ������

			//this_thread::sleep_for(std::chrono::milliseconds(100));
			this_thread::sleep_for(100ms); // 100ms ���� �غ� ť�� �ȵ��� ��� ��
			this_thread::yield(); // this_thread::sleep_for(0ms) �̰Ŷ� ����
			//�ڽ��� ���� Ÿ�ӽ����̽��� ���ϰ� �纸�ϰ� Ŀ�θ��� ���ư� �ٽ� �����층 �ض�
		}

		///////////////////////////////////////////////////////////////////////////////////

		while (m_isLock)
		{

		}

		// ����� ������ ������ �� ƴ ��� ���̿� �� �����尡 ���� �����ϴ�
		// ��찡 �߻��ؼ� �׷�, �ᱹ ��״� ������ ������� ó���ϴ� ������ �ϳ��� ��������

		m_isLock = true;
	}

	void unlock()
	{
		//m_isLock = false; ��� ������ ��������� �׳� �������� �򰥸��� �Ʒ�ó��
		m_isLock.store(false);
	}

private:
	//bool m_isLock = false;
	//volatile bool m_isLock = false; // ������� ����ȭ ���� ���ƶ�
	atomic<bool> m_isLock = false;
	/*
	a=1
	a=2
	a=3
	a=4 ������ ��� ����ȭ�� ����Ǵ� release ���� ��������
	�����Ϸ��� �ϳ� �ϳ� �����ϴ� ������ �����ϰ� �ٷ� a=4�� ����
	volatile �����ϸ� ���� ��� �ϳ��ϳ� �� ������ �� (a=1 a=2 a=3)	

	while (m_isLock)�� �츮�� �ǵ������� ����϶� �ٸ� �����尡 ���ǵ��
	�������� ���� �ݺ���, �׷��� �����Ϸ��� ����ȭ�� ���� Ȯ���� �ǹ̰� ����
	�ڵ�� �Ǵ��ϰ� �þ����. volatile ���� ������ �Ϸ������� ����� ������ ����
	*/
};

int32 sum = 0;
mutex m;
SpinLock sl;

void Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		//lock_guard<mutex> guard(m); // �������� �� ���
		lock_guard<SpinLock> guard(sl); // ���������� �� ���
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