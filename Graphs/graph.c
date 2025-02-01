#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Queue for BFS
#define MAX_QUEUE_SIZE 1000
typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(Queue* queue) {
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// Graph List Implementation
GraphList* createGraphList(int V) {
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdgeList(GraphList* graph, int src, int dest) {
    // Add edge from src to dest
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    // Add edge from dest to src (undirected graph)
    newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void BFS(GraphList* graph, int startVertex) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    Queue* queue = createQueue();
    
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    
    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        
        AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    
    free(visited);
    free(queue);
}

void DFSUtil(GraphList* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    AdjListNode* temp = graph->array[vertex].head;
    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(GraphList* graph, int startVertex) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Graph Matrix Implementation
GraphMatrix* createGraphMatrix(int V) {
    GraphMatrix* graph = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    graph->V = V;
    
    graph->matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}

void addEdgeMatrix(GraphMatrix* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;  // For undirected graph
}

void printGraphList(GraphList* graph) {
    for (int v = 0; v < graph->V; v++) {
        AdjListNode* temp = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printGraphMatrix(GraphMatrix* graph) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void deleteGraphList(GraphList* graph) {
    for (int i = 0; i < graph->V; i++) {
        AdjListNode* current = graph->array[i].head;
        while (current) {
            AdjListNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);
}

void deleteGraphMatrix(GraphMatrix* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}