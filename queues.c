//Basic use of queues using C.

#include <stdio.h>
#include <stdlib.h>

void allocate(int **queue, int *size) {
    (*size)++;
    *queue = (int*)realloc(*queue, (*size) * sizeof(int));

    if (*queue == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}

void enqueue(int value, int **queue, int *size) {
    allocate(queue, size);
    (*queue)[*size - 1] = value;
}

void printList(int *queue, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d -> ", queue[i]);
    }
    printf("NULL\n");
}

int main(void) {
    int *queue;
    int size = 0;

    queue = (int*)malloc(size * sizeof(int));

    if (queue == NULL) {
        printf("Memory allocation error\n");
        return EXIT_FAILURE;
    }

    enqueue(1, &queue, &size);
    enqueue(2, &queue, &size);
    enqueue(3, &queue, &size);

    printList(queue, size);

    free(queue);
    queue = NULL;

    return EXIT_SUCCESS;
}
