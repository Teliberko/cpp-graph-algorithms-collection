#include "../include/algorithms.hpp"


void connectedComponents(const Graph& graph){
    std::vector<std::vector<int>> wcc;
    std::vector<std::vector<int>> scc;
    int type;

    type = graph.getType();

    switch(type)
    {
        case 1:
        {
            Graph copy = graph;
            copy.convertType();
            wcc = undirectedConCom(copy); 
            scc = SCC(graph);
            std::cout<<"Strongly connected components: ";
            for(int i = 0; i<scc.size();i++){
                std::cout<<"{";
                for(int j =0; j<scc[i].size();j++){
                std::cout<<scc[i][j]<<" ";
            }
        std::cout<<"}";
    }
    std::cout<<std::endl;
            break;
        }
        case 2:
        {
            undirectedConCom(graph);
            break;
        }
        default:
        {
            break;
        }
    }

}




std::vector<std::vector<int>> undirectedConCom(const Graph& graph){
    int size = graph.getSize();
    int step = 0;
    std::vector<std::vector<int>> resultComponents;
    std::vector<bool> visited(size,false);
    for(int i =0;i<size;i++){
        if(visited[i] == false){
            resultComponents.push_back(bfs(graph,i));
            for(int j = 0; j<resultComponents[step].size();j++){
                visited[resultComponents[step][j]] = true;
            }
            step++;
        }
    }
    std::cout<<"Result of algorithm: ";
    for(int i = 0; i<resultComponents.size();i++){
        std::cout<<"{";
        for(int j =0; j<resultComponents[i].size();j++){
            std::cout<<resultComponents[i][j]<<" ";
        }
        std::cout<<"}";
    }
    std::cout<<std::endl;
    return resultComponents;
}

std::vector<std::vector<int>> SCC(const Graph& graph){
    int size = graph.getSize();
    std::vector<std::vector<int>> resultComponents;
    std::vector<bool> visited(size,false);
    std::vector<int> order;

    for(int i = 0; i<size;i++){
        if(!visited[i]){
            recursiveDfs(graph,i,visited,order,1);
        }
    }
    
    for(int i =0;i<visited.size();i++) visited[i] = false;
    Graph copy = graph;
    copy.transpose();

    for(int i = size -1; i >= 0; i--){
        int vertex = order[i];
        if(!visited[vertex]){
            std::vector<int> component;
            recursiveDfs(copy,vertex,visited,component,2);
            resultComponents.push_back(component);
        }
    }
    return resultComponents;
}

