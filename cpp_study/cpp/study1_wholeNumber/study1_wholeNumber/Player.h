#pragma once
#include "Object.h"
#include "Pet.h"

class Player : public Object
{
public:
	Player();
	Player(int x, int y) : Object(x, y) {};
	~Player();
public:
	Pet* m_pet = nullptr;
};