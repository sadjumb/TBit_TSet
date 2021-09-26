#pragma once
#include<string>
class TBitField
{
public:
	TBitField();
	TBitField(int);
	TBitField(const TBitField&);
	~TBitField();
	
	TBitField& operator=(const TBitField&);
	TBitField operator+(const TBitField&) const;
	TBitField operator*(TBitField) const;
	TBitField operator~() const;

	void add(int);
	void del(int);
	
	std::string TBitToStr(int sizeU) const;

private:
	unsigned int* mem;
	int size;
	int getBit(int) const;
	int getIndex(int) const;
};

