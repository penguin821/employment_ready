#pragma once
#include <mutex>
class User
{
	// todo
};

class DeadLock_UserManager
{
public:
	// �̱���
	static DeadLock_UserManager* Instance()
	{
		static DeadLock_UserManager instance;
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

