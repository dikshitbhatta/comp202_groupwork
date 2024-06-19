#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    bool isEmpty() {
        return numVertices == 0;
    }

    bool isDirected() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != adjMatrix[j][i]) {
                    return true;
                }
            }
        }
        return false;
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printAdjMatrix() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};
