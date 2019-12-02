说明：

构建的是最宽路径距离索引，该算法仅支持距离查询，且输入的原始图数据是有向有权图。

具体可看graph.txt的示例格式。

g++编译器：g++7.3.0

服务器：Linux

使用方法：

进入sample目录

$ make   //用来build程序
$ bin/normalquery graph.txt    //直接在原图上运行修改的Dijkstra算法，然后输入顶点s 和 t，查询最短路径距离
$ bin/construct_index   graph.txt   graph.idx  //构建索引
$ bin/query_distance graph.idx    //最宽路径剪枝索引构建，然后输入顶点s 和 t，查询最宽路径距离	   					     	  
$ bin/pll_benchmark graph.idx    //索引算法100w次随机结点访问查询最宽路径距离，输出平均查询时间
$ bin/normal_benchmark graph.txt    //1000次Dijkstra随机结点访问查询最宽路径距离，输出平均查询时间
$ make clean   //清除bin目录的程序