#include <iostream>
#include <vector>

#include <algorithm>

/*
find
find_if
count
count_if
all_of
any_of
none_of
for_each
remove
remove_if
*/

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;
	for (int i = 0; i < 30; i++)
	{
		v.push_back(rand() % 30);
	}
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "===============================================" << endl;
	// 1. num이라는 숫자가 벡터에 있는지 확인하는 기능
	{
		int number = 25;
		bool found = false;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it == number)
			{
				found = true;
				cout << *it << endl;
				break;
			}
		}

		//-------------------------------------------------
		auto it = find(v.begin(), v.end(), number); // 못찾으면 v.end() 나옴
		if (it != v.end())
			cout << *it << endl;
	}
	cout << "===============================================" << endl;
	// 2. 11로 나뉘어지는 숫자가 벡터에 있는지 확인하는 기능
	{
		bool found = false;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			if ((*it) % 11 == 0 && (*it!=0))
			{
				found = true;
				cout << "found : " << *it << endl;
				break;
			}
		}

		//-------------------------------------------------
		struct Divide11
		{
			bool operator()(int n)
			{
				return (n % 11) == 0;
			}
		};

		auto it = find_if(v.begin(), v.end(), Divide11());
		auto it1 = find_if(v.begin(), v.end(), [](int n) {return (n % 11) == 0; }); // 람다를 배운 이후

	}
	cout << "===============================================" << endl;
	// 3. 홀수인 숫자의 개수
	{
		int count = 0;
		int even = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if ((*it) % 2 != 0)
				count++;
		}
		cout << count << endl;

		//-------------------------------------------------

		count = count_if(v.begin(), v.end(), [](int n) {return (n % 2) != 0; }); // 얘는 이터레이터 아니고 std임
		cout << count << endl;
		// 모든 데이터가 홀수입니까?
		bool is = all_of(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
		// 홀수인 데이터가 하나라도 있습니까?
		bool is1 = any_of(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
		// 모든 데이터가 홀수가 아닙니까?
		bool is2 = none_of(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
	}
	cout << "===============================================" << endl;
	// 4. 벡터 내 모든 숫자 곱3
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			(*it) *= 3;
			cout << *it << endl;
		}

		//-------------------------------------------------
		cout << "===============================================" << endl;
		for_each(v.begin(), v.end(), [](int& n) {return n *= 3; });
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
	}
	cout << "===============================================" << endl;
	// 홀수인 데이터를 일괄 삭제
	{
		/*
		remove 사용시 주의사항
		벡터에 1 4 3 5 8 2 가 들어있다 치면
		remove 홀수 했을때 내용물이
		4 8 2 가 되는게 아니라 4 8 2 5 8 2 가 된다

		remove 작동 방식이 지가 스스로 삭제하고 빈칸 땡겨와주는게 아니라 (비효율적이므로)  
		삭제하면 안되는 데이터를 앞공간부터 순차적으로 복사해온다
		그래서 홀수가 아닌 482를 1,2,3번째칸에 복사해온것
		즉, 네번째칸부턴 필요없는 데이터들 뿐이라는거

		따라서 remove를 제대로 사용하려면
		*/
		int num = 4;

		auto it = remove(v.begin(), v.end(), num);
		auto it1 = remove_if(v.begin(), v.end(), [](int n) {return (n % 2) != 0; });
		// 이렇게 하면 이터레이터가 필요없는 데이터 시작점을 가리킴
		v.erase(it, v.end());

		// 한방에 해결하려면
		v.erase(remove_if(v.begin(), v.end(), [](int n) {return (n % 2) != 0; }), v.end());
	}


	return 0;
}