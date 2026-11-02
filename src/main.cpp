#include "../include/graph.hpp"
#include "../include/algorithms.hpp"

int main(){
    int key = 1;
    int choice;
    Graph graph(1); 
    std::string temp;

    graph.initGraph();
    graph.displayGraph();

    while(key){

        std::cout<<"===Menu==="<<std::endl;
        std::cout<<"1. BFS"<<std::endl;
        std::cout<<"2. DFS"<<std::endl;
        std::cout<<"3. Connected components"<<std::endl;
        std::cout<<"4. Convert type of graph"<<std::endl;
        std::cout<<"5. Show Graph"<<std::endl;
        std::cout<<"0. Exit"<<std::endl;

        std::getline(std::cin,temp);
        choice = stoi(temp);

        switch(choice){
            case(1):
                bfs(graph);
            break;
            case(2):
                dfs(graph);
            break;
            case(3):
                connectedComp(graph);
            break;
            case(4):
                graph.convertType();
            break;
            case(5):
                graph.displayGraph();
            break;
            case(0):
                key = 0;
            break;
            default:
            break;
        }

    }
    return 0;
}