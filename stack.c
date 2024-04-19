#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int *values;  // Array to store stack elements
    int top;      // Index of the top element
};

// Function to initialize or re-start the stack
void resetStack(struct Stack *stack) {
    stack->top = 0;            // Set top index to 0
    stack->values = NULL;      // Initialize stack array to NULL
}

// Function to insert a value into the stack
void push(int value, struct Stack *stack) {
    stack->top++;                               // Increment the top index
    stack->values = realloc(stack->values, stack->top * sizeof(int)); // Reallocate memory for the updated stack size
    if (stack->values == NULL) {                // Check if memory allocation failed
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->values[stack->top - 1] = value;     // Assign the value to the top of the stack
}

// Function to print the elements of the stack
void printStack(struct Stack *stack) {
    printf("TOP = %d\n", stack->top);          // Print the current value of the top of the stack
    for(int i = 0; i < stack->top; i++) {
        printf("|%d|\n", stack->values[i]);    // Print each element of the stack
    }
}

int main(void) {
    struct Stack stack; // Declare a stack structure variable
    
    // Initialize or re-start the stack
    resetStack(&stack);
    
    // Insert elements into the stack
    push(15, &stack);
    push(22, &stack);
    push(33, &stack);

    // Print the elements of the stack
    printStack(&stack);

    // Free the memory allocated for the stack array
    free(stack.values);

    return 0;
}
