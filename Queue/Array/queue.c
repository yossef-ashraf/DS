#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    
    if (isEmpty(q)) {
        q->front = -1;
        q->rear = -1;
    }
    
    return item;
}

int getFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

int getRear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->rear];
}

int getSize(Queue* q) {
    return q->size;
}
