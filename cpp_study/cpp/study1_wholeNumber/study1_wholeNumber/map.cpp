#include <iostream>
#include <map>
using namespace std;

class Player
{
	int m_id;
};

int main()
{
	// 10���� �÷��̾ �����Ѵ� ġ�� push back���� ���ָ� ��
	// �׷��� �� �� 5������ �������� �����ϰ� ������ 5���� �߿���
	// ���ϴ� �÷��̾� ���̵� �˻��Ϸ���?
	// �׳� ó������ �� �ϳ��ϳ� ã�ƺ��� �� �ۿ� ����;;
	
	// list vector ���� ���� ������ ġ������ ����
	// ���ϴ� ������ �����͸� ������ ȿ�������� ã�� �� ����

	// map�� ���� �����̳�, ���� ���� Ʈ��(AVL), ��� ���
	
	class Node
	{
		Node* m_left;
		Node* m_right;

		//int m_key;
		//Player* m_value;
		pair<int, Player*> m_data;
	};
	srand(static_cast<unsigned int>(time(nullptr)));
	// map�� key �� value�� ����
	map<int, int> m;

	// 10�� ����
	for (int i = 0; i < 100'000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5�� ����
	for (int i = 0; i < 50000; i++)
	{
		int randVal = rand() % 50000;

		// ���� erase ����� 4������ ����
		// erase by key
		m.erase(randVal);
	}

	// ���ϴ� �� ã��
	map<int, int>::iterator findIt = m.find(10000);
	// ()���� Ű��, find�� ������� ���ͷ�������
	if (findIt != m.end())
	{
		cout << "ã��" << endl;
	}
	else
	{
		cout << "��ã��" << endl;
	}

	// �Ȱ��� Ű ���� �ߺ� erase �Ѵٸ�?
	// �Ȱ��� Ű���� erase �ϸ� ���߿� ���� ����� �׳� ������ ū ������ �߻�����

	// �Ȱ��� Ű ��, �ٸ� value ���� �ߺ� insert �Ѵٸ�?
	// �굵 ���߿� �Էµ� ��� ����Ⱑ �ƴ϶� �׳� ����
	// ���� ���� �����ϰ� ������ �� ����� ����ϸ� �ȵ�

	// map�� ��ȯ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		int key = it->first;
		int value = it->second;

		cout << key << " , " << value << endl;
	}

	// ���ϴ� ���� �ִ��� Ȯ���ϰ� ������ �߰�, �ִٸ� �����ϰ� ������
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end()) // ã�Ҵٸ�
	{
		findIt->second = 200; // ����
	}
	else // ���ٸ�
	{
		m.insert(make_pair(10000, 200)); // �߰�
	}

	// �׳� m[����] ������ �̿��ؼ� ã���� ���� �ʳ�?
	m[10000] = 200; // �̰ŵ� ������ ���� ������ �Ѵ�
	// 1�� Ű���� �����ְ� ������ 200 value�� �߰��ϰ�
	// 1�� Ű���� �����ְ� ������ 200 value�� �����ϰ�

	// m[] ������ ���ǻ���
	// ���� �˻��ϰų� ȣ���Ѵ� �ð�

	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}
	// �̷������� m[ ] �� ������ ������ Ű���� ȣ�⸸ �Ǵ���
	// �� ������� �ش� Ű���� 0 value ������ �ؼ� map�� �߰����ѹ�����
	// �ſ� �����Ұ�

	// �ܼ� ���ͷ����� �������� ��ȸ�Ѵ� ġ��
	// ���ӵ� �����Ͱ� �� ��ġ�� ����Ǿ� �ִ� ���Ͱ� map���� ȿ����
	// �׷��� ���� ���� �˻��� �Ѵٰ� ������ avlƮ���� ������ map��
	// ���ӵ� �����Ͱ� �ƴ϶� ������ ������ Ʈ���� ����Ǿ��ִ� ���̹Ƿ�
	// ���ͺ��� �� ȿ�����̴�
}