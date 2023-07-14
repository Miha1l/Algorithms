#include "A-Star.h"

int main(){
    int start, end;
    std::cin >> start >> end;
    Graph graph;
    float size;
    int vertex1, vertex2;
    while(std::cin >> vertex1 >> vertex2 >> size){
        graph[vertex1].push_back(std::make_pair(vertex2, size));
    }
    pQueueVertices vertices;
    vertices.push(std::make_pair(start, 0.0));
    std::stack<std::pair<int, int>> edges;
    findMinPath(graph, vertices, edges, end);
    printRes(edges, start, end);
    return 0;
}