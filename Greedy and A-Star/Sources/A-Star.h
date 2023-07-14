#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>

class PairComparator{
public:
    bool operator()(const std::pair<int, float>& a, const std::pair<int, float>& b);
};

typedef std::map<int, std::vector<std::pair<int, float>>> Graph;
typedef std::priority_queue<std::pair<int, float>, std::vector<std::pair<int, float>>, PairComparator> pQueueVertices;

float heuristic(int sym1, int sym2);
void findMinPath(Graph& graph, pQueueVertices& vertices, std::stack<std::pair<int, int>>& edges, int end);
void printRes(std::stack<std::pair<int, int>>& edges, int start, int end);

#endif