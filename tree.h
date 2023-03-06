#ifndef TREE_H
#define TREE_H
/**
 * Simple tree implementation that adds nodes based on the most
 * recent empty location.
**/


#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(char* data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->data, data);
    return newNode;
}

/** add a node to the tree
 * Finds the first open left most spot, so can create a skewed tree if not careful
*/
void addNode(Node* root, char* data) {
    if (root->left == NULL) {
        root->left = createNode(data);
    }
    else if (root->right == NULL) {
        root->right = createNode(data);
    }
    else {
        // adding a check here could change which direction we add based on the data info.. 
        // this will help if we wanted a proper binary search tree
        addNode(root->left, data);
    }
}


/** add a node to tree in a breadth-first manner */
void addNodeBreadthFirst(Node* root, char* data) {
    struct Node *queue[1000];
    int front = 0, rear = 0;

    // Enqueue the root node (if it exists) to start the traversal
    if (root != NULL)
        queue[rear++] = root;

    // Traverse the tree in a breadth-first manner
    while (front < rear)
    {
        // Dequeue the next node and check if it has any empty children
        struct Node *node = queue[front++];
        if (node->left == NULL)
        {
            node->left = createNode(data);
            return;
        }
        if (node->right == NULL)
        {
            node->right = createNode(data);
            return;
        }

        // Enqueue its non-empty children (if any) to continue the traversal
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}


#endif