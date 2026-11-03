#include "../include/algorithms.hpp"

void dfs(const Graph& graph){
    std::string temp;
    std::stack<int> s;
    std::vector<int> dfsResult;
    int size;
    int current;

    std::cout<<"===DFS==="<<std::endl;
    std::cout<<"Select your vertex"<<std::endl;

    std::getline(std::cin,temp);
    int index = std::stoi(temp);
    size = graph.getSize();
    
    std::vector<bool> visited(size,false);

    s.push(index);
    visited[index] = true;

    while(!s.empty()){
        current = s.top();
        s.pop();
        dfsResult.push_back(current);
        std::vector<Edge> neighboors = graph.getEdges(current);
        for(int i = 0; i<neighboors.size();i++){
            int to = neighboors[i].to;
            if(visited[to] != true){
                visited[to] = true;
                s.push(to);
            }
        }
    }
    std::cout<<"DFS result: ";
    for(int i =0;i<dfsResult.size();i++){
        char vertex = 'A' + dfsResult[i];
        std::cout<<vertex<<" ";
    }
    std::cout<<std::endl;
}



std::vector<int> dfs(const Graph& graph, int start){
    std::stack<int> s;
    std::vector<int> dfsResult;
    int size;
    int current;

    size = graph.getSize();
    
    std::vector<bool> visited(size,false);

    s.push(start);
    visited[start] = true;

    while(!s.empty()){
        current = s.top();
        s.pop();
        dfsResult.push_back(current);
        std::vector<Edge> neighboors = graph.getEdges(current);
        for(int i = 0; i<neighboors.size();i++){
            int to = neighboors[i].to;
            if(visited[to] != true){
                visited[to] = true;
                s.push(to);
            }
        }
    }
    return dfsResult;
}

void recursiveDfs(const Graph& graph, int start, std::vector<bool>& visited, std::vector<int>& result,int mode){
    visited[start] = true;
    if(mode == 2) result.push_back(start);
    const std::vector<Edge>& neighboors = graph.getEdges(start);
    for(int i = 0;i<neighboors.size();i++){
        int to = neighboors[i].to;
        if(visited[to] != true){
            recursiveDfs(graph,to,visited,result,mode);
        }
    }
    if(mode == 1) result.push_back(start);
    
}