#include "pwpl_widestpath.h"
int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage: construct_index GRAPH INDEX" << endl;
        exit(EXIT_FAILURE);
    }
    WidestPath pwpl;
    if (!pwpl.constructIndex(argv[1])) {
        cerr << "error: Construction failed" << endl;
        exit(EXIT_FAILURE);
    }
    pwpl.printStatistic();
    if (!pwpl.storeIndex(argv[2])) {
        cerr << "error: Store failed" << endl;
        exit(EXIT_FAILURE);
    }
}

