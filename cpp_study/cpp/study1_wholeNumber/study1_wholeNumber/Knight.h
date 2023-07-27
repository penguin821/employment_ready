#pragma once
#include "Position.h"
#include "Player.h"


class Knight : public Player
{
public:
	Knight();
	Knight(int x, int y) : Player(x, y) {};
	Knight(const Knight& copy);
	Knight(const Knight& copy) : Player(copy) {} ; // m_pet(copy.m_pet)도 같이 (포인터 아닐시)
	~Knight();
public:
	Knight& operator=(const Knight& copy);
public:
	
};