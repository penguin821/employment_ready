#pragma once

class c_Position
{
public:
	c_Position();
	// c_Position(const c_Position& arg); ���� ������
	~c_Position();
public:
	c_Position operator+(const c_Position& pos);
	c_Position operator+(int pos);
	c_Position& operator=(int pos);
	// c_Position& operator=(const c_Position& pos); ���� ���� ������
	bool operator==(const c_Position& pos);
public:
	int m_x = 0;
	int m_y = 0;
};