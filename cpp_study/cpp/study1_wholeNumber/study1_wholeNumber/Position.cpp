#include "Position.h"

c_Position::c_Position()
{

}

c_Position::~c_Position()
{

}

c_Position c_Position::operator+(const c_Position& back_pos)
{
	c_Position pos;

	pos.m_x = m_x + back_pos.m_x;
	pos.m_y = m_y + back_pos.m_y;

	return pos;
}

c_Position c_Position::operator+(int num)
{
	c_Position pos;

	pos.m_x = m_x + num;
	pos.m_y = m_y + num;

	return pos;
}

bool c_Position::operator==(const c_Position& back_pos)
{
	if ((m_x == back_pos.m_x) && (m_y == back_pos.m_y))
		return true;
	else
		return false;
}

c_Position& c_Position::operator=(int num)
{
	m_x = num;
	m_y = num;
	// this = 나를 가르키는 포인터, 내 자신의 주소
	return *this;
}