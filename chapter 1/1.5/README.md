Given a task that can be divided into m subtasks, each requiring one unit
of time, how much time is needed for an m-stage pipeline to process n
tasks?

----

if we look at the total time as the time taken for the first task + time taken for n-1 tasks, we
would have this: the first task obviously takes m to finish since there is m stages with 1 unit of time per each.
then after the first task, there is a new finished task each unit of time. because it is pipelined. so the
first task takes m and all the other n-1 ones take 1.
that makes T = m + n-1