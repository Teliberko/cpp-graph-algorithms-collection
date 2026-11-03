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

//CONNECTED COMPONENTS
void connectedComponents(const Graph& graph); //main fuction for each types
void undirectedConCom(const Graph& graph); //also WCC for directed graph
void WCC(); //for directed