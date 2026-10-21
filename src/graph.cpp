#include "../include/graph.hpp"

int Graph::getVertexIndex(const std::string& name) const{
    for(int i = 0; i<vertexNames.size();i++){
        if(vertexNames[i] == name){
            return i;
        }
    }
    return -1;
}

const int Graph::getSize()const {
    return this->vertexNames.size();
}

const std::vector<Edge>& Graph::getEdges(int index) const{
    return relations.at(index);
}


void Graph::setVertex(const std::string& name){
    int indexName = getVertexIndex(name);
    if(indexName != -1) return;
    vertexNames.push_back(name);
    relations.push_back(std::vector<Edge>());
}

void Graph::setEdge(int distance,
    const std::string& from, 
    const std::string& to){

        int indexFrom = getVertexIndex(from);
        int indexTo = getVertexIndex(to);

        if(indexFrom == -1 || indexTo == -1){
            std::cout<<"Error: not found vertex"<<std::endl;
        }
        else{
            relations[indexFrom].push_back({distance, indexTo});
        }
}

void Graph::displayGraph(){
    std::cout<<"Graph = ["<<std::endl;

    for(int i = 0;i<vertexNames.size();i++){
        std::vector<Edge> temp = getEdges(i);
        std::cout<<i<<". "<<vertexNames[i]<< " = ";
        for(int j =0;j<temp.size();j++){
            std::cout<<" {"<<vertexNames[temp[j].to]
            <<","<<temp[j].weight << "} ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"]"<<std::endl;
}

void Graph::initGraph(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,100);
    std::string temp;
    std::cout<<"Input size of your graph"<<std::endl;
    std::getline(std::cin,temp);
    int size = stoi(temp);

    std::uniform_int_distribution<int> vert(0,size-1);
    for(int i = 0; i< size; i++){
        std::string s(1,'A' + i);
        setVertex(s);
    }

    
    for(int i = 0; i<size;i++){
        for(int j = 0; j<size;j++){

            if(i == j) continue;

            if(dist(gen) > 45){
                std::string from(1,'A' + i);
                std::string to(1,'A' + j);
                setEdge(dist(gen),from,to);
            
            }
        }
    }
}