#include <iostream>
#include <vector>
#include <queue>

class Graph(){
    private:
        struct Edge(){
            int weight;
            int to;
        };
        int numberOfV;
        std::vector<char> vertexNames[numberOfV];
        std::vector<vector<Edge>> relations;
    
        void setName(int n);
        void setNumberOfV(int n);

}



