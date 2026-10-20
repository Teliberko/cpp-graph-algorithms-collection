#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <random>

struct Edge{
        int weight;
        int to;
    };

class Graph{
private:
    std::vector<std::string> vertexNames;
    std::vector<std::vector<Edge>> relations;
    
public:
    int getVertexIndex(const std::string& name) const;
    const std::vector<Edge>& getEdges(int index) const;
    void setVertex(const std::string& name);
    void displayGraph();
    void setEdge(int distance,
        const std::string& from, 
        const std::string& to);
};



