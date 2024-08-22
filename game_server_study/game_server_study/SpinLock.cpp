#include "PCH.h"
#include <iostream>
#include "CorePCH.h"
#include <thread>
#include <atomic>
#include <mutex>

class SpinLock
{
public:
	void lock() // �ҹ��� = lock_guard ���� ��ü�� �ҹ��� lock() unlock()�� ����
	{
		while (m_isLock)
		{

		}

		// ����� ������ ������ �� ƴ ��� ���̿� �� �����尡 ���� �����ϴ�
		// ��찡 �߻��ؼ� �׷�, �ᱹ ��״� ������ ������� ó���ϴ� ������ �ϳ��� ��������

		m_isLock = true;
	}

	void unlock()
	{
		m_isLock = false;
	}

private:
	//bool m_isLock = false;
	volatile bool m_isLock = false; // ������� ����ȭ ���� ���ƶ�
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