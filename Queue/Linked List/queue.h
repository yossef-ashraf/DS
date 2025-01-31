#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int getFront(Queue* q);
int getRear(Queue* q);
int getSize(Queue* q);
void deleteQueue(Queue* q);

#endif