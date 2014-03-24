#include "../inc.h"

struct MyStack
{
    void push(int v){
        stack_.push_back(v);
        if(minStack_.empty() || v <= minStack_.back())
            minStack_.push_back(v);
    }
    bool pop(int & v){
        if(stack_.empty())
            return false;
        v = stack_.back();
        stack_.pop_back();
        assert(!minStack_.empty());
        if(v == minStack_.back())
            minStack_.pop_back();
        return true;
    }
    bool getMin(int & v) const{
        if(minStack_.empty())
            return false;
        v = minStack_.back();
        return true;
    }
private:
    vector<int> stack_, minStack_;
};

struct MyQueue
{
    void push_rear(int v){
        if(!que_.empty() && que_.back() > v){
            while(!minQue_.empty() && minQue_.back() > v)
                minQue_.pop_back();
            minQue_.push_back(v);
        }
        que_.push_back(v);
    }
    bool pop_front(int & v){
        if(que_.empty())
            return false;
        v = que_.front();
        que_.pop_front();
        if(!minQue_.empty() && v == minQue_.front())
            minQue_.pop_front();
        return true;
    }
    bool getMin(int & v) const{
        if(que_.empty())
            return false;
        v = que_.front();
        if(!minQue_.empty() && minQue_.front() < v)
            v = minQue_.front();
        return true;
    }
private:
    deque<int> que_, minQue_;
};

int main()
{
}