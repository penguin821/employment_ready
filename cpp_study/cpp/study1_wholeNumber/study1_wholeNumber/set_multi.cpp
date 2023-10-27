#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
	// key �� �� value �϶�
	// key �� �ϳ� ����Ǿ� ����
	set<int> s;

	s.insert(10);
	s.insert(10); // ����
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(60);
	s.insert(70);
	s.insert(80);

	s.erase(40);

	set<int>::iterator findit = s.find(50);
	if (findit != s.end())
	{
		cout << "ã��" << endl;
	}
	else
	{
		cout << "��ã��" << endl;
	}

	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "------------------------------------------" << endl;

	multimap<int, int> mm; // �ߺ� Ű�� ����ϴ� map

	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));

	// mm[1] = 600 �� ������ �ȸ���

	mm.erase(1); // Ű ���� 1�� ��� value�� ����
	unsigned int count = mm.erase(1); // �̷��� �ϸ� ������ ������ŭ ī��Ʈ �ö�

	multimap<int, int>::iterator findIt = mm.find(1);
	// ó�� �߰��Ѿ� ������ �����ϰ� ������ ++findIt
	if (findit != s.end())
		mm.erase(findIt); // �̷��� �ϸ� ó�� �߰��� �ָ� ����

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	// ���߿� auto itPair �� ��ü ����
	itPair = mm.equal_range(1);
	// Ű ���� 1�� ���� ���� �ּ� = first
	// Ű ���� 1�� ���� ������ ���� �ּҰ� = second
	
	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	mm.lower_bound(1); // Ű ���� 1�� ���� ���� �ּ�
	mm.upper_bound(1); // Ű ���� 1�� ���� ������ ���� �ּҰ�

	multimap<int, int>::iterator itBegin = mm.lower_bound(1);
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);

	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "------------------------------------------" << endl;

	multiset<int> ms; // �ߺ��� ����ϴ� set
	// multimap �̶� ���ư��� ��� ����

	cout << "------------------------------------------" << endl;

	/*
	�ǹ����� ��Ƽ�� ��Ƽ�� ���� �� �ѹ��� �̿����
	set ���� ��� �������� ���� �÷��̾�� ���͵� ID ����� �ʿ��ѵ�
	�������� ID �߿� ���� ã�ƾ��ϴ� ID�� ���� ã�ƾ� �Ѵ� �ϸ�
	set �ϳ� ���� ���� ã�ƺ� ID���� �ǽð����� �־
	�ش� set�� �̿��Ͽ� �ڵ带 ¥�� ��Ŀ��� ���� ����?
	*/

	/*
	�������� set map �� �������� ����, �������� ������ ��������
	��쿡 ���� map �� multimap�� ���̵� ���

	���� map set multimap multiset�� �⺻ ���� ������ �����ؾ���
	*/
	return 0;
}