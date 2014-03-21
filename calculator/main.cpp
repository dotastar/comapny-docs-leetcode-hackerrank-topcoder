#include <list>
#include <iostream>
#include <cassert>

class CNode
{
    CNode * parent_;
    CNode * left_;
    CNode * right_;
    double val_;
    char type_;
public:
    explicit CNode(char t):parent_(NULL),left_(NULL),right_(NULL),val_(0),type_(t){}
    explicit CNode(double v):parent_(NULL),left_(NULL),right_(NULL),val_(v),type_(0){}
    bool hasParent() const{return (NULL != parent_);}
    CNode * parent() const{return parent_;}
    void setRight(CNode & n){
        right_ = &n;
        n.parent_ = this;
    }
    void setLeft(CNode & n){
        left_ = &n;
        n.parent_ = this;
    }
    bool isNumber() const{return (0 == type_);}
    bool isAddMinus() const{return ('+' == type_ || '-' == type_);}
    bool isMulDiv() const{return ('*' == type_ || '/' == type_);}
    double calc() const{
        if(isNumber())
            return val_;
        assert(left_ && right_);
        switch(type_){
            case '+':return (left_->calc() + right_->calc());
            case '-':return (left_->calc() - right_->calc());
            case '*':return (left_->calc() * right_->calc());
            case '/':return (left_->calc() / right_->calc());
            default:;
        }
        assert(false);
        return 0;
    }
};

typedef std::list<CNode> __Nodes;

const char * parseToken(const char * p, __Nodes & nodes)
{
    assert(p);
    if('+' == *p || '-' == *p || '*' == *p || '/' == *p){
        nodes.push_back(CNode(*p++));
        return p;
    }else if('0' <= *p && *p <= '9'){
        double v = 0;
        do{
            v = v * 10 + *p - '0';
            ++p;
        }while('0' <= *p && *p <= '9');
        nodes.push_back(CNode(v));
        return p;
    }
    return NULL;
}

CNode & findHead(CNode & n)
{
    CNode * p = &n;
    for(;p->hasParent();p = p->parent());
    return *p;
}

const CNode & findHead(const CNode & n)
{
    const CNode * p = &n;
    for(;p->hasParent();p = p->parent());
    return *p;
}

CNode & findSubHead(CNode & n)
{
    CNode * p = &n;
    while(p->hasParent()){
        CNode * pp = p->parent();
        if(!pp->isMulDiv())
            break;
        p = pp;
    }
    return *p;
}

void adjustNodes(CNode & last, CNode & cur)
{
    if(last.isNumber()){
        if(cur.isAddMinus()){
            cur.setLeft(findHead(last));
            return;
        }else if(cur.isMulDiv()){
            CNode & h = findSubHead(last);
            CNode * p = h.parent();
            if(p)
                p->setRight(cur);
            cur.setLeft(h);
            return;
        }
    }else{
        if(cur.isNumber()){
            last.setRight(cur);
            return;
        }
    }
    assert(false);
}

bool buildTree(__Nodes & nodes)
{
    if(nodes.size() < 2)
        return true;
    __Nodes::reverse_iterator i = nodes.rbegin();
    CNode & cur = *i++;
    CNode & last = *i;
    if(cur.isNumber() == last.isNumber())
        return false;
    adjustNodes(last, cur);
    return true;
}

bool parseExpr(const char * expr, __Nodes & nodes)
{
    assert(expr);
    for(const char * p = expr;*p;){
        if(NULL == (p = parseToken(p, nodes)))
            return false;
        if(!buildTree(nodes))
            return false;
    }
    if(nodes.empty() || !nodes.back().isNumber())
        return false;
    return true;
}

double calcTree(const __Nodes & nodes)
{
    if(nodes.empty())
        return 0;
    const CNode & h = findHead(nodes.front());
    return h.calc();
}

double eval(const char * expr)
{
    __Nodes nodes;
    if(parseExpr(expr, nodes))
        return calcTree(nodes);
    return 0;   //error format expr
}

int main()
{
    std::cout<<eval("2+5/2")<<"\n";     //4.5
    std::cout<<eval("12*2+5/2-3")<<"\n";//23.5
}