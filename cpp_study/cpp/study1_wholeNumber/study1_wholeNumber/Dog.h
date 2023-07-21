#pragma once
#include "Knight.h"

class Dog
{
public:
	Dog();
	Dog(const Knight& knight);
	~Dog();
public:
	operator Knight();
};