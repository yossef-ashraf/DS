#ifndef GRAPH_H
#define GRAPH_H

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    AdjListNode* head;
} AdjList;

typedef struct {
    int V;
    AdjList* array;
} GraphList;

typedef struct {
    int V;
    int** matrix;
} GraphMatrix;

GraphList* createGraphList(int V);
GraphMatrix* createGraphMatrix(int V);
void addEdgeList(GraphList* graph, int src, int dest);
void addEdgeMatrix(GraphMatrix* graph, int src, int dest);
void BFS(GraphList* graph, int startVertex);
void DFS(GraphList* graph, int startVertex);
void printGraphList(GraphList* graph);
void printGraphMatrix(GraphMatrix* graph);
void deleteGraphList(GraphList* graph);
void deleteGraphMatrix(GraphMatrix* graph);

#endif
