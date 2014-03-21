4位的密码，遍历完所有0000-9999的可能性后，锁就能打开。
把所有的可能密码连接在一起成为总长度为4*10000=40000的string。这个string的某
连续四位肯定能够能解开锁。
上面的string不是唯一的。比如实际密码是2345，string的某5位是12345，1234是一个
组合，2345是另一个组合。也就是说他们共享了一些数字。导致总长度降低。
现在求一个最短的string，其中某连续4位一定是可以解开锁的密码。


---ring digits---
len=1:
digits:0
0
digits:0 1
01
...
0123456789

len=2:
digits: 0 1
0011
digits: 0 1 2
001122102
digits: 0 1 2 3

http://en.wikipedia.org/wiki/De_Bruijn_sequence
http://chessprogramming.wikispaces.com/De+Bruijn+sequence
