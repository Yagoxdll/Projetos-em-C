//pratical use of liked list created to store int values

#include <stdio.h>
#include <stdlib.h>

struct linkeListStruct{
    int value;
    struct linkeListStruct *next;
};

struct linkeListStruct *createNewNode(int newValue){

    struct linkeListStruct *newNode = (struct linkeListStruct*)malloc(sizeof(struct linkeListStruct));

    newNode->value = newValue;
    newNode->next = NULL;

    return newNode;
}

void insertAtBegginig(struct linkeListStruct **head, int newValue){

    struct linkeListStruct *newNode = createNewNode(newValue);
    
    newNode->value = newValue;
    newNode->next = *head;

    *head = newNode;
}

void printLikendList(struct linkeListStruct *head){
    while(head != NULL){
        printf("%d -->  ", head->value);
        head = head->next;
    }printf("NULL\n");
}

int main(void){

    struct linkeListStruct *linkedList = NULL;

    insertAtBegginig(&linkedList, 100);
    insertAtBegginig(&linkedList, 200);
    insertAtBegginig(&linkedList, 300);

    printLikendList(linkedList);

    free(linkedList);
    linkedList = NULL;

    return 0;
}