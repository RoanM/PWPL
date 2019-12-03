# PWPL
PWPL is a pruned widest path labeling algorithm, 
#introduction
The widest path query problem is also called the maximum
capacity route problem It is one of the most fundamental
operations in many applications. In weighted graphs,
there can be multiple paths between two designated vertices.
Each path commonly consists of a sequence of edges. The
edge with the minimum weight value can be seen as the
bottleneck through the path, and the minimum value is called
the width of the path. The path which has the maximum width
value among all the paths is the widest path between the
two designated vertices. Finding the widest path is desired by various applications.

We implement the parallel version of PWPL by modifying the constructIndex function and PMDijkstra function in the "pwpl_widestpath.h". In the original PWPL we just start one thread to construct index. In the parallel PWPL, we start n threads to construct Index where n is the number of cpu cores of this machine. At the same time, we assign different threads with the vertices that need to be performed according to the precalculated execution order. For an example, if there are two threads and eight vertices in all. The precalculated execution order is v1, v2, v3, v4, v5, v6, v7, v8. We assign v1, v3, v5, v7 to first thread and v2, v4, v6, v8 to second thread.


