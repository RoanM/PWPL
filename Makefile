CXX = g++
CXXFLAGS = -g -Wall -Wextra -Og -lpthread

all: bin bin/normalquery bin/construct_index bin/query_distance bin/normal_benchmark bin/pll_benchmark

bin:
	mkdir -p bin

bin/normalquery: normalquery.cpp
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^

bin/construct_index: construct_index_main.cpp pllwidestpath.h
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^
	
bin/query_distance: query_distance_main.cpp pllwidestpath.h
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^
	
bin/normal_benchmark: normal_benchmark.cpp
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^
	
bin/pll_benchmark: pll_benchmark.cpp pllwidestpath.h
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^

clean:
	rm -rf bin
