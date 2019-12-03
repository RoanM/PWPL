# PWPL
a parallel version of pruned widest path labeling algorithm

We implement the parallel version of PWPL by modifying the constructIndex function in the pwpl_widestpath. In the original PWPL we just start one thread to construct index. In the parallel PWPL, we start n threads to construct Index where n is the number of cpu cores of this machine. At the same time, we assign different threads with the vertices that need to be performed according to the precalculated execution order. For an example, if there are two threads and eight vertices in all. The precalculated execution order is v1, v2, v3, v4, v5, v6, v7, v8. We assign v1, v3, v5, v6 to first thread and v2, v4, v6, v8 to second thread.


