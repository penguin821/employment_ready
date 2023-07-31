#pragma once
#include "Position.h"

class Object
{
public:
	Object();
	Object(int x, int y);
	virtual ~Object();
public:
	void SetHp(int* copy);
	int GetHp();
	void SetMp(int* copy);
	int GetMp();
public:
	int m_hp = 0;
	int m_mp = 0;
	Position m_pos;
};