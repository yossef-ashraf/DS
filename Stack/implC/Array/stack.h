#ifndef STACK_H
#define STACK_H

typedef struct {
    int* array;
    int top;
    int capacity;
} Stack;

// Function declarations
Stack* createStack(int capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void deleteStack(Stack* stack);

#endif

