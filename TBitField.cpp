#include "TBitField.h"

TBitField::TBitField()
{
	size = 0;
	mem = nullptr;
}

TBitField::TBitField(int _size)
{
	size = _size / (8 * sizeof(int)) + 1;
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
	TBitField tmp(*this);
	for (size_t i = 0; i < size; ++i)
	{
		tmp.mem[i] = mem[i] | right.mem[i];
	}
	return tmp;
}

TBitField TBitField::operator*(TBitField right) const
{
	TBitField tmp(*this);
	for(size_t i = 0; i < size; ++i)
	{
		tmp.mem[i] = mem[i] & right.mem[i];
	}
	return tmp;
}

TBitField TBitField::operator~() const
{
	TBitField tmp(*this);
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
	if(i < size)
		mem[i] = mem[i] | (1 << k);
}

void TBitField::del(int num)
{
	const int k = getBit(num);
	const int i = getIndex(num);
	mem[i] = mem[i] & (~(1 << k));
}

void TBitField::resize(int _size)
{
	_size = _size / (8 * sizeof(int)) + 1;
	if (_size == size) return;
	
	TBitField tmp = *this;
	delete[] mem;
	
	mem = new unsigned[_size];
	if(_size < size)
	{
		for(size_t i = 0; i < _size; ++i)
		{
			mem[i] = tmp.mem[i];
		}
		return;
	}
	for (size_t i = 0; i < size; ++i)
	{
		mem[i] = tmp.mem[i];
	}
	for(size_t i = size; i < _size; ++i)
	{
		mem[i] = 0;
	}
}

int TBitField::getSize() const
{
	return size;
}

std::string TBitField::TBitToStr(int sizeU) const
{
	std::string str;
	int k = 0;
	for(size_t i = 0; i < size; ++i)
	{
		for(size_t j = 0; j < sizeof(unsigned int) * 8; ++j)
		{
			if((mem[i] & (1 << j)) > 0)
			{
				k = i * sizeof(unsigned int) * 8 + j + 1;
				if(k <= sizeU)
				{
					str += std::to_string(k) + " ";
				}
			}
		}
	}
	return str;
}

int TBitField::getBit(long long int num) const
{
	return (num - 1) % (8 * sizeof(unsigned int));
}

int TBitField::getIndex(long long int num) const
{
	return (num - 1) / (8 * sizeof(unsigned int));
}
