#pragma once
// ���� �����Ҷ� ������ ����
#include <mutex>

class Account
{
	//todo
};

class DeadLock_AccountManager
{
public: 
	// �̱���
	static DeadLock_AccountManager* Instance()
	{
		static DeadLock_AccountManager instance;
		return &instance;
	}

	Account* GetAccount(int32)
	{
		lock_guard<mutex> guard(m_mutex);
		// ���� ���� ���𰡸� ������ ��
		return nullptr;
	}

	void ProcessLogin(); // �α��� �ϴ� �ڵ��
private:
	mutex m_mutex;
	//map<int32,Account*> m_accounts;
};

