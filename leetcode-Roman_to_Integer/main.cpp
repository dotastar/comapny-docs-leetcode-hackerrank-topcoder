#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    struct Node{
        int val;
        Node * next[256];    //'A' - 'Z'
        Node(int v = 0):val(v){memset(next, 0, sizeof next);}
        ~Node(){
            for(int i = 0;i < 256;++i)
                delete next[i];
        }
    };
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        Node head;
        init(head);
        int r = 0;
        Node * cur = head.next[s[0]];
        for(size_t i = 1;i < s.size();++i){
            if(cur && cur->next[s[i]]){
                cur = cur->next[s[i]];
            }else{
                if(cur)
                    r += cur->val;
                cur = head.next[s[i]];
            }
        }
        return r + (cur ? cur->val : 0);
    }
    void init(Node & head){
        head.next['I'] = new Node(1);
        head.next['V'] = new Node(5);
        head.next['X'] = new Node(10);
        head.next['L'] = new Node(50);
        head.next['C'] = new Node(100);
        head.next['D'] = new Node(500);
        head.next['M'] = new Node(1000);

        head.next['I']->next['V'] = new Node(4);
        head.next['I']->next['X'] = new Node(9);
        head.next['X']->next['L'] = new Node(40);
        head.next['X']->next['C'] = new Node(90);
        head.next['C']->next['D'] = new Node(400);
        head.next['C']->next['M'] = new Node(900);
    }
};

/*
   DCXXI
   s[i] C X X I
   cur  D C X X I
   r    500+100+10+10+1

   MCMXCVI
   s[i] C M X C V I
   cur  M C CM X XC V I
   r    1000+900+90+5+1
*/

int main()
{
    std::cout<<Solution().romanToInt("DCXXI")<<"\n";
    std::cout<<Solution().romanToInt("MCMXCVI")<<"\n";
}
