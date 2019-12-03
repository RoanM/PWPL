# PWPL
a parallel version of pruned widest path labeling algorithm

We implement the parallel version of PWPL by modifying the constructIndex function in the pwpl_widestpath 
We start n threads to construct Index where n is the number of cpu cores of this machine. 

