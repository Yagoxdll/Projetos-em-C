#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the binary tree
struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node of the binary tree
struct TreeNode *createNode(int value) {
    // Allocate memory for the new node
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    // Check if memory allocation was successful
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    // Initialize the value and left/right pointers of the new node
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
struct TreeNode *insert(struct TreeNode *root, int value) {
    // If the root is NULL, create a new node with the given value
    if (root == NULL) {
        return createNode(value);
    }
    // If the value is less than the root's value, insert it into the left subtree
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the root's value, insert it into the right subtree
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to print the elements of the binary tree in-order
void printInOrder(struct TreeNode *root) {
    // If the root is not NULL, recursively print the left subtree, then the root, and then the right subtree
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d -> ", root->value);
        printInOrder(root->right);
    }
}

// Function to free the memory allocated by the binary tree
void freeTree(struct TreeNode *root) {
    // If the root is not NULL, recursively free the memory of the left and right subtrees, then free the root node
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode *tree = NULL;

    // Insertion of values into the binary tree
    tree = insert(tree, 0);
    insert(tree, 10);
    insert(tree, 45);
    insert(tree, 101);
    insert(tree, -25);
    insert(tree, 33);

    // Printing the binary tree in-order
    printInOrder(tree);
    printf("NULL\n");

    // Freeing memory allocated by the binary tree
    freeTree(tree);

    return 0;
}
