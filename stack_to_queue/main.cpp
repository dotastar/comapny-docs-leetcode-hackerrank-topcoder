#include "../inc.h"

class CStack
{
public:
    void push(int i){v_.push_back(i);}
    void pop(){v_.pop_back();}
    bool empty() const{return v_.empty();}
    int top() const{return v_.back();}
private:
    vector<int> v_;
};

class CQueue
{
public:
    void push_back(int i){
        while(!s2_.empty()){
            s1_.push(s2_.top());
            s2_.pop();
        }
        s1_.push(i);
    }
    void pop_front(){
        while(!s1_.empty()){
            s2_.push(s1_.top());
            s1_.pop();
        }
        s2_.pop();
    }
    bool empty() const{return (s1_.empty() && s2_.empty());}
    int front(){
        while(!s1_.empty()){
            s2_.push(s1_.top());
            s1_.pop();
        }
        return s2_.top();
    }
private:
    CStack s1_, s2_;
};

int main()
{
    {
        const int val[] = {1,2,3,4,5,6,7,8};
        CQueue q;
        vector<int> r;
        for(size_t i = 0;i < sizeof val / sizeof val[0];++i){
            q.push_back(val[i]);
            if(0 == (i & 3)){
                r.push_back(q.front());
                q.pop_front();
            }
        }
        while(!q.empty()){
            r.push_back(q.front());
            q.pop_front();
        }
        if(r.size() != sizeof val / sizeof val[0]){
            cerr<<"Wrong!\n";
            return 1;
        }
        for(size_t i = 0;i < r.size();++i)
            if(r[i] != val[i]){
                cerr<<"Wrong!\n";
                return 1;
            }
    }
    cout<<"Right\n";
}
