// Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы

#include <iostream>

#include "TBitField.h"

int main()
{
    TBitField a(128), b(a), c;
	c = a;

	c.add(56);
	c.add(32);
	c.add(70);
	c.add(71);
	c.add(72);
	c.add(73);

	b.add(12);
	b.add(23);
	b.add(56);
	
	
	TBitField k = c * b;
	std::cout << k.TBitToStr(128);
	return 0;
}


