#pragma once
#include <mutex>
class User
{
	// todo
};

class Study_UserManager
{
public:
	// �̱���
	static Study_UserManager* Instance()
	{
		static Study_UserManager instance;
		return &instance;
	}

	User* GetUser(int32)
	{
		lock_guard<mutex> guard(m_mutex);
		// ���� ���� ���𰡸� ������ ��
		return nullptr;
	}

	void ProcessSave();
private:
	mutex m_mutex;
};

