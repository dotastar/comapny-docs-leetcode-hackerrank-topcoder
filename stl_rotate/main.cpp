#include <iostream>
#include <cassert>

int gcd(int a, int b)
{
    assert(a > 0 && b > 0);
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void cycle(int * v, int sz, int from, int step)
{
    assert(step > 0);
    int p = from, n = p + step;
    assert(n < sz);
    assert(v);
    int t = v[p];
    while(n != from){
        v[p] = v[n];
        p = n;
        n += step;
        if(n >= sz)
            n -= sz;
    }
    v[p] = t;
}

//rotate array [v, sz] with k steps left
void rotate(int * v, int sz, int k)
{
    if(sz < 2)
        return;
    k %= sz;
    if(!k)
        return;
    for(int d = gcd(sz, k);d > 0;--d)
        cycle(v, sz, d, k);
}


template <class ForwardIterator>
  void my_rotate (ForwardIterator first, ForwardIterator middle,
               ForwardIterator last)
{
  ForwardIterator next = middle;
  while (first!=next)
  {
      std::iter_swap (first++,next++);
    if (next==last) next=middle;
    else if (first==middle) middle=next;
  }
}

int main()
{
    int v[] = {1,2,3,4,5,6,7,8,9,10};

    rotate(v, sizeof v / sizeof v[0], 3);

    for(size_t i = 0;i < sizeof v / sizeof v[0];++i)
        std::cout<<v[i]<<",";
    std::cout<<"\n";

    //std::rotate();
}
