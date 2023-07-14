#pragma once
#include "Position.h"

class c_Object
{
public:
	c_Object();
	c_Object(int x, int y);
	~c_Object();
public:
	c_Position m_pos;
};