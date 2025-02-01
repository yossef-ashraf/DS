#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Tree* tree, int value) {
    if (tree->root == NULL) {
        tree->root = createNode(value);
        return;
    }

    Node* current = tree->root;
    while (1) {
        if (value < current->data) {
            if (current->left == NULL) {
                current->left = createNode(value);
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = createNode(value);
                return;
            }
            current = current->right;
        }
    }
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
        
    if (value < root->data)
        return search(root->left, value);
    
    return search(root->right, value);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int getHeight(Node* root) {
    if (root == NULL) return -1;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
