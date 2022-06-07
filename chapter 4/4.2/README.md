Given a set of five unsigned, eight-bit integers with decimal values 13, 22,
43, 64, and 99, determine the decimal result of the following reductions:

a. add
b. multiply
c. maximum
d. minimum
e. bitwise or
f. bitwise and
g. logical or
h. logical and

Assume the meaning of the and and or operators is the same as in the
C programming language.

----

a: ( (13+22) + (43) ) + (64+99) = 241

b: ( (13X22) X (43) ) X (64X99) = 77,920,128

c: max( max( max(13,22) , 43 ) , max(64,99) ) = 99

d: min( min( min(13,22) , 43 ) , min(64,99) ) = 13

...