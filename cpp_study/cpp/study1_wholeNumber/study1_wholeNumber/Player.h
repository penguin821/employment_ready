#pragma once
#include "Object.h"

class c_Player : public c_Object
{
public:
	c_Player();
	c_Player(int x, int y) : c_Object(x, y) {};
	~c_Player();
};