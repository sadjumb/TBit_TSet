#include "TSet.h"

TSet::TSet(int _size = 0) : size(_size), tb(size)
{}

TSet::TSet(const TSet& copy) : size(copy.size), tb(copy.tb)
{}

TSet& TSet::operator=(TSet copy)
{
	size = copy.size;
	tb = copy.tb;
	return *this;
}

TSet TSet::operator+(TSet right)
{
	TSet tmp(*this);
	if (size == right.size)
	{
		tmp.tb = tmp.tb + right.tb;
	}
	return tmp;;
}

TSet TSet::operator*(TSet right)
{
	TSet tmp(*this);
	if (size == right.size)
	{
		tmp.tb = tmp.tb * right.tb;
	}
	return tmp;;
}

TSet TSet::operator~()
{
	TSet tmp(*this);
	tmp.tb = ~tmp.tb;
	return tmp;
}

void TSet::add(int num)
{
	if(num > 0 && num < size)
		tb.add(num);
}

void TSet::del(int num)
{
	tb.del(num);
}

std::string TSet::ToString()
{	
	return tb.TBitToStr(size);
}


