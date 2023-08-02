#include "Knight.h"

Knight::Knight()
{

}

Knight::~Knight()
{
	delete m_pet;
}

Knight::Knight(const Knight& copy)
{
	m_pos = copy.m_pos;
	m_pet = new Pet(*copy.m_pet);
}

Knight& Knight::operator=(const Knight& copy)
{
	m_pos = copy.m_pos;
	m_pet = new Pet(*copy.m_pet);
	return *this;
}

void Knight::operator()()
{

}