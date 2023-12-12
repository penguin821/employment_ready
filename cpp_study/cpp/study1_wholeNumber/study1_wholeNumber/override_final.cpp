#include <iostream>
using namespace std;

class Object
{
	//virtual void attack() // 부모에 오버라이딩 할 함수가 없으면 에러뜸
	//{
	//
	//}
};

class Player : public Object
{
	// 재정의, 부모가 물려준 함수를 재정의해서 쓸거면
	// override를 뒤에 붙이면 안전장치처럼 작용
	virtual void attack() override final // final=더이상 상속하지 않고 얘가 마지막으로 쓸애다
	{

	}
};


class Knight : public Player
{
	virtual void attack() override
	{

	}
};



int main()
{
	Player p1;
	return 0;
}