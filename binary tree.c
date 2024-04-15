#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the tree
struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};


// Function to create a new node of the tree
struct TreeNode *createNode(int value) {
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the tree
struct TreeNode *insert(struct TreeNode *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to print the tree in order
void printInOrder(struct TreeNode *root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d -> ", root->value);
        printInOrder(root->right);
    }
}

// Function to free the memory allocated by the tree
void freeTree(struct TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode *tree = NULL;

    // Insertion of values into the tree
    tree = insert(tree, 0);
    insert(tree, 10);
    insert(tree, 45);
    insert(tree, 101);
    insert(tree, -25);
    insert(tree, 33);

    // Printing the tree
    printInOrder(tree);
    printf("NULL\n");

    // Freeing memory
    freeTree(tree);

    return 0;
}
