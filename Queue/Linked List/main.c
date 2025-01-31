#include <stdio.h>
#include "queue.h"
#include "queue.c"

int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));
    printf("Size: %d\n", getSize(q));
    
    printf("Dequeued: %d\n", dequeue(q));
    printf("Size after dequeue: %d\n", getSize(q));
    
    deleteQueue(q);
    return 0;
}