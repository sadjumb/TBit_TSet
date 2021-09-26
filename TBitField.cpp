#include "TBitField.h"

int TBitField::getBit(size_t index)
{
    return (index - 1) % (8 * sizeof(int));
}

int TBitField::getIndex(size_t index)
{

    return (index - 1) / (8 * sizeof(int));
}

TBitField::TBitField(size_t _size = 0) : size(_size), mem(nullptr)
{
    if(size)
        mem = new unsigned int[size];
}

TBitField::~TBitField()
{
    size = 0;
    delete[] mem;
    mem = nullptr;

}

TBitField::TBitField(const TBitField& copy)
{
    size = copy.size;
    mem = new unsigned int[size];
    for (size_t i = 0; i < size; ++i)
    {
        mem[i] = copy.mem[i];
    }
}

TBitField& TBitField::operator=(const TBitField& copy)
{
    if (this == &copy)
    {
        return *this;
    }
    size = copy.size;
    delete[] mem;
    mem = new unsigned int[size];
    for (size_t i = 0; i < size; ++i)
    {
        mem[i] = copy.mem[i];
    }
    return *this;
}

TBitField TBitField::operator+(TBitField rightObj)
{
    TBitField res(size);
    for (size_t i = 0; i < size; ++i)
    {
        res.mem[i] = mem[i] | rightObj.mem[i];
    }
    return res;
}

TBitField TBitField::operator~()
{
    TBitField tmp(*this);
    for (size_t i = 0; i < size; ++i)
    {
        tmp.mem[i] = ~tmp.mem[i];
    }
    return tmp;
}

TBitField TBitField::operator*(TBitField rightObj)
{
    TBitField res(size);
    for (size_t i = 0; i < size; ++i)
    {
        res.mem[i] = mem[i] & rightObj.mem[i];
    }
    return res;
}

void TBitField::add(size_t index)
{
    size_t k = getIndex(index);
    size_t j = getBit(index);
    mem[k] = mem[k] | (1 << j);
    return;
}

void TBitField::del(size_t index)
{
    size_t k = getIndex(index);
    size_t j = getBit(index);
    mem[k] = mem[k] & (~(1 << j));
    return;
}

std::string TBitField::TBitToStr(size_t sizeU)
{
    std::string str{};
    size_t k = 0;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < sizeU; ++j)
        {
            if (mem[i] & (1 << j) == 1)
            {
                k = i * (sizeof(unsigned int) * 8) + 1 + j;
                if (k <= sizeU)
                {
                    str = str + " " + std::to_string(k);
                }
            }
        }
    }
    return str;
}
