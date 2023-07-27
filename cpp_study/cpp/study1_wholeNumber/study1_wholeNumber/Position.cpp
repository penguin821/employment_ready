#include "Position.h"

Position::Position()
{

}

Position::~Position()
{

}

Position Position::operator+(const Position& back_pos)
{
	Position pos;

	pos.m_x = m_x + back_pos.m_x;
	pos.m_y = m_y + back_pos.m_y;

	return pos;
}

Position Position::operator+(int num)
{
	Position pos;

	pos.m_x = m_x + num;
	pos.m_y = m_y + num;

	return pos;
}

bool Position::operator==(const Position& back_pos)
{
	if ((m_x == back_pos.m_x) && (m_y == back_pos.m_y))
		return true;
	else
		return false;
}

Position& Position::operator=(int num)
{
	m_x = num;
	m_y = num;
	// this = ���� ����Ű�� ������, �� �ڽ��� �ּ�
	return *this;
}