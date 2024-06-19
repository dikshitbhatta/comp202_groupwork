
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int numVertices);

    bool isEmpty();
    bool isDirected();
    void addEdge(int u, int v);
    void printAdjMatrix();
};


