#include <stdio.h>
#include <stdlib.h>

// Define a struct for a linked list node
struct linkedListStruct {
    int value;                      // Value stored in the node
    struct linkedListStruct *next;  // Pointer to the next node
};

// Function to create a new node with the given value
struct linkedListStruct *createNewNode(int newValue) {
    // Allocate memory for the new node
    struct linkedListStruct *newNode = (struct linkedListStruct *)malloc(sizeof(struct linkedListStruct));
    // Initialize the value and next pointer of the new node
    newNode->value = newValue;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct linkedListStruct **head, int newValue) {
    // Create a new node with the given value
    struct linkedListStruct *newNode = createNewNode(newValue);
    // If the linked list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // Traverse the linked list to find the last node
    struct linkedListStruct *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Attach the new node to the last node
    current->next = newNode;
}

// Function to print the elements of the linked list
void printLinkedList(struct linkedListStruct *head) {
    // Traverse the linked list and print each node's value
    while (head != NULL) {
        printf("%d --> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct linkedListStruct *head) {
    struct linkedListStruct *temp;
    // Traverse the linked list and free each node's memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main(void) {

    // Initialize a pointer to the linked list
    struct linkedListStruct *linkedList = NULL;

    // Insert elements into the linked list
    insertAtEnd(&linkedList, 100);
    insertAtEnd(&linkedList, 200);
    insertAtEnd(&linkedList, 300);

    // Print the elements of the linked list
    printLinkedList(linkedList);

    // Free the memory allocated for the linked list
    freeLinkedList(linkedList);

    linkedList = NULL;  // Reset the linked list pointer
    return 0;
}
