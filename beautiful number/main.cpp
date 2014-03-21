#include <iostream>
#include <cassert>

int beauty(int n)
{
    assert(n > 0);
    int r = 0;
    for(int i = 0;n > 0;n >>= 1)
        if(n & 1)
            r += i;
        else
            ++i;
    return r;
}

int main()
{
    std::cout<<beauty(12)<<"\n";
}