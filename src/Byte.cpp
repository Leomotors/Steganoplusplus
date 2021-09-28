#include "Byte.hpp"

#include <array>
std::array<bool, BITS> toByte(char _c)
{
    int c = (int)_c;
    std::array<bool, BITS> data;
    for (int i = BITS - 1; i >= 0; i--)
    {
        data[i] = c % 2;
        c /= 2;
    }
    return data;
}
