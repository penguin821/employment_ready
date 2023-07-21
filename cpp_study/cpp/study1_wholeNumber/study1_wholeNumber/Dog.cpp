#include "Dog.h"

Dog::Dog()
{

}

Dog::~Dog()
{

}

// 타입 변환 생성자
Dog::Dog(const Knight& knight)
{

}

// 타입 변환 연산자 (앞에 자료형이 없어도 뒤에 클래스명이 다 설명해줘서 가능)
Dog::operator Knight()
{
	return (Knight)(*this);
}
