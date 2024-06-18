#include "graph.h"

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

bool Graph::isEmpty() {
    return numVertices == 0;
}


bool Graph::isDirected() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                return true;
            }
        }
    }
    return false;
}

void Graph::addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void Graph::printAdjMatrix() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
