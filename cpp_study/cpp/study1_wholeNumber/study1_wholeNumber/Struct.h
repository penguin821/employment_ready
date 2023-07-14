#pragma once
#include "Position.h"

c_Position operator+(int num, const c_Position pos)
{
	c_Position ret;

	ret.m_x = num + pos.m_x;
	ret.m_y = num + pos.m_y;

	return ret;
}