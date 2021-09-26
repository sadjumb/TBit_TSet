#include "TBitField.h"

TBitField::TBitField()
{
	size = 0;
	mem = nullptr;
}

TBitField::TBitField(int _size)
{
	size = _size / (8 * sizeof(int) + 1);
	mem = new unsigned int [size] { 0 };
}

TBitField::TBitField(const TBitField& copy)
{
	size = copy.size;
	mem = new unsigned int[size];
	for(size_t i = 0; i < size; ++i)
	{
		mem[i] = copy.mem[i];
	}
}

TBitField::~TBitField()
{
	size = 0;
	delete[] mem;
	mem = nullptr;
}

TBitField& TBitField::operator=(const TBitField& right)
{
	if(this == &right)
	{
		return *this;
	}
	delete[] mem;
	size = right.size;
	mem = new unsigned int[size];
	for(size_t i = 0; i < size; ++i)
	{
		mem[i] = right.mem[i];
	}
	return *this;
}

TBitField TBitField::operator+(const TBitField& right) const
{
	TBitField tmp(size);
	for (size_t i = 0; i < size; ++i)
	{
		tmp.mem[i] = mem[i] | right.mem[i];
	}
	return tmp;
}

TBitField TBitField::operator*(TBitField right) const
{
	TBitField tmp(size);
	for(size_t i = 0; i < size; ++i)
	{
		tmp.mem[i] = mem[i] & right.mem[i];
	}
	return tmp;
}

TBitField TBitField::operator~() const
{
	TBitField tmp(size);
	for(size_t i = 0; i < size; ++i)
	{
		tmp.mem[i] = ~mem[i];
	}
	return tmp;
}

void TBitField::add(int num)
{
	int k = getBit(num);
	int i = getIndex(num);
	mem[i] = mem[i] | (1 << k);
	size += (sizeof(int) * 8);
}

void TBitField::del(int num)
{
	int k = getBit(num);
	int i = getIndex(num);
	mem[i] = mem[i] & ~(1 << k);
	size -= (sizeof(int) * 8);
}

std::string TBitField::TBitToStr(int sizeU) const
{
	std::string str;
	int k;
	for(size_t i = 0; i < size; ++i)
	{
		for(size_t j = 0; j < sizeof(unsigned int) * 8; ++j)
		{
			if((mem[i] & (1 << j)) > 0)
			{
				k = i * sizeof(unsigned int) * 8 + 1 + j;
				str += " " + std::to_string(k);
			}
		}
	}
	return str;
}

int TBitField::getBit(int num) const
{
	return (num - 1) % (8 * sizeof(unsigned int));
}

int TBitField::getIndex(int num) const
{
	return (num - 1) / (8 * sizeof(unsigned int));
}
