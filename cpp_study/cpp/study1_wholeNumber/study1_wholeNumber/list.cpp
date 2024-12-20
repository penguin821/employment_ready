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
	// 벡터처럼 미리 여유 메모리를 잡아놓고 거기에 저장하는 방식이 아닌
	// 그때그때 삽입 삭제 되는 노드를 만들어서 연결시켜주는 구조임
	int front = li.front();
	int last = li.back();

	 // li[1] 없음, 동적배열이 아니기 때문
	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();
	// list<int>::iterator it2 = li.begin() + 5;
	// 벡터에선 가능했는데 얘는 이렇게 접근 불가

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

class node // list의 동작 원리
{
public:
	node* m_next;
	node* m_prev;
	int m_data;
};

/*
리스트의 종류
list : 연결리스트
서로서로 다른 메모리 공간에 저장되어있는 데이터들을 포인터로 이으는 방식으로 동작함

1. 중간 삽입 삭제
효율적임, 얘네는 서로서로 앞뒤 포인터로 연결짓는 구조이기 때문에
중간에 새로 넣고 앞뒤 포인터로 연결시켜주면 끝

2. 처음 끝 삽입 삭제
위랑 같은 이유로 효율적임

3. 임의 접근
비효율적임, 서로 다른 메모리 공간에 저장되어 있으므로
i번째 데이터를 찾아가려면 시작부터 하나하나 포인터를 타고 찾아가야함
벡터는 한 메모리 공간에 연속적으로 저장되어 있으면
시작 주소의 몇번째칸 뒤에있다, 해서 빠르게 찾을 수 있음

단일 리스트
[1] -> [2] -> [3] -> [4] -> [5]

이중 리스트
[1] <-> [2] <-> [3] <-> [4] <-> [5]

원형 리스트
[1] <-> [2] <-> [3] <-> [4] <-> [5] <->

리스트 이터레이터
[1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [_Myhead : end()] <-> 처음으로
										STL에서 자체적으로 추가해준 노드, 벡터처럼 값은 없지만
										마지막인지 판단용

1. begin() 기준으로 --하면 end()로 가지는지?
터짐, 메모리 상으로 연결되어 있는데 사실상 이렇게 하면 안된다고 
디버깅 단계에서 에러코드를 띄우기 위해 연결해놓은 거임

2. end() 기준으로 --하면 이전칸으로 가지는지?
잘 된다

3. end() 기준으로 ++하면 처음으로 가지는지?
터짐, 얘도 디버깅 단계에서 에러코드 띄우기용

★★★★★★★★★★★★★★★★★★★★★★★★★
분명 임의 접근이 안되는데(비효율적이라)
중간 삽입 삭제를 빠르다는 모순이 발생

애초에 중간 삽입 삭제를 하려면 입의 접근을 해야하고
원하는 값을 삭제하려면 처음부터 접근하는 비효율성 발생
그런데 중간 삽입 삭제가 빠르다?

따로 생각해야함
우리가 원하는 특정 인덱스에 있는 데이터를 삭제하는건 비효율적인게 맞음
데이터 자체를 한번에 삽입 삭제하는게 효율적이고 빠르다는거지
*/