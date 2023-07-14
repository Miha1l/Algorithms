#include "Graph.h"

int main(){
    Graph* graph = new Graph();
    graph->findMaxFlow();
    graph->printRes();
    delete graph;
    return 0;
}