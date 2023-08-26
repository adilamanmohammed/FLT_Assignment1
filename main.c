#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {
    // Open the first text file for reading
    FILE *file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    // Read the string from the first text file
    char string[MAX];
    fgets(string, sizeof(string), file1);
    string[strcspn(string, "\n")] = '\0'; // Remove newline character

    // Close the first text file
    fclose(file1);
    
    //accessing character
    printf("Character :%c\n\n", string[2]);

    FILE *file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        perror("Error opening file2.txt");
        return 1;
    }

    /*char alpha[MAX],buffer[MAX],matrix[MAX][MAX]; // Adjust the array size as needed
    int Index = 0;

    int c;
    while ((c = fgetc(file2)) != EOF && c != '\n') {
        if (c != ' ') {
            alpha[Index] = c;
            Index++;
        }
    }

    alpha[Index] = '\0'; // Null-terminate the result

    //accessing alphabets
    printf("Alphabets :%c\n", alpha[2]);
    */










    //jump to line 3
    char buffer[MAX][MAX];
    int bufferIndex = 0;

    // Read lines and store non-empty lines (excluding lines with only spaces)
    while (fgets(buffer[bufferIndex], MAX, file2)) {
        int length = strlen(buffer[bufferIndex]);

        // Remove spaces from the line and store only non-space characters
        int newLength = 0;
        for (int i = 0; i < length; i++) {
            if (buffer[bufferIndex][i] != ' ' && buffer[bufferIndex][i] != '\n') {
                buffer[bufferIndex][newLength] = buffer[bufferIndex][i];
                newLength++;
            }
        }
        buffer[bufferIndex][newLength] = '\0'; // Null-terminate the modified line

        if (newLength > 0) {
            bufferIndex++;
        }
    }

    // Process the stored non-empty lines
    for (int i = 0; i < bufferIndex; i++) {
        printf("Read line %d: %s\n", i + 1, buffer[i]);
    }

    //accessing the buffer
    printf("\nseparate :%c\n",buffer[2][0]);

    //finding length of N in NxN Matrix:
    int N = strlen(buffer[1]);
    printf("\nN :%d\n",N);

    fclose(file2);

    

    return 0;
}
