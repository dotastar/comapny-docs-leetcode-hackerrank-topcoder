 给一个字典，里面是若干单词。再给一堆字符，判断所有字符能否组成字典里的单词，没有剩余。
 每个字符只能用一次，可能有重复字符。
 组成的单词数目不限。
 例如，
 字典为： hello world is my first program
 
 字符集为：i i i f r s s s t
 返回：true（因为可以组成 is is first）

 字符集为：e i i f r s s t
 返回：false（因为剩余字符e）
