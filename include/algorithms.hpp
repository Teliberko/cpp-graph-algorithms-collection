#pragma once
#include "graph.hpp"
#include <queue>
#include <stack>

//BFS
void bfs(const Graph& graph);
std::vector<int> bfs(const Graph& graph, int start);

//DFS
void dfs(const Graph& graph);
std::vector<int> dfs(const Graph& graph, int start);
void recursiveDfs(const Graph& graph, int start, 
    std::vector<bool>& visited, std::vector<int>& result, int mode);


//CONNECTED COMPONENTS
void connectedComponents(const Graph& graph); //main fuction for each types
std::vector<std::vector<int>> undirectedConCom(const Graph& graph); //also WCC for directed graph
std::vector<std::vector<int>> SCC(const Graph& graph); //for directed