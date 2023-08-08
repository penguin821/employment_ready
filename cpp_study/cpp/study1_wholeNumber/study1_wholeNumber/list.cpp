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
	// li.capacity() 없음, 동적배열이 아니기 때문
	int front = li.front();
	int last = li.back();

	 // li[1] 없음, 동적배열이 아니기 때문

	for (list<int>::iterator iter = li.begin(); iter != li.end(); ++iter)
	{
		cout << *iter << endl;
	}
	li.insert(li.begin(), 25); // (넣을위치, 넣을 값)
	li.erase(li.begin()); // (지울 위치)
	li.pop_front();
	li.remove(10); // 10을 가지고 있는 모든 리스트를 지워줌 (벡터는 복잡했었음)


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
리스트의 종류
list : 연결리스트

단일 리스트
[1] -> [2] -> [3] -> [4] -> [5]

이중 리스트
[1] <-> [2] <-> [3] <-> [4] <-> [5]

원형 리스트
[1] <-> [2] <-> [3] <-> [4] <-> [5] <->
*/