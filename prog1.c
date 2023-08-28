#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
char buffer[MAX][MAX],string[MAX],statenum;
int bufferIndex = 0,DFSM=1,position=-1,found,stringlength=0;


int Verify_and_store_alpha_position(const char *buffer, char target) {
    int position = -1;

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == target) {
            position = i;
            break; // Stop searching once found
        }
    }

    return position;
}


int main(int argc, char *argv[]) {

    //verifying the command line argument
    if(argc!=3)
    {
        printf("The given no.of arguments are incorrect please check your arguments in command line:\n");
    }

    //printf("%s\t%s\n",argv[1],argv[2]);

    // Open the first text file for reading
    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("Error opening string.txt");
        return 1;
    }

    // Read the string from the first text file
    fgets(string, sizeof(string), file2);
    string[strcspn(string, "\n")] = '\0'; // Remove newline character
    stringlength=strlen(string);
    // Close the first text file
    fclose(file2);
    
    //accessing character
    printf("string :%s  stringlength=%d\n\n", string,stringlength);


    //open the 2nd file
    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("Error opening DFSM.txt");
        return 1;
    }

    

    //Read lines and store non-empty lines (excluding lines with only spaces)
    while (fgets(buffer[bufferIndex], MAX, file1)) {
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

    //printing the buffer index
    printf("bufferIndex:%d\n\n",bufferIndex);


    // printing the stored non-empty lines
    for (int i = 0; i < bufferIndex; i++) {
        printf("Read line %d: %s\n", i, buffer[i]);
    }

    //aphalet Length defining
    int alphalength=strlen(buffer[0]);
    //printf("alphalength:%d\n",alphalength);


    //accessing the buffer
    //printf("\nseparate :%c\n",buffer[2][0]);

    //finding length of N in NxN Matrix:
    int N = strlen(buffer[1]);
    //printf("\nN :%d\n",N);

    //Verifying that the given input is perfect NxN matrix or not

    int j,k=2,V=0;
    // k is index for matrix[k][max], V is check for NxN matrix if its one then the given matrx is not NxN

    /*
    for(j=0;j<N-1;j++)
    {
        if(strlen(buffer[k])==N && V!=1)
        {
            V=0;
            //printf("\n%s V=%d\n",buffer[k],V);
            k++;
        }
        else
        {   
            V=1;
            //printf("\n%s V=%d\n",buffer[k],V);
            k++;
        }
    }*/

    //now  K is intialized to final state index

    int finalstatelength= strlen(buffer[bufferIndex-1]);
    printf("final state: %s\t FSlength :%d FSarrayIndex:%d\n ",buffer[bufferIndex-1],finalstatelength,bufferIndex-1);

    //Closing file 2

    

    fclose(file1);



    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DFSM logic>>>>>>>>>>>>>>>>>>>>>>>>>>

    //Verify that NxN is correct and the first alphabet in the string and DFSM transition match the first character.
    //if V is 1 then the given transition table is not a NxN matrix

    //remove V=0 if you want to run DFSM only with NxN matrix
    V=0;
    
    if(V!=1)
    {
        printf("\nhi\n");




        //DFSM Logic
        for(int i=0;i<stringlength;i++)
        {

            char target = string[i];

            int position = Verify_and_store_alpha_position(buffer[0], target);

            if (position != -1) {

                //accessing the postion of alphabet
                printf("%c is present in Buffer[0] at position %d\n", target, position);

                //DFSM
                statenum=buffer[DFSM][position];
                //covert character to integer and intialize to DFSM
                DFSM=statenum-'0';
                printf("DFSM=%d\n",DFSM);


            } 
            else 
            {
                printf("\n String is NOT accepted by DFSM ");
            }

        }
        printf("\n finatstates=%s  statenum=%c DFSM=%d\n",buffer[bufferIndex-1],statenum,DFSM);

        if(strchr(buffer[bufferIndex-1],statenum))
        {
            printf("\n Given String is Accepted by DFSM\n");
        }
        else{
            printf("\n Given String is Not Accepted by DFSM final\n");
        }










    }
    else{
        printf("/n String is NOT accepted by DFSM ");
    }
    




    

    return 0;
}
