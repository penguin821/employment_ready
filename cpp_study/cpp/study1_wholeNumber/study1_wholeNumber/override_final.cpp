#include <iostream>
using namespace std;

class Object
{
	//virtual void attack() // �θ� �������̵� �� �Լ��� ������ ������
	//{
	//
	//}
};

class Player : public Object
{
	// ������, �θ� ������ �Լ��� �������ؼ� ���Ÿ�
	// override�� �ڿ� ���̸� ������ġó�� �ۿ�
	virtual void attack() override final // final=���̻� ������� �ʰ� �갡 ���������� ���ִ�
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