#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> li;
	for (int i = 0; i < 100; i++)
		li.push_back(i);
	
	li.push_front(10);
	int size = li.size();
	// li.capacity() ����, �����迭�� �ƴϱ� ����
	int front = li.front();
	int last = li.back();

	 // li[1] ����, �����迭�� �ƴϱ� ����

	for (list<int>::iterator iter = li.begin(); iter != li.end(); ++iter)
	{
		cout << *iter << endl;
	}
	li.insert(li.begin(), 25); // (������ġ, ���� ��)
	li.erase(li.begin()); // (���� ��ġ)
	li.pop_front();
	li.remove(10); // 10�� ������ �ִ� ��� ����Ʈ�� ������ (���ʹ� �����߾���)


	return 0;
}

class node
{
public:
	node* m_next;
	node* m_prev;
	int m_data;
};

/*
����Ʈ�� ����
list : ���Ḯ��Ʈ

���� ����Ʈ
[1] -> [2] -> [3] -> [4] -> [5]

���� ����Ʈ
[1] <-> [2] <-> [3] <-> [4] <-> [5]

���� ����Ʈ
[1] <-> [2] <-> [3] <-> [4] <-> [5] <->
*/