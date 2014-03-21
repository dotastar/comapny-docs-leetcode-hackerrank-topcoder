Write a function for retrieving the total number of substring palindromes. 
For example the input is 'abba' then the possible palindromes= a, b, b, a, bb, abba 
So the result is 6. 

Updated at 11/11/2013: 
After the interview I got know that the O(n^3) solution is not 
enough to go to the next round. It would have been better to 
know before starting implementing the solution unnecessarily ...

ref:
http://stackoverflow.com/questions/7043778/longest-palindrome-in-a-string-using-suffix-tree
http://blog.sina.com.cn/s/blog_70811e1a01014esn.html

pftest:
run kkr_pftest.time:
test.test: 295.724 us per call (3,381 calls per second)
run n1_pftest.time:
test.test: 86.2115 us per call (11,599 calls per second)
run n2_pftest.time:
test.test: 4.14006 ms per call (241 calls per second)
run n3_pftest.time:
test.test: 1.10221 s per call (0.907265 calls per second)
