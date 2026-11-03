#include "../include/graph.hpp"

int Graph::getVertexIndex(const std::string& name) const{
    for(int i = 0; i<vertexNames.size();i++){
        if(vertexNames[i] == name){
            return i;
        }
    }
    return -1;
}

int Graph::getSize()const {
    return this->vertexNames.size();
}

const std::vector<Edge>& Graph::getEdges(int index) const{
    return relations.at(index);
}

int Graph::getType() const{
    return this->type;
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
        int isPresent = 0;

        int indexFrom = getVertexIndex(from);
        int indexTo = getVertexIndex(to);

        if(indexFrom == -1 || indexTo == -1){
            std::cout<<"Error: not found vertex"<<std::endl;
        }
        else{
            for(int i = 0;i<relations[indexFrom].size();i++){
                if(indexTo == relations[indexFrom][i].to){
                    relations[indexFrom][i].weight = distance;
                    isPresent = 1;
                }
            }
            if(!isPresent){
                relations[indexFrom].push_back({distance, indexTo});
            }
        }
}

void Graph::removeEdge(int vertex, int to){
    for(int i =0;i<relations[vertex].size();){
        if(relations[vertex][i].to == to) {
            relations[vertex].erase(relations[vertex].begin() + i);
        }
        else{
            ++i;
        }
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
    std::vector<Edge> edges;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,100);
    std::string temp;
    int start;
    int distance;
    std::cout<<"Input size of your graph"<<std::endl;
    std::getline(std::cin,temp);
    int size = stoi(temp);

    for(int i = 0; i< size; i++){
        std::string s(1,'A' + i);
        setVertex(s);
    }



    for(int i = 0; i<size;i++){
        if(this->type == 2){
            start = i + 1;
        }
        else{
            start = 0;
        }
        for(int j = start; j<size;j++){

            if(i == j) continue;

            if(dist(gen) > 90){
                std::string from(1,'A' + i);
                std::string to(1,'A' + j);
                distance = dist(gen);
                setEdge(distance,from,to);
                if(this->type == 2){
                    setEdge(distance,to,from);
                }
            }
        }
    }
   
}

Graph::Graph(int type) : type(type) {}

void Graph::convertType(){
    int size = this->getSize();
    std::vector<std::vector<Edge>> copy = relations;
    switch(this->type){
        case 1:  //directed -> undirected
            for(int i =0; i<size;i++){
                for(int j = 0; j< copy[i].size();j++){
                    std::string from(1,'A' + copy[i][j].to);
                    std::string to(1,'A' + i);
                    setEdge(copy[i][j].weight, from, to);
                }
            }
            this->type = 2;
        break;
        case 2:
            
        break;
        default:
        break;
    }
}

void Graph::transpose(){
    int size = this->getSize();
    std::vector<std::vector<Edge>> copy(size);

    for(int i =0;i<size;i++){
        for(const Edge& edge : relations[i]){
            copy[edge.to].push_back({edge.weight,i});
        }
    }
    relations.swap(copy);
}