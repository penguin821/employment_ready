#include <iostream>
#include "Player.h"
#include "Struct.h"
using namespace std;

int main()
{
	c_Player cPlayer1(1, 1), cPlayer2(2, 2);

	cout << "플레이어 1 위치 : " << cPlayer1.m_pos.m_x << " , " << cPlayer1.m_pos.m_y << endl;
	cout << "플레이어 2 위치 : " << cPlayer2.m_pos.m_x << " , " << cPlayer2.m_pos.m_y << endl;

	c_Position pos;
	pos = cPlayer1.m_pos + cPlayer1.m_pos;
	cout << "이후 위치 : " << pos.m_x << " , " << pos.m_y << endl;
	//pos = pos + 5;
	cout << "이후 위치 : " << pos.m_x << " , " << pos.m_y << endl;
	//pos = 2 + pos;
	cout << "이후 위치 : " << pos.m_x << " , " << pos.m_y << endl;

	bool isSame = (pos == cPlayer2.m_pos);
	cout << "값 일치? : " << isSame << endl;
}