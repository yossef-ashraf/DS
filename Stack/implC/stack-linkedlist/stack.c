#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->next = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->next == NULL;
}

void push(Stack* stack, int item) {
    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Set data and link
    newNode->data = item;
    newNode->next = stack->next;
    
    // Update stack
    stack->next = newNode;
    stack->size++;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    // Store first node and its data
    Node* temp = stack->next;
    int popped = temp->data;
    
    // Update stack and free node
    stack->next = temp->next;
    stack->size--;
    free(temp);
    
    return popped;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->next->data;
}

int getSize(Stack* stack) {
    return stack->size;
}

void deleteStack(Stack* stack) {
    Node* current = stack->next;
    Node* next;
    
    // Free all nodes
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    // Free stack structure
    free(stack);
}