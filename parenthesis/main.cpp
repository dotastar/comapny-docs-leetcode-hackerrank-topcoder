#include <iostream>
#include <cassert>
#include <vector>

//solution 1
void printRecursive(std::vector<bool> & bits, int index, int depth, int left)
{
    if(left){
        bits[index] = true;
        printRecursive(bits, index + 1, depth + 1, left - 1);
        if(depth > 0){
            bits[index] = false;
            printRecursive(bits, index + 1, depth - 1, left);
        }
    }else{
        assert(index <= int(bits.size()));
        for(int i = 0;i < index;++i)
            std::cout<<(bits[i] ? '(' : ')');
        for(size_t i = index;i < bits.size();++i)
            std::cout<<')';
        std::cout<<"\n";
    }
}

void printParanthesis(int n)
{
    if(!n)
        return;
    assert(n > 0);
    std::vector<bool> bits(n * 2);
    bits[0] = true;
    printRecursive(bits, 1, 1, n - 1);
}

int main()
{
    printParanthesis(2);
    printParanthesis(3);
    printParanthesis(4);
}
