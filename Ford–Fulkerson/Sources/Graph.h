#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <fstream>

struct Edge{
    int capacity;
    int flow;
    bool isReversed;
};

class Graph{
private:
    std::map<char, std::vector<std::pair<char, Edge>>> graph;
    std::vector<char> visited;
    char start, end;
    int initialCap, maxFlow = 0;
public:
    Graph();
    bool isVisited(char vertex);
    int dfs(char vertex, int flow);
    void findMaxFlow();
    void printRes();
    void readFromTerminal();
    void readFromFile();
};

bool cmp(const std::pair<char, Edge>& a, const std::pair<char, Edge>& b);

#endif