#include <stdio.h>

#include "tree.h"

void print_single_node(Node *node)
{
	printf("%s\n", node->data);
}

/** inOrder DFS print of the Tree.h*/
void printTree(Node* root) {
	if (root == NULL) {
		return;
	}
	printTree(root->left);
	print_single_node(root);
	printTree(root->right);
}

/** post order DFS print of the Tree.h */
void printTreePostOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	printTreePostOrder(root->left);
	printTreePostOrder(root->right);
	print_single_node(root);
}

/** pre order DFS print of the Tree.h*/
void printTreePreOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	print_single_node(root);
	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
}

/** iterative breadth-first print of the tree.h*/
void printTreeBreadthFirst(Node* root) {
	if (root == NULL) {
		return;
	}
	struct Node *queue[1000];
	int front = 0, rear = 0;
	queue[rear] = root;
	rear++;
	while (front < rear)
	{
		struct Node *current = queue[front];
		front++;
		print_single_node(current);
		if (current->left != NULL)
		{
			queue[rear] = current->left;
			rear++;
		}
		if (current->right != NULL)
		{
			queue[rear] = current->right;
			rear++;
		}
	}
}



/** read a file, and store elements into the tree as they are read*/
Node* read_file_into_tree(char* filename, Node* root) {
	FILE* fp = fopen(filename, "r");
	char line[256];
	while (fgets(line, sizeof(line), fp)) {
		int len = strlen(line);
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0'; // Replace the newline with null character
		}

		// if root is null, create a root node
		if (root == NULL) {
			root = createNode(line);
		}else {
			addNodeBreadthFirst(root, line);
		}
	}
	fclose(fp);
	return root;
}




	// load a file from the command line
	// create a tree	
	// print the tree in order
	

int main(int argc, char** argv) {
	Node* root = NULL;
	root = read_file_into_tree(argv[1], root);
	char* print_type = argv[2];

	// based on print type, print the tree
	if (strcmp(print_type, "inorder") == 0) {
		printTree(root);
	}
	else if (strcmp(print_type, "postorder") == 0) {
		printTreePostOrder(root);
	}
	else if (strcmp(print_type, "preorder") == 0) {
		printTreePreOrder(root);
	}
	else if (strcmp(print_type, "breadthfirst") == 0) {
		printTreeBreadthFirst(root);
	}
	else {
		printf("Invalid print type");
	}

	return 0;
}