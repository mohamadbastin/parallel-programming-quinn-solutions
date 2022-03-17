## Question 1.2:

Suppose you own a hole punch capable of putting a hole in an arbitrarily
thick stack of paper. If you insert the paper into the hole punch and
activate it, you will have a piece of paper with one hole in it. If you fold
the paper in half before inserting it into the hole punch, you will have a
piece of paper with two holes in it. If you can only use the hole punch
once, how many times must you fold a piece of paper in order to put n
holes in it? Prove that your answer is correct and optimal.

--------------

My guess is that, as we can see if we do 0 folds we get 1 hole, 1 fold -> 2 holes, 2 folds, 4 holes, and so on...
so basically if we want to have n hole, we would have to fold the paper M times where M is floor(root(n)).
but this may be problematic as M grows because its not easy to fold the paper many times.