#include <stdio.h>
#include <stdlib.h>

// Defining a struct to represent a Queue
struct Queue {
    int *values; // Array to store queue elements
    int head;    // Index of the head of the queue
    int tail;    // Index of the tail of the queue
};

// Function to enqueue (add) an element to the queue
void enqueue(int value, struct Queue *queue) {
    queue->tail++; // Increment the tail index
    queue->values = realloc(queue->values, queue->tail * sizeof(int)); // Reallocate memory for the updated queue size
    queue->values[queue->tail - 1] = value; // Assign the value to the tail of the queue
}

// Function to dequeue (remove) an element from the queue
void dequeue(struct Queue *queue) {
    if (queue->tail > 0) { // Checking if the queue is not empty
        for (int i = 0; i < queue->tail - 1; i++) { // Shifting elements to the left to remove the head of the queue
            queue->values[i] = queue->values[i + 1];
        }
        queue->tail--; // Decrement the tail index
        queue->values = realloc(queue->values, queue->tail * sizeof(int)); // Reallocate memory for the updated queue size
    }
}

// Function to print the elements of the queue
void printQueue(struct Queue *queue) {
    printf("Queue: ");
    for (int i = 0; i < queue->tail; i++) {
        printf("%d -> ", queue->values[i]);
    }
    printf("NULL\nHEAD -> %d\nTAIL -> %d\n", queue->head, queue->tail);
}

// Function to clear the memory allocated for the queue
void clearQueue(struct Queue *queue) {
    free(queue->values); // Free the memory allocated for the array of values
    free(queue);         // Free the memory allocated for the queue struct itself
}

int main(void) {
    // Creating a queue dynamically
    struct Queue *queue = malloc(sizeof(struct Queue));

    // Enqueuing elements to the queue
    enqueue(5, queue);
    enqueue(10, queue);
    enqueue(20, queue);
    enqueue(30, queue);
    enqueue(40, queue);
    enqueue(50, queue);
    enqueue(60, queue);

    // Dequeuing an element from the queue
    dequeue(queue);

    // Printing the elements of the queue
    printQueue(queue);

    // Clearing the memory allocated for the queue
    clearQueue(queue);

    return 0;
}
