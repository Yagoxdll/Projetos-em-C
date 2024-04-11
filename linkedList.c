#include <stdio.h>
#include <stdlib.h>

struct linkedListStruct {
    int value;
    struct linkedListStruct *next;
};

struct linkedListStruct *createNewNode(int newValue) {
    struct linkedListStruct *newNode = (struct linkedListStruct *)malloc(sizeof(struct linkedListStruct));
    newNode->value = newValue;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct linkedListStruct **head, int newValue) {
    struct linkedListStruct *newNode = createNewNode(newValue);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct linkedListStruct *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printLinkedList(struct linkedListStruct *head) {
    while (head != NULL) {
        printf("%d --> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void freeLinkedList(struct linkedListStruct *head) {
    struct linkedListStruct *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct linkedListStruct *linkedList = NULL;
    insertAtEnd(&linkedList, 100);
    insertAtEnd(&linkedList, 200);
    insertAtEnd(&linkedList, 300);
    printLinkedList(linkedList);
    freeLinkedList(linkedList);
    linkedList = NULL;
    return 0;
}
