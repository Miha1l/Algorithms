#include "A-Star.h"

bool PairComparator::operator()(const std::pair<int, float>& a, const std::pair<int, float>& b){
    if (a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

void printRes(std::stack<std::pair<int, int>>& edges, int start, int end){
    int tmp = end;
    std::vector<int> path;
    while (!edges.empty()){
        if (edges.top().second == tmp){
            path.push_back(edges.top().second);
            tmp = edges.top().first;
        }
        edges.pop();
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    for (auto& elem: path){
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

float heuristic(int sym1, int sym2){
    return std::abs(sym1 - sym2);
}

void findMinPath(Graph& graph, pQueueVertices& vertices, std::stack<std::pair<int, int>>& edges, int end){
    std::map<int, float> pathCost;
    pathCost[vertices.top().first] = vertices.top().second;
    while (!vertices.empty()){
        int current = vertices.top().first;
        vertices.pop();
        if (current == end){
            return;
        }
        for (auto& elem: graph[current]){
            float new_cost = pathCost[current] + elem.second;
            if (!pathCost.count(elem.first) || new_cost < pathCost[elem.first]){
                pathCost[elem.first] = new_cost;
                float priority = new_cost + heuristic(elem.first, end);
                vertices.push(std::make_pair(elem.first, priority));
                edges.push(std::make_pair(current, elem.first));
            }
        }
    }
}