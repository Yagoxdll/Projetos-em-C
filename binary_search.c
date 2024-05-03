#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_STANDARD_SIZE 70

// Function to draw a line with a given size
void draw_line(int size) {
    if(size <= 0) {
        printf("DRAW_LINE_ERROR: Invalid size.\n");
        return;
    }

    int i = 0;
    do {
        printf("=");
        i++;
    } while(i < size);
    printf("\n");
}

// Function to print a message centered within a standard line size
void msg(char txt[]) {
    int spaces_before = (LINE_STANDARD_SIZE - strlen(txt)) / 2;

    draw_line(LINE_STANDARD_SIZE);
    for (int i = 0; i < spaces_before; i++) {
        printf(" ");
    }
    printf("%s\n", txt);
    draw_line(LINE_STANDARD_SIZE);
}

// Function to perform bubble sort on an array
void insert_bubble(int array[], int size) {
    int aux;

    for(int i = 0; i < size; i++) {
        int comp = i;

        while(comp != 0 && array[comp] < array[comp - 1]) {
            aux = array[comp];
            array[comp] = array[comp - 1];
            array[comp - 1] = aux;
            comp--;
        }   
    }
}

// Function to input values into an array
void array_get_values(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("    Enter the value of array element at position %d -> ", i);
        scanf("%d", &array[i]);
    }
    system("clear");
}

// Function to print array elements with their addresses
void array_printer(int array[], int size) {
    int i = 0;
    do {
        printf("Array[%d] = %d ==>[Address]%p\n", i, array[i], &array[i]);
        i++;
    } while(i < size);
}

// Function to print array elements within a formatted frame
void farray_printer(int array[], int size) {
    draw_line(LINE_STANDARD_SIZE);
    array_printer(array, size);
    draw_line(LINE_STANDARD_SIZE);
}

// Function to perform binary search on a sorted array
int binary_search(int array[], int size, int key) {
    int start = 0, end = size - 1;

    while(start <= end) {
        int middle = (start + end) / 2;

        if(array[middle] == key) {
            return middle;
        }

        if(array[middle] < key) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return -1;
}

// Function to display the result of binary search
void binary_search_results(int array[], int size, int key) {
    int resp = binary_search(array, size, key);
    if(resp != -1) {
        printf("The value %d is at position %d with address [%p]\n", key, resp, &array[resp]);
    } else {
        printf("Array not found.\n");
    }
    draw_line(LINE_STANDARD_SIZE);
}

int main(void) {
    system("clear");

    msg("Binary Search Program");

    int size;
    printf("\nWhat will be the array size => ");
    scanf("%d", &size);

    int array[size];
    int key;

    array_get_values(array, size);

    draw_line(LINE_STANDARD_SIZE);
    printf("Array before sorting...\n");
    farray_printer(array, size);

    printf("\n");
    draw_line(LINE_STANDARD_SIZE);
    printf("Array after insertion sort...\n");
    insert_bubble(array, size);
    farray_printer(array, size);

    printf("Which value do you want to search => ");
    scanf("%d", &key);

    draw_line(LINE_STANDARD_SIZE);
    binary_search_results(array, size, key);

    return 0;
}
