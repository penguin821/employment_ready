#include "Object.h"

Object::Object()
{

}

Object::Object(int x, int y)
{
	m_pos.m_x = x;
	m_pos.m_y = y;
}

Object::~Object()
{

}

void Object::SetHp(int* copy)
{
	m_hp = *copy;
}

int Object::GetHp()
{
	return m_hp;
}

void Object::SetMp(int* copy)
{
	m_mp = *copy;
}

int Object::GetMp()
{
	return m_mp;
}
