#include <cstdlib>
#include "pwpl_widestpath.h"
double GetCurrentTimeMicroSec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1e6 + tv.tv_usec;
}

int main(int argc, char **argv){
    if (argc != 2) {
        cerr << "usage: load_index  INDEX" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Load file, waiting ... " << endl;
    WidestPath pll;
    if(!pll.loadIndex(argv[1])){
        cerr << "error: Load failed" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Load sucess ! " << endl;


    uint32_t u,w;
    while(true){
        if(cin >> u >> w){
            double query_time = 0;
            query_time = -GetCurrentTimeMicroSec();
            cout << "distance of widest path: " << pll.queryDistance(u, w) << endl;
            query_time += GetCurrentTimeMicroSec();
            cout << "query_time:" << query_time << "us" << endl;
        }
        else{
            cout <<"Wrong fomat!"<<endl;
            cin.clear();
            cin.ignore();
        }
    }
}