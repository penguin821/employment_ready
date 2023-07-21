#include <iostream>
#include "Player.h"
#include "Struct.h"
using namespace std;

int main()
{
	c_Player cPlayer1(1, 1), cPlayer2(2, 2);

	cout << "�÷��̾� 1 ��ġ : " << cPlayer1.m_pos.m_x << " , " << cPlayer1.m_pos.m_y << endl;
	cout << "�÷��̾� 2 ��ġ : " << cPlayer2.m_pos.m_x << " , " << cPlayer2.m_pos.m_y << endl;

	c_Position pos;
	pos = cPlayer1.m_pos + cPlayer1.m_pos;
	cout << "���� ��ġ : " << pos.m_x << " , " << pos.m_y << endl;
	//pos = pos + 5;
	cout << "���� ��ġ : " << pos.m_x << " , " << pos.m_y << endl;
	//pos = 2 + pos;
	cout << "���� ��ġ : " << pos.m_x << " , " << pos.m_y << endl;

	bool isSame = (pos == cPlayer2.m_pos);
	cout << "�� ��ġ? : " << isSame << endl;
}