#ifndef TREE_H
#define TREE_H
/**
 * Simple tree implementation that adds nodes based on the most
 * recent empty location.
**/


#include <stdlib.h>

typedef struct Node {
    char* data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(char* data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/** add a node finding the first open spot*/
void addNode(Node* root, char* data)
{
    if (root->left == NULL) {
        root->left = createNode(data);
    } else if (root->right == NULL) {
        root->right = createNode(data);
    } else {
        addNode(root->left, data);
    }
}

#endif