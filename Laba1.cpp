// Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы

#include <iostream>

#include "TBitField.h"

int main()
{
    TBitField a(72), b(a), c;
	c = a;
	c.add(33);
	c.add(56);
	c.add(32);
	b.add(12);
	b.add(23);
	
	
	c = c + b;
	std::cout << c.TBitToStr(72);
	return 0;
}


