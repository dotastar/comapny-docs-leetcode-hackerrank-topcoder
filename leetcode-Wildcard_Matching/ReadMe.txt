Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false



dozerg:
可以简化成二维DP：
令T(i, j)表示s[1...i]是否能用p[1...j]匹配，则有状态转换方程：
T(i, j) = T(i, j - 1) || T(i - 1, j), if p[j] == '*'（如果s(i)匹配p(j-1)，那么也匹配p(j-1)*；同理，如果s(i-1)匹配p(j)=p(j-1)*，那么s(i)也匹配p(j)）
        = T(i - 1, j - 1), if p[j] = '?'
        = T(i - 1, j - 1) && s[i] == p[j]
初始状态：T(0, 0) = true        


others Analysis:
For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
if there is no *,  return false;
if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.

e.g.

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;

Note that in char array, the last is NOT NULL, to check the end, use  "*p"  or "*p=='\0'".

bool isMatch(const char *s, const char *p)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
         
    const char* star=NULL;
    const char* ss=s; 
    while (*s){
        if ((*p=='?')||(*p==*s)){s++;p++;continue;}
        if (*p=='*'){star=p++; ss=s;continue;}
        if (star){ p = star+1; s=++ss;continue;}
        return false;
    }
    while (*p=='*'){p++;}
    return !*p;
}