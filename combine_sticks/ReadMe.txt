Many sticks with length, every time combine two, the cost is the sum of two sticks' length.
Finally, it will become a stick, what's the minimum cost?

DoZerg answer:
Suppose there are n(>0) sticks of length {L1, L2, ... , Ln}, where L1<=L2<=...<=Ln, I think the answer is: 
cost = 
(1) 0, if n=1; 
(2) L1+L2, if n=2; 
(3) L1 + 2 * (L2 + L3 +...+Ln-1) + Ln, if n>2; 
Prove: 
Each time we combine 2 sticks to 1, there remains n-1 sticks, until there is only 1 stick. So we need to combine n-1 times. To minimize each combine cost, we should choose the shortest 2 sticks all the time. 
So, the 1st combine cost is L1+L2, left n-1 sticks of lenght {L2, L3, ... , Ln}; 
the 2nd combine cost is L2+L3, left {L3, L4, ..., Ln}; 
the 3rd combine cost is L3+L4, left {L4, L5, ..., Ln}; 
... 
the total cost is L1+2*(L2 + L3 +...+Ln-1)+Ln.
