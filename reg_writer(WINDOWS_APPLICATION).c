#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_SIZE 70
#define MAX_FILE_NAME_SIZE 50
#define LOCAL_FILES "REG/"

///MINOR FUNCTIONS OF THE APPLICATION

// Function to draw a line of characters
void draw_line_global(int size) {
    int i = 0;
    do {
        printf("=");
        i++;
    } while(i <= size);
    printf("\n");
}

// Function to draw a minor line of characters
void minor_line(int size) {
    for(int i = 0; i < size; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to display a message with centered text
void msg(char txt[]) {
    int spaces_before = (LINE_MAX_SIZE - strlen(txt)) / 2;
    draw_line_global(LINE_MAX_SIZE);
    for(int i = 0; i < spaces_before; i++) {
        printf(" ");
    }
    printf("%s\n", txt);
    draw_line_global(LINE_MAX_SIZE);
}

// Function to display the list of files in the "REG" directory
void display_files() {
    minor_line(LINE_MAX_SIZE);
    system("dir /A:-D /B .\\REG | findstr /V \"<DIR>\"");
    minor_line(LINE_MAX_SIZE);
}

// Function to display text from a file
void display_text(FILE *arq) {
    char r;
    while ((r = getc(arq)) != EOF) {
        printf("%c", r);
    }
    printf("\n");
}

///GREATER FUNCTIONS OF THE APPLICATION

// Function to edit a text file
void txt_editor(FILE *arq) {
    char name[MAX_FILE_NAME_SIZE], w[999], dest[] = LOCAL_FILES;

    // Clear the screen and display minor lines and file list
    system("cls");
    display_files();

    // Prompt for file name and input
    printf("Enter the file name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    strcat(dest, name);

    arq = fopen(dest, "r");
    display_text(arq);

    // Open the file in append mode
    arq = fopen(dest , "a+");
    if(arq == NULL) {
        printf("TXT_EDITOR_ERROR: Could not open file.\n");
        return;
    }

    // Prompt for text input and write to the file
    fgets(w, sizeof(w), stdin);
    fputs(w, arq);
    fputs("\n", arq);   
    fclose(arq);
}

// Function to read and display a text file
void txt_reader(FILE *arq) {
    char name[MAX_FILE_NAME_SIZE], path[] = LOCAL_FILES;

    system("cls");
    display_files();

    // Prompt for the file name to read
    printf("Which file do you want to read? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    strcat(path, name);

    draw_line_global(LINE_MAX_SIZE);

    // Open the file in read mode
    arq = fopen(path, "r");
    if(arq == NULL) {
        printf("TXT_READER_ERROR: Could not open file.\n");
        return;
    }

    // Clear the screen and display the file content
    system("cls");
    draw_line_global(LINE_MAX_SIZE);
    display_text(arq);
    fclose(arq);
    draw_line_global(LINE_MAX_SIZE);

    // Wait for user input before returning to the menu
    getchar();
}

// Function to clean a text file
void txt_clean_file(FILE *arq) {
    system("cls");

    char name[MAX_FILE_NAME_SIZE], dest[] = LOCAL_FILES;
    display_files();

    printf("Which file do you want to clean: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    strcat(dest, name);

    arq = fopen(dest, "w");

    if(arq == NULL) {
        printf("TXT_CLEAN_FILE_ERROR: Could not open file.\n");
        return;
    }

    fclose(arq);
}

// Function to delete a file
void delete_file() {
    char name[MAX_FILE_NAME_SIZE], command[100] = "del .\\REG\\";

    system("cls");
    display_files();
    printf("Which file do you want to delete\n[0 - to cancel]\n\n-> ");

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character

    if (strcmp(name, "0") == 0) {
        printf("Deletion cancelled.\n");
        return;
    }

    strcat(command, name);
    system(command);
}

// Function to display the main menu and handle user input
void standard_menu_idle(FILE *arq) {
    int chose = -1, c;

    // Loop until the user chooses the exit option (0)
    while (chose != 0) {
        // Clear the screen and display the main menu
        system("cls");
        msg("TXT WRITER");
        printf("\033[0;33m      CHOOSE AN OPTION\n\n");
        printf("\033[0;34m[ 1 ] Edit a file\n");
        printf("[ 2 ] Read a file\n");
        printf("[ 3 ] Clean a file\n");
        printf("[ 4 ] Delete a file\n");
        printf("\033[0;31m[ 0 ] EXIT\033[0m\n");
        printf("\n---> ");
        scanf("%d", &chose);

        // Clear the input buffer
        while ((c = getchar()) != '\n' && c != EOF);

        // Process user choice
        switch(chose) {
            case 1:
                txt_editor(arq);
                break; // Go back to the beginning of the loop
            case 2:
                txt_reader(arq);
                break; // Go back to the beginning of the loop
            case 3:
                txt_clean_file(arq);
                break; // Go back to the beginning of the loop
            case 4:
                delete_file();
                break; // Go back to the beginning of the loop
            case 0:
                printf("Exiting...\n");
                system("cls");
                exit(EXIT_SUCCESS);
            default:
                printf("Enter a valid number!\n");
                break; // Go back to the beginning of the loop
        }
    }
}

int main(void) {
    // Create directory "REG" if it doesn't exist
    system("mkdir REG");
    FILE *arq = NULL; // Initialize file pointer to NULL
    
    // Call function to display the main menu
    standard_menu_idle(arq);

    // Set file pointer back to NULL as a security measure
    arq = NULL;

    return 0;
}

