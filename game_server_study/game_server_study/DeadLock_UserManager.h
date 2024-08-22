#pragma once
#include <mutex>
class User
{
	// todo
};

class DeadLock_UserManager
{
public:
	// 싱글톤
	static DeadLock_UserManager* Instance()
	{
		static DeadLock_UserManager instance;
		return &instance;
	}

	User* GetUser(int32)
	{
		lock_guard<mutex> guard(m_mutex);
		// 계정 관련 무언가를 가지고 옴
		return nullptr;
	}

	void ProcessSave();
private:
	mutex m_mutex;
};

