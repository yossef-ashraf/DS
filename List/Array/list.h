#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int size;
} List;

List* createList();
void insertAtBeginning(List* list, int value);
void insertAtEnd(List* list, int value);
void insertAtPosition(List* list, int value, int position);
void deleteAtBeginning(List* list);
void deleteAtEnd(List* list);
void deleteAtPosition(List* list, int position);
int getElementAt(List* list, int position);
int findElement(List* list, int value);
void printList(List* list);

#endif