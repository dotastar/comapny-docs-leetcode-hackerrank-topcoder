#include "../inc.h"

class MedianFinder
{
public:
    void insert(int val){
        if (maxHeap_.empty() || val <= maxHeap_.top())
            maxHeap_.push(val);
        else
            minHeap_.push(val);
        while (maxHeap_.size() > minHeap_.size() + 1){
            val = maxHeap_.top();
            maxHeap_.pop();
            minHeap_.push(val);
        }
        while (maxHeap_.size() < minHeap_.size()){
            val = minHeap_.top();
            minHeap_.pop();
            maxHeap_.push(val);
        }
    }
    int getMedian() const{
        assert(!maxHeap_.empty());
        if (maxHeap_.size() == minHeap_.size())
            return (maxHeap_.top() + minHeap_.top()) / 2;
        return maxHeap_.top();
    }
private:
    priority_queue<int, vector<int>, std::greater<int> > minHeap_;   //values >= median
    priority_queue<int> maxHeap_;   //values <= median
};

int getMedianSlow(vector<int> & v)
{
    assert(!v.empty());
    sort(v.begin(), v.end());
    size_t s = v.size();
    if ((s & 1) == 0)
        return (v[s / 2] + v[s / 2 - 1]) / 2;
    return v[s / 2];
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<int> v;
    MedianFinder m;
    for (int i = 0; i < 3000; ++i){
        v.push_back(rand() & ((1 << 14) - 1));
        m.insert(v.back());
    }
    cout << m.getMedian() << endl;
    cout << getMedianSlow(v) << endl;
    //print(v);
}