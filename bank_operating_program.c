

//**Summary: Banking Operations Program**

//This C program implements a simple banking system allowing users to deposit, withdraw, and check balance 
//operations. 
//It utilizes POSIX threads (`pthread`) for concurrency and semaphores for thread synchronization to ensure safe
// access to shared resources. The program presents users with a menu to select their desired operation. 
//Each operation is executed within a separate thread,
//enabling concurrent execution while maintaining thread safety with semaphores. 
//After completing each operation, users are prompted to press Enter to continue, providing an opportunity
//to review the output before clearing the screen and displaying the menu again. 
//Overall, the program demonstrates the use of threads and semaphores to manage concurrent 
//access to shared resources effectively.


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define NUM_THREADS 1

float balance = 0;      // Variable to store the account balance
sem_t mutex;            // Semaphore to ensure mutual exclusion for the balance variable

// Function to perform deposit, withdrawal, or check balance operation
void *performOperation(void *arg) {
    int *op = (int *)arg;   // Cast the argument to an integer pointer
    float value;            // Variable to store the deposit or withdrawal amount
    
    switch (*op) {  // Switch based on the selected operation
        case 1:
            // Deposit operation
            printf("Enter the deposit amount: ");
            scanf("%f", &value);    // Read the deposit amount from the user
            sem_wait(&mutex);       // Acquire the semaphore to ensure exclusive access to balance
            balance += value;       // Update the balance with the deposit amount
            printf("Deposit of %.2f completed. Current balance: %.2f\n", value, balance); // Print the transaction details
            sem_post(&mutex);       // Release the semaphore
            break;
        case 2:
            // Withdrawal operation
            printf("Enter the withdrawal amount: ");
            scanf("%f", &value);    // Read the withdrawal amount from the user
            sem_wait(&mutex);       // Acquire the semaphore
            if (balance >= value) { // Check if the balance is sufficient for withdrawal
                balance -= value;   // Update the balance with the withdrawal amount
                printf("Withdrawal of %.2f completed. Current balance: %.2f\n", value, balance); // Print the transaction details
            } else {
                printf("Insufficient balance for withdrawal of %.2f\n", value); // Print error message if balance is insufficient
            }
            sem_post(&mutex);       // Release the semaphore
            break;
        case 3:
            // Check balance operation
            printf("Current balance: %.2f\n", balance); // Print the current balance
            break;
        case 4:
            // Exit program
            pthread_exit(NULL);     // Exit the thread
            break;
        default:
            // Invalid option
            printf("Invalid option.\n"); // Print error message for invalid option
    }
    pthread_exit(NULL);     // Exit the thread
}

int main() {
    pthread_t thread;   // Thread variable
    sem_init(&mutex, 0, 1); // Initialize the semaphore with initial value 1 (mutex)

    int option;         // Variable to store the selected option
    char continueInput; // Variable to clear the Enter buffer

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option); // Read the selected option from the user

        if (option >= 1 && option <= 4) { // Check if the option is valid
            pthread_create(&thread, NULL, performOperation, (void *)&option); // Create a thread to perform the selected operation
            pthread_join(thread, NULL); // Wait for the thread to complete
            printf("Press Enter to continue...");
            scanf("%c", &continueInput); // Clear the Enter buffer
            scanf("%c", &continueInput); // Wait for user input
            system("clear"); // Clear the screen
            if (option == 4) { // Check if the selected option is to exit
                break; // Exit the loop if the selected option is to exit
            }
        } else {
            printf("Invalid option.\n"); // Print error message for invalid option
        }
    }

    sem_destroy(&mutex); // Destroy the semaphore
    return 0; // Exit the program
}
