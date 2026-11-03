#include "../include/algorithms.hpp"

void undirectedConCom(const Graph& graph);

void connectedComponents(const Graph& graph){
    
    int type;

    type = graph.getType();

    switch(type)
    {
        case 1:
        {
            Graph copy = graph;
            copy.convertType();
            undirectedConCom(copy); //WCC
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




void undirectedConCom(const Graph& graph){
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
}

void SCC(){

}

