#pragma once

class Position
{
public:
	Position();
	// Position(const Position& arg); ���� ������
	~Position();
public:
	Position operator+(const Position& pos);
	Position operator+(int pos);
	Position& operator=(int pos);
	// Position& operator=(const Position& pos); ���� ���� ������
	bool operator==(const Position& pos);
public:
	int m_x = 0;
	int m_y = 0;
};