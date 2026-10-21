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
        std::cout<<dfsResult[i]<<" ";
    }
    std::cout<<std::endl;
}