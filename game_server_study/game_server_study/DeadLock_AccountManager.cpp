#include "PCH.h"
#include "DeadLock_AccountManager.h"
#include "DeadLock_UserManager.h"

void DeadLock_AccountManager::ProcessLogin()
{
	// ��ī��Ʈ �Ŵ��� ��ü ��
	lock_guard<mutex> guard(m_mutex);

	// ���� �Ŵ����� get user �ȿ� ��ü userlock
	User* user = DeadLock_UserManager::Instance()->GetUser(100);

	// �� ���߶�
	// todo
}
