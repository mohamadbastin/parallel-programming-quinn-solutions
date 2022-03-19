 Consider the data dependence graph in Figure 1.10. Identify all sources
of data parallelism. Identify all sources of functional parallelism.

---

the first row with three As can be done in parallel (Data Parallelism)

the second row B and C can be done in parallel (Functional Parallelism)

in the third row, three As can be done concurrently (Data Parallelism) and these can be done parallel with D (Functional Parallelism)