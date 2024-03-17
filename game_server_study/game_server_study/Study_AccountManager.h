#pragma once
// 게임 접속할때 계정들 관리
#include <mutex>

class Account
{
	//todo
};

class Study_AccountManager
{
public: 
	// 싱글톤
	static Study_AccountManager* Instance()
	{
		static Study_AccountManager instance;
		return &instance;
	}

	Account* GetAccount(int32)
	{
		lock_guard<mutex> guard(m_mutex);
		// 계정 관련 무언가를 가지고 옴
		return nullptr;
	}

	void ProcessLogin();
private:
	mutex m_mutex;
	//map<int32,Account*> m_accounts;
};

