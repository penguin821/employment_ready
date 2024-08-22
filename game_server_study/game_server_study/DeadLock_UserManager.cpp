#include "PCH.h"
#include "DeadLock_UserManager.h"
#include "DeadLock_AccountManager.h"

void DeadLock_UserManager::ProcessSave()
{
	// 유저 매니저 자체 락
	lock_guard<mutex> guard(m_mutex);

	// 어카운트 매니저의 get accont 안에 자체 account lock
	Account* account = DeadLock_AccountManager::Instance()->GetAccount(100);

	// 즉 이중락
	// todo
}