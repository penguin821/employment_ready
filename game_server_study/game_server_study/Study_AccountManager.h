#pragma once
// ���� �����Ҷ� ������ ����
#include <mutex>

class Account
{
	//todo
};

class Study_AccountManager
{
public: 
	// �̱���
	static Study_AccountManager* Instance()
	{
		static Study_AccountManager instance;
		return &instance;
	}

	Account* GetAccount(int32)
	{
		lock_guard<mutex> guard(m_mutex);
		// ���� ���� ���𰡸� ������ ��
		return nullptr;
	}

	void ProcessLogin();
private:
	mutex m_mutex;
	//map<int32,Account*> m_accounts;
};

