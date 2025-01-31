#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertAtBeginning(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void insertAtEnd(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void insertAtPosition(List* list, int value, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(list, value);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    Node* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}

void deleteAtBeginning(List* list) {
    if (list->head == NULL) return;

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void deleteAtEnd(List* list) {
    if (list->head == NULL) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size = 0;
        return;
    }

    Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    list->size--;
}

void deleteAtPosition(List* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginning(list);
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
}

int getElementAt(List* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return -1;
    }

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

int findElement(List* list, int value) {
    Node* current = list->head;
    int position = 0;

    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteList(List* list) {
    while (list->head != NULL) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}