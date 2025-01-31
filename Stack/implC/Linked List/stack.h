#ifndef STACK_H
#define STACK_H

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure with size tracking
typedef struct {
    Node* next;
    int size;
} Stack;

// Function declarations
Stack* createStack();
int isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void deleteStack(Stack* stack);
int getSize(Stack* stack);

#endif