#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element is %d\n", peek(stack));
    printf("Popped %d from stack\n", pop(stack));
    printf("Top element is %d\n", peek(stack));

    deleteStack(stack);
    return 0;
}