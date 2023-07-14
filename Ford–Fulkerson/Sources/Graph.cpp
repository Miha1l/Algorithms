#include "Graph.h"

Graph::Graph(){
    int mode;
    std::cout << "Input mode:\n1 - Terminal\n2 - File\n";
    std::cin >> mode;
    switch(mode){
        case 1:
            readFromTerminal();
            break;
        case 2:
            readFromFile();
            break;
        default:
            std::cout << "Incorrect value\n";
            break;
    }
}

void Graph::readFromTerminal(){
    int N;
    std::cin >> N;
    std::cin >> start >> end;
    int capacity;
    char vertex1, vertex2;
    for (int i = 0; i<N; i++){
        std::cin >> vertex1 >> vertex2 >> capacity;
        graph[vertex1].push_back(std::make_pair(vertex2, Edge{capacity, 0, false}));
        graph[vertex2].push_back(std::make_pair(vertex1, Edge{0, capacity, true}));
        initialCap += capacity;
    }
    return;
}

void Graph::readFromFile(){
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::ifstream fin(filename);
    int N;
    fin >> N;
    fin >> start >> end;
    int capacity;
    char vertex1, vertex2;
    for (int i = 0; i<N; i++){
        fin >> vertex1 >> vertex2 >> capacity;
        graph[vertex1].push_back(std::make_pair(vertex2, Edge{capacity, 0, false}));
        graph[vertex2].push_back(std::make_pair(vertex1, Edge{0, capacity, true}));
        initialCap += capacity;
    }
    fin.close();
    return;
}

bool Graph::isVisited(char vertex){
    for (auto& elem: visited){
        if (elem == vertex){
            return true;
        }
    }
    return false;
}

int Graph::dfs(char vertex, int flow){
    if (vertex == end){
        return flow;
    }
    visited.push_back(vertex);
    for (auto& v: graph[vertex]){
        char to = v.first;
        if (!isVisited(to) && v.second.capacity > 0){
            std::cout << vertex << " -> " << to << " ; ";
            int minRes = dfs(to, std::min(flow, v.second.capacity));
            if (minRes > 0){
                v.second.capacity -= minRes;
                v.second.flow += minRes;
                for (int i = 0; i<graph[to].size(); i++){
                    if (graph[to][i].first == vertex && ((!v.second.isReversed && graph[to][i].second.isReversed) || (v.second.isReversed && !graph[to][i].second.isReversed))){
                        graph[to][i].second.capacity += minRes;
                        graph[to][i].second.flow -= minRes;
                        break;
                    }
                }
                return minRes;
            }
        }
    }
    return 0;
}

void Graph::findMaxFlow(){
    for (auto& elem: graph){
        std::sort(graph[elem.first].begin(), graph[elem.first].end(), cmp);
    }
    int curFlow = 0;
    while(true){
        std::cout << "Edges: ";
        curFlow = dfs(start, initialCap);
        std::cout << "Flow = " << curFlow << '\n';
        if (!curFlow){
            break;
        }
        maxFlow += curFlow;
        visited.clear();
    }
}

void Graph::printRes(){
    std::cout << maxFlow << '\n';
    for (auto& i: graph){
        for (auto& j: i.second){
            if (!j.second.isReversed){
                std::cout << i.first << " " << j.first << " " <<  j.second.flow << '\n';
            }
        }
    }
}

bool cmp(const std::pair<char, Edge>& a, const std::pair<char, Edge>& b){
    return a.first < b.first;
}