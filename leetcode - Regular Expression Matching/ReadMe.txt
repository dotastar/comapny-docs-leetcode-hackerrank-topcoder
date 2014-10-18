Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true


dozerg:
��T(i, j)��ʾs[0...i)�Ƿ���ƥ��p[0...j)�����У�
T(i+1, j+1) = 
    T(i, j), if(s[i] == p[j] || p[j] == '.');
    T(i+1, j) || T(i, j+1), if('*' == p[j] && (s[i] == p[j] || p[j] == '.'));   //���Sƥ��P����ôҲƥ��P*�����Sƥ��Px*����ôSxҲƥ��Px*
    T(i+1, j-1), if('*' == p[j] && (s[i] != p[j-1]);   //���Sƥ��P����ôSҲƥ��Px*
    false
    
T(0, 0) = true
