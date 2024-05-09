
//////////////////
//THIS SOFTRWARE//
/////////////////

//The provided C code is a simple program for managing a linked list. 
//It includes functionalities to insert new elements into the list, view the list, 
//and delete or reset the list. The program utilizes a menu-based interface where 
//users can choose the operation they want to perform on the linked list. 
//Each function, such as inserting elements or printing the list, is implemented with 
//appropriate error handling and user-friendly messages. The code is well-structured, 
//with clear function definitions and comments to explain the logic behind each operation. 
//Overall, it serves as a basic example of how to implement a linked list management system in C.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_SIZE 75

// Define a structure for the linked list node
struct st_linkedlist {
    int value;
    struct st_linkedlist *next;
};

// Function to draw a line of a given size with '=' characters
void draw_line(int size) {
    for (int i = 0; i < size; i++) {
        printf("=");
    }
    printf("\n");
}

// Function to draw a minor line of a given size with '-' characters
void draw_minor_line(int size) {
    for (int i = 0; i < size; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to display a message with centered text within a line
void msg(char text[]) {
    int spaces_before_text = (LINE_MAX_SIZE - strlen(text)) / 2;

    draw_line(LINE_MAX_SIZE);
    for (int i = 0; i < spaces_before_text; i++) {
        printf(" ");
    }
    printf("%s\n", text);
    draw_line(LINE_MAX_SIZE);
}

// Function to get an integer value from the user
int get_value() {
    system("clear");

    int n;
    draw_minor_line(LINE_MAX_SIZE);
    printf("Enter the value to add: ");
    scanf("%d", &n);

    return n;
}

// Function to create a new node with a given value
struct st_linkedlist* create_node(int value) {
    struct st_linkedlist* new_node = malloc(sizeof(struct st_linkedlist));

    // Check if memory allocation was successful
    if (new_node == NULL) {
        printf("Memory allocation failed. Exiting...");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

// Function to insert a new node at the end of the linked list
struct st_linkedlist* insert(struct st_linkedlist **head) {
    int value = get_value();
    
    struct st_linkedlist* new_node = create_node(value);

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct st_linkedlist *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return new_node;
}

// Function to print the elements of the linked list
void print_list(struct st_linkedlist **list) {
    int count = 0; // Initialize count to zero
    system("clear");
    draw_line(LINE_MAX_SIZE);
    
    struct st_linkedlist *temp = *list;

    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
        count++;
        if(count == 8){
            printf("\n");
            count = 0;
        }
    }
    printf("NULL\n");

    draw_line(LINE_MAX_SIZE);
    getchar();
}

// Function to free the memory allocated for the linked list
void free_list(struct st_linkedlist **list) {
    while (*list != NULL) {
        struct st_linkedlist *temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

// Function to display the menu and perform operations on the linked list
void menu(struct st_linkedlist **head) {
    int choice = -1, c;
  
    while (choice != 0) {
        system("clear");

        msg("LINKED LIST MANAGER");

        printf("\nCHOOSE AN OPTION BELOW\n\n");
        draw_minor_line(LINE_MAX_SIZE);
        printf("[ 1 ] INSERT INTO THE LIST\n");
        printf("[ 2 ] VIEW THE LIST\n");
        printf("[ 3 ] DELETE OR RESET THE LIST\n");
        printf("[ 0 ] EXIT...\n");
        draw_minor_line(LINE_MAX_SIZE);
        scanf("%d", &choice);
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                insert(head);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                free_list(head);
                break;
            case 0:
                system("clear");
                printf("Exiting...");
                getchar();
                system("clear");
                exit(EXIT_SUCCESS);
            default:
                system("clear");
                msg("Please enter a valid option!\n");
                getchar();
        }
    }
}

// Main function
int main(void) {
    struct st_linkedlist* list = NULL;

    menu(&list);

    return 0;
}
