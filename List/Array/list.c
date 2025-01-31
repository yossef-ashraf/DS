#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->size = 0;
    return list;
}

void insertAtBeginning(List* list, int value) {
    if (list->size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }

    for (int i = list->size; i > 0; i--) {
        list->items[i] = list->items[i-1];
    }
    list->items[0] = value;
    list->size++;
}

void insertAtEnd(List* list, int value) {
    if (list->size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }

    list->items[list->size] = value;
    list->size++;
}

void insertAtPosition(List* list, int value, int position) {
    if (list->size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }

    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = list->size; i > position; i--) {
        list->items[i] = list->items[i-1];
    }
    list->items[position] = value;
    list->size++;
}

void deleteAtBeginning(List* list) {
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }

    for (int i = 0; i < list->size - 1; i++) {
        list->items[i] = list->items[i+1];
    }
    list->size--;
}

void deleteAtEnd(List* list) {
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }

    list->size--;
}

void deleteAtPosition(List* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = position; i < list->size - 1; i++) {
        list->items[i] = list->items[i+1];
    }
    list->size--;
}

int getElementAt(List* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return -1;
    }

    return list->items[position];
}

int findElement(List* list, int value) {
    for (int i = 0; i < list->size; i++) {
        if (list->items[i] == value) {
            return i;
        }
    }
    return -1;
}

void printList(List* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}