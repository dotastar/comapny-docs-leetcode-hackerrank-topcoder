#include <iostream>
#include <cassert>

void merge1(const int * a, int * b, int len)
{
    if(len <= 0)
        return;
    assert(a && b);
    int i = 0, j = 0, k = len;
    while(i < len && j < len){
        if(a[i] < b[j])
            b[k] = a[i++];
        else
            b[k] = b[j++];
        if(++k == 2 * len)
            k = 0;
    }
    if(i < len){
        while(i < len){
            b[k] = a[i++];
            if(++k == 2 * len)
                k = 0;
        }
    }else if(j < len){
        while(j < len){
            b[k] = b[j++];
            if(++k == 2 * len)
                k = 0;
        }
    }
    for(i = 0;i < len;++i){
        int t = b[i];
        b[i] = b[i + len];
        b[i + len] = t;
    }
}

void merge2(const int * a, int * b, int len)
{
    if(len <= 0)
        return;
    assert(a && b);
    int i = len - 1, j = i, k = 2 * len - 1;
    while(i >= 0 && j >= 0)
        if(a[i] > b[j])
            b[k--] = a[i--];
        else
            b[k--] = b[j--];
    memcpy(b, a, sizeof(int) * (i + 1));
}

int main()
{
    {
        int a[6] = {1,3,4,6,8,9};
        int b[12] = {0,2,5,7,10,11};
        merge1(a, b, 6);
        for(int i = 0;i < 12;++i)
            std::cout<<b[i]<<",";
        std::cout<<"\n";
    }
    std::cout<<"---\n";
    {
        int a[6] = {1,3,4,6,8,9};
        int b[12] = {0,2,5,7,10,11};
        merge2(a, b, 6);
        for(int i = 0;i < 12;++i)
            std::cout<<b[i]<<",";
        std::cout<<"\n";
    }
}