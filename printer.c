#include <stdio.h>

#include "tree.h"


/** inOrder DFS print of the Tree.h*/
void printTree(Node* root) {
	if (root == NULL) {
		return;
	}
	printTree(root->left);
	printf("%s\n", root->data);
	printTree(root->right);
}

/** post order DFS print of the Tree.h */
void printTreePostOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	printTreePostOrder(root->left);
	printTreePostOrder(root->right);
	printf("%s\n", root->data);
}

/** pre order DFS print of the Tree.h*/
void printTreePreOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%s\n", root->data);
	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
}

/** breadth first print of the tree.h*/
void printTreeBreadthFirst(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%s\n", root->data);
	printTreeBreadthFirst(root->left);
	printTreeBreadthFirst(root->right);
}

/** read a file, and store elements into the tree as they are read*/
Node* read_file_into_tree(char* filename, Node* root) {
	FILE* fp = fopen(filename, "r");
	char line[256];
	while (fgets(line, sizeof(line), fp)) {
		// if root is null, create a root node
		if (root == NULL) {
			root = createNode(line);
		}else {
			addNode(root, line);
		}
	}
	fclose(fp);
	return root;
}


void print_single_node(Node* node) {
	printf("%s\n", node->data);
}



	// load a file from the command line
	// create a tree	
	// print the tree in order
int main(int argc, char** argv) {
	Node* root = NULL;
	root = read_file_into_tree(argv[1], root);
	printTree(root);
	return 0;
}