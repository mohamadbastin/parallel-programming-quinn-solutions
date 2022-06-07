Suppose n pieces of work are allocated in cyclic fashion to p processes.

a. Which pieces of work are assigned to process k, where
0 <= k <= p - 1?

b. Which process is responsible for piece of work j, where
0 <= j <= n — 1?

c. What are the most pieces of work assigned to any process?

d. Identify all processes having the most pieces of work.

e. What are the fewest pieces of work assigned to any process?

f. Identify all processes having the fewest pieces of work.

-----

a: k, k+p, k+2p, k+3p, .... .

b: k = j mod p

c: floor(n/p) + 1

d: process k[i] for i in range(0, n mod p) unless n mod p equals p-1 which every process has equal work.

e: floor(n/p)

f: process k[i] for i in range( (n mod p)+1, p-1) 