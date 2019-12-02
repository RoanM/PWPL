/**
 * 对索引算法构建出的索引进行一百万次的随机查询，获取平均查询时间
 */
#include "pllwidestpath.h"
const int kNumQueries = 1000000;
double GetCurrentTimeSec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main(int argc, char **argv){
    if (argc != 2) {
        cerr << "usage: load_index  filename" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Load file, waiting ... " << endl;
    PllWidestPath pll;
    if(!pll.loadIndex(argv[1])){
        cerr << "error: Load failed" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Load sucess ! " << endl;
    vector<int> vs(kNumQueries), ws(kNumQueries);
    for (int i = 0; i < kNumQueries; ++i) {
        vs[i] = rand() % pll.getVerticeNum();
        ws[i] = rand() % pll.getVerticeNum();
    }

    double time_start = GetCurrentTimeSec();
    for (int i = 0; i < kNumQueries; ++i) {
        pll.queryDistance(vs[i], ws[i]);
    }
    double elapsed_time = GetCurrentTimeSec() - time_start;
    cout << "average query time: "
         << elapsed_time / kNumQueries * 1E6
         << " microseconds" << endl;

    exit(EXIT_SUCCESS);
}