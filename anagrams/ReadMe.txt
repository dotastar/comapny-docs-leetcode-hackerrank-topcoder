Input - List<String> ["star", "rats", "ice", "cie", "arts"] 
print all anagrams in buckets: 
["star", "rats", "arts"] 
["ice", "cie"] 

The signature of unimplemented method is given:

public void anagramBuckets(List<String> input);

I was given this question during phone interview.

anonymous:
Sort each string and put it in a trie. 
Sorting a string can be done in O(n) time and constant space - keep track of count of each characters and print in sorted order. 
Trie insertion = O(n) 
Total complexity - O(n*m) 
m = number of strings in array 
n = size of strings in array.
