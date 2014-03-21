#include <vector>
#include <iostream>
#include <algorithm>

template<class Iter>
Iter median(Iter a, Iter b, Iter c)
{
    if(*a > *b)
        std::iter_swap(a, b);
    if(*b > *c)
        std::iter_swap(b, c);
    if(*a > *c)
        std::iter_swap(a, c);
    return b;
}

template <class RandomIterator>
void insert_sort(RandomIterator first, RandomIterator last)
{
    typedef typename std::iterator_traits<RandomIterator>::value_type __Val;
    for(RandomIterator n = first + 1;n < last;++n){
        RandomIterator i = first;
        for(;i < n;++i)
            if(*n < *i)
                break;
        if(i < n){
            __Val v = *n;
            std::copy_backward(i, n, n + 1);
            *i = v;
        }
    }
}

template <class RandomIterator, class T>
RandomIterator patition(RandomIterator first, RandomIterator last, T v)
{
    for(;;){
        while(*first < v)
            ++first;
        --last;
        while(v < *last)
            --last;
        if(first >= last)
            break;
        std::iter_swap(first++, last);
    }
    return first;
}

template <class RandomIterator>
void my_nth_elem(RandomIterator first, RandomIterator nth, RandomIterator last)
{
    while(last - first > 10){
        RandomIterator mid = first + (last - first) / 2;
        mid = median(first, mid, last - 1);
        mid = patition(first, last, *mid);
        if(nth > mid)
            first = mid;
        else
            last = mid;
    }
    insert_sort(first, last);
}

void printVec(const std::vector<int> & vec)
{
    for(size_t i = 0;i < vec.size();++i)
        std::cout<<vec[i]<<", ";
    std::cout<<"\n";
}

int main()
{
    std::vector<int> vec;
    for(int i = 0;i < 20;++i)
        vec.push_back(i + 1);
    std::random_shuffle(vec.begin(), vec.end());
    printVec(vec);
    std::vector<int> vec2 = vec;

    my_nth_elem(vec.begin(), vec.begin() + 5, vec.end());
    printVec(vec);

    std::nth_element(vec2.begin(), vec2.begin() + 5, vec2.end());
    printVec(vec2);
}

