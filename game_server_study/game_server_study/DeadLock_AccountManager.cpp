#include "PCH.h"
#include "DeadLock_AccountManager.h"
#include "DeadLock_UserManager.h"

void DeadLock_AccountManager::ProcessLogin()
{
	// 어카운트 매니저 자체 락
	lock_guard<mutex> guard(m_mutex);

	// 유저 매니저의 get user 안에 자체 userlock
	User* user = DeadLock_UserManager::Instance()->GetUser(100);

	// 즉 이중락
	// todo
}
