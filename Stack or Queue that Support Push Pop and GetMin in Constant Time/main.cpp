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

class MinStack2 {
    vector<int> s_, m_;
public:
    void push(int x) {
        if(m_.empty() || x < s_[m_.back()])
            m_.push_back(s_.size());
        s_.push_back(x);
    }
    void pop() {
        if(s_.empty())
            return;
        const int v = s_.back();
        s_.pop_back();
        if(!m_.empty() && s_.size() == m_.back())
            m_.pop_back();
    }
    int top() {
        return (s_.empty() ? 0 : s_.back());
    }
    int getMin() {
        return (m_.empty() ? 0 : s_[m_.back()]);
    }
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