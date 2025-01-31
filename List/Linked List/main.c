#include <stdio.h>
#include "list.h"
#include "list.c"

int main() {
    List* list = createList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtBeginning(list, 5);
    insertAtPosition(list, 15, 2);

    printf("List: ");
    printList(list);

    printf("Element at position 2: %d\n", getElementAt(list, 2));
    printf("Position of 20: %d\n", findElement(list, 20));

    deleteAtPosition(list, 1);
    printf("List after deletion: ");
    printList(list);

    deleteList(list);
    return 0;
}