#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

typedef std::map<char, std::vector<std::pair<char, float>>> Graph;

class PairComparator{
public:
    bool operator()(const std::pair<char, float>& a, const std::pair<char, float>& b);
};

bool isVisited(std::vector<char>& passedVertices, char vertex);
void findPath(Graph& graph, std::stack<std::pair<char, float>>& vertices, std::stack<std::pair<char, char>>& edges, char end);
void printRes(std::stack<std::pair<char, char>>& edges, char start, char end);

#endif