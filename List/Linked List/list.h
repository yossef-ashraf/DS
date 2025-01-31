#ifndef LIST_LINKEDLIST_H
#define LIST_LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
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
void deleteList(List* list);

#endif
