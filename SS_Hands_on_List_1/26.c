#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    /*char executableName[] = "./25"; // Replace with the actual executable name
    char input[] = "John"; // Replace with your desired input
    
    // Build the command string to run the executable with input
    char command[256];
    snprintf(command, sizeof(command), "%s %s", executableName,input);
    
    // Use the system() function to execute the command
    int returnCode = system(command);
    
    if (returnCode == 0) {
        printf("Executable program executed successfully.\n");
    } else {
        printf("Executable program failed with exit code: %d\n", returnCode);
    }*/
    printf("Enter the input : ");
    char str[100];
    scanf("%s",str);
    char file[10] ="./25 ";
    strcat(file,str);
    int status  = system(file);
    return 0;
}

