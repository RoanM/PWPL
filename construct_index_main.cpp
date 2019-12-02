#include "pllwidestpath.h"
int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage: construct_index GRAPH INDEX" << endl;
        exit(EXIT_FAILURE);
    }
    PllWidestPath pll;
    if (!pll.constructIndex(argv[1])) {
        cerr << "error: Construction failed" << endl;
        exit(EXIT_FAILURE);
    }
    pll.printStatistic();
    if (!pll.storeIndex(argv[2])) {
        cerr << "error: Store failed" << endl;
        exit(EXIT_FAILURE);
    }
}

