Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".


II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].



dozerg:
I
令T(i)表示s.substr(i, npos)是否可以Break，则有状态转换方程：
T(i) = false || T(i + W1) || T(i + W2) || ... ,  if s.substr(i, Wi) is a valid word
使用Trie，可以将valid word的检测降低到O(N)复杂度
