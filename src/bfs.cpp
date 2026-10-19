#include graph.hpp

Graph::setName(int n){
    for(int i = 0; i<n; i++){
        vertexNames[i] = 'A' + i;
    }
}

Graph::setNumberOfV(int n){
    numberOfV = n;
}

int main(){

}