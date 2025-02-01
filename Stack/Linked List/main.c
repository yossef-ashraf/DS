#include <stdio.h>
#include "stack.h"
#include "stack.c"

int main() {
    Stack* stack = createStack();
    
    push(stack, 10);
    printf("Stack size: %d\n", getSize(stack));
    
    push(stack, 20);
    printf("Stack size: %d\n", getSize(stack));
    
    push(stack, 30);
    printf("Stack size: %d\n", getSize(stack));
    
    printf("Top element is %d\n", peek(stack));
    printf("Popped %d from stack\n", pop(stack));
    printf("Stack size after pop: %d\n", getSize(stack));
    
    deleteStack(stack);
    return 0;
}