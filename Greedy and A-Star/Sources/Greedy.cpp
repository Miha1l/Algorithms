#include "Greedy.h"

bool PairComparator::operator()(const std::pair<char, float>& a, const std::pair<char, float>& b){
    if (a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

bool isVisited(std::vector<char>& passedVertices, char vertex){
    for (auto& elem: passedVertices){
        if (elem == vertex){
            return true;
        }
    }
    return false;
}

void findPath(Graph& graph, std::stack<std::pair<char, float>>& vertices, std::stack<std::pair<char, char>>& edges, char end){
    std::vector<char> passedVertices;
    while (!vertices.empty()){
        char current = vertices.top().first;
        vertices.pop();
        passedVertices.push_back(current);
        if (current == end){
            return;
        }
        for (auto& elem: graph[current]){
            if (!isVisited(passedVertices, elem.first)){
                vertices.push(elem);
                edges.push(std::make_pair(current, elem.first));
            }
        }
    }
}

void printRes(std::stack<std::pair<char, char>>& edges, char start, char end){
    char tmp = end;
    std::string path;
    while (!edges.empty()){
        if (edges.top().second == tmp){
            path.push_back(edges.top().second);
            tmp = edges.top().first;
        }
        edges.pop();
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    std::cout << path << '\n';
}