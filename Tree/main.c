#include <stdio.h>
#include "tree.h"
#include "tree.c"

int main() {
    Tree* tree = createTree();
    
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    printf("Inorder traversal: ");
    inorderTraversal(tree->root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(tree->root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(tree->root);
    printf("\n");

    printf("Tree height: %d\n", getHeight(tree->root));

    Node* found = search(tree->root, 40);
    printf("Search for 40: %s\n", found ? "Found" : "Not found");

    deleteTree(tree->root);
    free(tree);
    return 0;
}