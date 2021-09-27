#include <iostream>
#include "TBitField.h"

int main()
{
    TBitField a(32), b(a), c;
	c = a;
	c = c;

	//a = ~a;
	
	
	//a.add(250);
	a.add(1);
	a.add(32);
	a.add(36);
	a.add(65);
	//a.add(1);
	//a.add(2);
	//a.add(3);
	//a.add(4);
	//a.add(5);
	//a.add(6);
	//a.add(10);
	//a.add(50);
	std::cout << a.TBitToStr(96) << " Size: " << a.getSize();
	
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
	//std::cout << k.TBitToStr(128) << std::endl;
	////a = ~a;
	//std::cout << a.TBitToStr(32);
	
	return 0;
}


