#include "PCH.h"
#include "Study_AccountManager.h"
#include "Study_UserManager.h"

void Study_AccountManager::ProcessLogin()
{
	// account lock
	lock_guard<mutex> guard(m_mutex);

	// get user ¾È¿¡ userlock
	User* user = Study_UserManager::Instance()->GetUser(100);

	// todo
}
