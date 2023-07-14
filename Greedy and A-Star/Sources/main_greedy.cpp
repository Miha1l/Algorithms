#include "Greedy.h"

int main(){
    char start, end;
    std::cin >> start >> end;
    Graph graph;
    float size;
    char vertex1, vertex2;
    while(std::cin >> vertex1 >> vertex2 >> size){
        graph[vertex1].push_back(std::make_pair(vertex2, size));
    }
    std::stack<std::pair<char, float>> vertices;
    vertices.push(std::make_pair(start, 0.0));
    std::stack<std::pair<char, char>> edges;
    PairComparator cmp;
    for (auto& elem: graph){
        std::sort(graph[elem.first].begin(), graph[elem.first].end(), cmp);
    }
    findPath(graph, vertices, edges, end);
    printRes(edges, start, end);
    return 0;
}