#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *values;
    int head;
    int tail;
};

void enqueue(int value, struct Queue *queue) {
    queue->tail++;
    queue->values = realloc(queue->values, queue->tail * sizeof(int));
    queue->values[queue->tail - 1] = value;
}

void dequeue(struct Queue *queue) {
    if (queue->tail > 0) {
        for (int i = 0; i < queue->tail - 1; i++) {
            queue->values[i] = queue->values[i + 1];
        }
        queue->tail--;
        queue->values = realloc(queue->values, queue->tail * sizeof(int));
    }
}

void printQueue(struct Queue *queue) {
    printf("Queue: ");
    for (int i = 0; i < queue->tail; i++) {
        printf("%d -> ", queue->values[i]);
    }
    printf("NULL\nHEAD -> %d\nTAIL -> %d\n", queue->head, queue->tail);
}

void clearQueue(struct Queue *queue) {
    free(queue->values);
    free(queue);
}

int main(void) {
    struct Queue *queue = malloc(sizeof(struct Queue));

    enqueue(05, queue);
    enqueue(10, queue);
    enqueue(20, queue);
    enqueue(30, queue);
    enqueue(40, queue);
    enqueue(50, queue);
    enqueue(60, queue);

    dequeue(queue);

    printQueue(queue);

    clearQueue(queue);

    return 0;
}
