#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort
void insert_sort(int array[], int size) {
    int temp;
    for(int i = 1; i < size; i++) {
        int next = i;
        // Move the current element to its correct position
        // within the sorted part of the array
        while(next != 0 && array[next] < array[next - 1]) {
            // Swap the current element with its predecessor
            temp = array[next];
            array[next] = array[next - 1];
            array[next - 1] = temp;
            next--;
        }
    }
}

// Function to prompt the user to input values for the array
void array_creator(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter a value at position %d = ", i + 1);
        scanf("%d", &array[i]);
    }
}

// Function to print the elements of the array
void print_array(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d -> ", array[i]);
    }
    printf("NULL\n\n");
}

// Function to print a line separator
void print_line() {
    printf("------------------------------------------------------------\n");
}

int main(void) {
    int size;

    system("cls");

    // Define the size of the array for the main program
    printf("DEFINE THE SIZE OF ARRAY: ");
    scanf("%d", &size);
    int array[size];

    // Print a line separator
    print_line();
    printf("Enter values for the array:\n");
    // Prompt the user to input values for the array
    array_creator(array, size);

    // Print a line separator
    print_line();
    printf("Array before sorting:\n");
    // Print the array before sorting
    print_array(array, size);

    // Sort the array using insertion sort algorithm
    insert_sort(array, size);
    printf("Array after sorting:\n");
    // Print the array after sorting
    print_array(array, size);

    // Print a line separator
    print_line();

    system("pause");

    return 0;
}
