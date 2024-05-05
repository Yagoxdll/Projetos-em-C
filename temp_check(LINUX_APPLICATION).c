#include <stdio.h>
#include <stdlib.h>

// Function to get the current CPU temperature
void get_thermal(){
    
    FILE *arq;  // File pointer
    int temp;   // Variable to store temperature in millidegrees Celsius

    // Open the file that contains CPU temperature information
    arq = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    
    // Check if the file was successfully opened
    if (arq == NULL) {
        printf("GET_THERMAL_ERROR: Error opening (.../temp).\n");
        return;
    }

    // Read temperature value from the file
    fscanf(arq, "%d", &temp);
    fclose(arq);  // Close the file
    arq = NULL;  // Reset file pointer to NULL

    // Print the temperature in Celsius, converted from millidegrees
    printf("Temperature: %.2f°C\n", temp / 1000.0); // Converting to degrees Celsius
}

// Main function
int main(void){

    // Call the function to get the CPU temperature
    get_thermal();

    return 0;
}
