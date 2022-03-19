The complexity of an algorithm often becomes more, not less, significant
as computer speeds increase. For example, an aircraft designer runs one
simulation each evening between 5 p.m. and 8 a.m. When she gains
access to a faster computer, she uses this extra speed to run a larger
simulation (one that can provide more detailed results) in the same
section 1.11 Exercises 25
amount of time. Suppose her current computer can solve a problem of
size 100,000 in 15 hours. Assume that execution time is determined
solely by CPU speed; i.e., all other resources such as I/O bandwidth and
primary memory are not a constraint on performance. How large a
problem can be solved in 15 hours by a computer that is 100 times faster
if the simulation program’s time complexity is

a. ®(n)

b. ®(nlog2n)

c. ®(n2)

d. ®(n3)

---

basically we have to see if the whole expression increases by a factor of 100, what happens to n.

a. because its linear then problem size could be 100 times bigger.

b. i cant seem to figure this one out.

c. 10

d. 4.19