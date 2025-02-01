#include <stdio.h>
#include "graph.h"
#include "graph.c"

int main() {
    int V = 5;
    
    // Test Adjacency List
    GraphList* graphList = createGraphList(V);
    addEdgeList(graphList, 0, 1);
    addEdgeList(graphList, 0, 4);
    addEdgeList(graphList, 1, 2);
    addEdgeList(graphList, 1, 3);
    addEdgeList(graphList, 1, 4);
    addEdgeList(graphList, 2, 3);
    addEdgeList(graphList, 3, 4);
    
    printf("Adjacency List Representation:\n");
    printGraphList(graphList);
    
    printf("\nBFS starting from vertex 0: ");
    BFS(graphList, 0);
    
    printf("\nDFS starting from vertex 0: ");
    DFS(graphList, 0);
    
    // Test Adjacency Matrix
    GraphMatrix* graphMatrix = createGraphMatrix(V);
    addEdgeMatrix(graphMatrix, 0, 1);
    addEdgeMatrix(graphMatrix, 0, 4);
    addEdgeMatrix(graphMatrix, 1, 2);
    addEdgeMatrix(graphMatrix, 1, 3);
    addEdgeMatrix(graphMatrix, 1, 4);
    addEdgeMatrix(graphMatrix, 2, 3);
    addEdgeMatrix(graphMatrix, 3, 4);
    
    printGraphMatrix(graphMatrix);
    
    deleteGraphList(graphList);
    deleteGraphMatrix(graphMatrix);
    return 0;
}