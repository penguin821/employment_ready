#pragma once
// 게임 접속할때 계정들 관리
#include <mutex>

class Account
{
	//todo
};

class DeadLock_AccountManager
{
public: 
	// 싱글톤
	static DeadLock_AccountManager* Instance()
	{
		static DeadLock_AccountManager instance;
		return &instance;
	}

	Account* GetAccount(int32)
	{
		lock_guard<mutex> guard(m_mutex);
		// 계정 관련 무언가를 가지고 옴
		return nullptr;
	}

	void ProcessLogin(); // 로그인 하는 코드들
private:
	mutex m_mutex;
	//map<int32,Account*> m_accounts;
};

