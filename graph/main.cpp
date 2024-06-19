#include <iostream>
#include "graph.h"

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    std::cout << "Adjacency Matrix:\n";
    g.printAdjMatrix();

    if (g.isEmpty()) {
        std::cout << "Graph is empty.\n";
    } else {
        std::cout << "Graph is not empty.\n";
    }

    if (g.isDirected()) {
        std::cout << "Graph is directed.\n";
    } else {
        std::cout << "Graph is undirected.\n";
    }

    return 0;
}
