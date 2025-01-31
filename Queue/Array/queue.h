#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue();
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int getFront(Queue* q);
int getRear(Queue* q);
int getSize(Queue* q);

#endif