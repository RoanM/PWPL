#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <sys/time.h>

using namespace std;
#define INF 99999
typedef pair<float, int> iPair; // iPair的float保存的是边的权值

class Graph{
public:
    int V = 0,E = 0;
    vector<vector<iPair > > adj;  //保存图的邻接表
    vector<float> distTo;        //保存最宽路径距离
    vector<int > P;

    bool constructGraph(const char *filename);
    bool constructGraph(istream &ifs);
    void widsetPath(int src, int des);
    void showWidestPath(int des);
    double GetCurrentTimeMicroSec() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1e6 + tv.tv_usec;
    }



};

bool Graph::constructGraph(const char *filename) {
    ifstream ifs(filename);
    return ifs && constructGraph(ifs);
}

bool Graph::constructGraph(istream &ifs) {
    int u,v;
    float weight;
    map<int, vector<iPair > > tmp;
    for(;ifs >> u >> v >> weight;){
        V = max(u, max(V, v));
        E++;
        tmp[u].push_back(make_pair(weight, v));
    }
    V++;
    vector<vector<iPair > > adj_tmp(V);
    adj.swap(adj_tmp);
    //遍历tmp
    auto iter = tmp.begin();
    while(iter != tmp.end()){
        int k = iter->first;
        for(int i = 0; i < tmp[k].size(); i++){
            adj[k].push_back(tmp[k][i]);
//            cout << k << "->" << tmp[k][i].second << ": " << tmp[k][i].first << endl;
        }
        iter++;
    }


}

void Graph::widsetPath(int src, int des) {
    if(src < 0 || src >= V) return;
    set< iPair, greater<iPair> > maxHeap;  //权值大的优先级高,最大堆
    //先将distTo初始化为-INF
    vector<float > tmp_arr(V, -INF);
    distTo.swap(tmp_arr);

    maxHeap.insert(make_pair(INF, src));
    distTo[src] = INF;

    // 保存路径
    vector<int > tmpPath(V, -1);
    P.swap(tmpPath);
    P[src] = src;

    //运行修改的Dijkstra算法求解最宽路径距离
    while(!maxHeap.empty()){
        iPair tmp = *(maxHeap.begin()); //取出set集合中权值最大的边
        maxHeap.erase(maxHeap.begin());
        int u = tmp.second;
//        if(u == des)
//            return;   //如果终点des已经在集合中，说明src -> des 的最宽距离已经求出，直接返回
        for(auto i = adj[u].begin(); i != adj[u].end(); i++){
            int v = (*i).second;
            float weight = (*i).first;
            float dis = distTo[u] > weight ? weight : distTo[u];
            if(distTo[v] < dis){
                if(distTo[v] != -INF){
                    //说明最大堆的v需要更新其value
                    maxHeap.erase(maxHeap.find(make_pair(distTo[v], v)));
                }
                distTo[v] = dis;
                maxHeap.insert(make_pair(distTo[v], v));
                P[v] = u;
            }
        }
    }
}

void Graph::showWidestPath(int des) {
    int tmp = des;
    stack<int> s;
    while(P[tmp] != tmp){
        if(P[tmp] == -1)
            return;;
        s.push(tmp);
        tmp = P[tmp];
    }
    s.push(tmp);
    while(!s.empty()){
        cout << s.top();
        s.pop();
        if(!s.empty()) cout << "->";
    }
    cout << endl;
//    for(int i = 0; i < V; i++){
//        cout << "P[" << i << "]=" << P[i] << endl;
//    }

}

int main(int argc, char **argv){
    if (argc != 2) {
        cerr << "usage: normalWidestPathQuery GRAPH" << endl;
        exit(EXIT_FAILURE);
    }
    Graph *graph = new Graph();
    graph->constructGraph(argv[1]);
    cout << "graph loaded!" << endl;
    cout << "vertex num: " << graph->V  << ", edge num: " <<  graph->E  << endl;
    int s, t;
    while(true){
        if(cin >> s >> t){
            if(s > graph->V || t > graph->V || s < 0 || t < 0) continue;
            double query_time = -graph->GetCurrentTimeMicroSec();
            graph->widsetPath(s, t);
            cout << "widest distance: " << graph->distTo[t] << endl;
//            cout << "widest path: " ;
//            graph->showWidestPath(t);
            query_time += graph->GetCurrentTimeMicroSec();
            cout << "query_time:" << query_time*1e-3 << "ms" << endl;
        }
        else{
            cout <<"Wrong fomat!"<<endl;
            cin.clear();
            cin.ignore();
        }
    }
}
