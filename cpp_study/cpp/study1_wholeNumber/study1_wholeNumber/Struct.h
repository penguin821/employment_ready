#pragma once
#include "Position.h"

Position operator+(int num, const Position pos)
{
	Position ret;

	ret.m_x = num + pos.m_x;
	ret.m_y = num + pos.m_y;

	return ret;
}