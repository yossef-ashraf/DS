#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} Tree;

Tree* createTree();
Node* createNode(int value);
void insert(Tree* tree, int value);
Node* search(Node* root, int value);
void inorderTraversal(Node* root);
void preorderTraversal(Node* root);
void postorderTraversal(Node* root);
int getHeight(Node* root);
void deleteTree(Node* root);

#endif