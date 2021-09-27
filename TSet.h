#pragma once
#include "TBitField.h"

class TSet
{
public:
	TSet() = default;
	TSet(int);
	TSet(const TSet&);
	~TSet() = default;

	TSet& operator=(TSet);
	TSet operator+(TSet);
	TSet operator*(TSet);
	TSet operator~();

	void add(int);
	void del(int);
	std::string ToString();
	

private:
	int size;
	TBitField tb;
};

