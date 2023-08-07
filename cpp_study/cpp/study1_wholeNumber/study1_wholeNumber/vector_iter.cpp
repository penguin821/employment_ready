#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 반복자 iterator : 포인터와 유사한 개념
	// 컨테이너의 원소를 가리킴, 다음-이전 원소 이동 가능

	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	vector<int>::iterator iter;
	int* ptr;

	iter = v.begin();
	ptr = &v[0];
	// 그럼 이터레이터도 포인터랑 똑같은거 아니냐??
	// 포인터긴 포인터인데 iter은 자기가 어느벡터 소속인지 정복값을 가지고있음

	++iter;
	iter++;
	++ptr;
	ptr++;
	iter += 2; // 이렇게도 포인터 이동 가능
	ptr += 2;

	int a = 1;
	int b = a++; // b=1, a=2
	int c = ++a; // c=2, a=2

	// 그리고 이터레이터 쓸때 begin()은 해당 데이터가 잡힌 메모리 첫 주소값이 나오지만
	// end() 하면 쓰레기값이 들어가있음, 마지막 저장 컨테이너 다음칸으로 잡혀있기 때문
	// 따라서 begin은 시작 값을 호출하거나 꺼내오는 용도로 쓸 수 있지만
	// end는 그냥 마지막 위치를 알기 위한 용도임

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) // auto it = v.begin()도 가능
	{
		// ++it이 조금 더 효율적이다, it++해도 상관은 없음
		// ++it는 이터레이터 내부적으로 포인터로 주소값을 바로 넘기는 연산자 오버로딩이 일어나는데
		// it++은 연산자 오버로딩을 통해 값 복사가 일어남
		cout << *it << endl;
	}
	/*	
	왜 굳이 그냥 벡터 0값부터 마지막값으로 안하고 이터레이터를 쓰냐?
	
	1. 이터레이터는 벡터뿐만 아니라 다른 STL에도 사용할 수 있음
	2. STL 중 다른 컨테이너는 벡터처럼 인덱스 접근이 불가능한 애도 있음
	*/
	
	// const_iterator말그대로 모든 값에 const를 붙인 버전
	// reverse_iterator역방향 도 있는데 잘 안씀

	// 이터레이터 활용한 삽입 삭제
	for (vector<int>::iterator iter = v.begin(); iter != v.end();)
	{
		int data = *iter;
		if (data == 3) // 벡터안에 정보가 3인 몬스터를 모두 삭제하고 싶을때
		{
			// v.erase(iter); 를 하면 삭제는 잘 되는데 문제는 해당 이터레이터가
			// 삭제한 칸이 어떤 컨테이너 소속인지에 대한 정보까지 삭제해버려서 다음 바퀴때 터짐

			iter = v.erase(iter);
			// 이렇게 해서 삭제 이후 이터레이터가 뒤에서 당겨온 애를 다시 가리키게 해서
			// 다음 바퀴때 안터짐, 그러나 뒤에서 당겨온 애가 현재 싸이클의 이터레이터가 됐으니
			// 다음 바퀴로 넘어가면 당겨온 애를 검사도 안하고 다음칸부터 검사하게 됨
		}
		else
			++iter; // 이렇게 해서 삭제한 싸이클엔 값 변화없이 한번더 싸이클 타게 만든다
	}

	// clear() 를 쓰는 순간 이터레이터는 텅 비게 되니까 걍 이터레이터 활용한 코드를 아예 안건드는게 나음
	return 0;
}