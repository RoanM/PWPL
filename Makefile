CXX = g++
CXXFLAGS = -g -Wall -Wextra -Og -lpthread

all: bin bin/normalquery bin/construct_index bin/query_width bin/normal_benchmark bin/pwpl_benchmark

bin:
	mkdir -p bin

bin/normalquery: normalquery.cpp
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^

bin/construct_index: construct_index_main.cpp pwpl_widestpath.h
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^
	
bin/query_width: query_width_main.cpp pwpl_widestpath.h
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^
	
bin/normal_benchmark: normal_benchmark.cpp
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^
	
bin/pwpl_benchmark: pwpl_benchmark.cpp pwpl_widestpath.h
	$(CXX) $(CXXFLAGS) -Isrc -o $@ $^

clean:
	rm -rf bin
