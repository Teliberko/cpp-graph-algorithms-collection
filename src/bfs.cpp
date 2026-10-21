#include "../include/algorithms.hpp"


void bfs(const Graph& graph){
    std::queue<int> q;
    std::vector<int> bfsResult;
    std::string temp;
    int size = graph.getSize();
    std::cout<<"===BFS==="<<std::endl;
    std::cout<<"Select your vertex"<<std::endl;
    std::getline(std::cin,temp);
    int index = stoi(temp);
 
    std::vector<bool> visited(size,false);
    visited[index] = true;
    q.push(index);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        bfsResult.push_back(current);
        std::vector<Edge> neighbors = graph.getEdges(current);
        for(int i = 0; i<neighbors.size();i++){
            int to = neighbors[i].to;
            if(visited[to] != true){
                visited[to] = true;
                q.push(to);
            }
        }
    }
    std::cout<<"BFS result: ";
    for(int i = 0; i<bfsResult.size();i++){
        std::cout<< bfsResult[i]<< " ";
    }
    std::cout<<std::endl;
}