#include <iostream>
#include "TBitField.h"
#include "TSet.h"



//testing TBitField
//int main()
//{
//    TBitField a(64), b(a), c;
//	c = a;
//	//c = c;
//
//	//a = ~a;
//	
//	
//	//a.add(250);
//	a.add(1);
//	a.add(5);
//	a.add(5);
//	a.add(6);
//	a.add(32);
//	a.add(36);
//	a.add(63);
//
//	
//	//a.add(1);
//	//a.add(2);
//	//a.add(3);
//	//a.add(4);
//	//a.add(5);
//	//a.add(6);
//	//a.add(10);
//	//a.add(50);
//	
//	std::cout << a.TBitToStr(64) << " Size: " << a.getSize();
//	
//	c.add(56);
//	c.add(32);
//	c.add(70);
//	c.add(71);
//	c.add(72);
//	c.add(73);
//	
//	
//	b.add(12);
//	b.add(23);
//	b.add(56);
//	
//	TBitField k = c * b;
//	//std::cout << k.TBitToStr(128) << std::endl;
//	////a = ~a;
//	//std::cout << a.TBitToStr(32);
//	
//	return 0;
//}



int main()
{
	TSet a, b, c(139);
	TSet r(64);
	a = r;
	a.add(24);
	a.add(32);
	a.add(64);
	b = a;
	b.add(31);
	b.add(44);
	b.add(31);
	c.add(101);
	a.add(-3);
	a.add(160);
	c.add(141);

	TSet sum = a + b;
	TSet mult = a * b;
	TSet non = ~a;
	//c = ~c;

	std::cout << "c: " << c.ToString() << std::endl;
	//c = c + a;

	//std::cout << "c: " << c.ToString() << std::endl;
	//std::cout << "a: " << a.ToString() << std::endl;
	//std::cout << "b: " << b.ToString() << std::endl;
	//std::cout << "sum: " << sum.ToString() << std::endl;
	//std::cout << "mult: " << mult.ToString() << std::endl << std::endl;
	//std::cout << "~: " << non.ToString() << std::endl;

	return 0;
}

