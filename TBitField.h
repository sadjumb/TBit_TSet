#pragma once
#include<string>
class TBitField
{
public:
	TBitField(size_t);
	~TBitField();
	TBitField(const TBitField&);
	TBitField& operator=(const TBitField&);
	TBitField operator+(TBitField);
	TBitField operator~();
	TBitField operator*(TBitField);
	void add(size_t index);
	void del(size_t index);
	std::string TBitToStr(size_t sizeU);

private:
	unsigned int* mem;
	size_t size;
	int getBit(size_t);
	int getIndex(size_t);
};

