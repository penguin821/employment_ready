#include "PCH.h"
#include "DeadLock_UserManager.h"
#include "DeadLock_AccountManager.h"

void DeadLock_UserManager::ProcessSave()
{
	// ���� �Ŵ��� ��ü ��
	lock_guard<mutex> guard(m_mutex);

	// ��ī��Ʈ �Ŵ����� get accont �ȿ� ��ü account lock
	Account* account = DeadLock_AccountManager::Instance()->GetAccount(100);

	// �� ���߶�
	// todo
}