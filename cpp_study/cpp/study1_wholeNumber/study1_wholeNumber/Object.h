#pragma once
#include "Position.h"

class Object
{
public:
	Object();
	Object(int x, int y);
	~Object();
public:
	Position m_pos;
};