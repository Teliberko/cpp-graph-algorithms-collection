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
void connectedComp(const Graph& graph);