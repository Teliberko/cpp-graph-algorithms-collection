#include "../include/graph.hpp"
#include "../include/algorithms.hpp"

int main(){

    Graph graph; 
    graph.initGraph();
    graph.displayGraph();

    bfs(graph);

    return 0;
}