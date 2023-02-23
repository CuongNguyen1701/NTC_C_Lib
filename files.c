#include <stdio.h>
#include "files.h"

void fileStatusCheck(FILE *files[], int size)
{
    int count = 0;
    FILE *openedFiles[64];
    for (int i = 0; i < size; i++)
    {
        if (files[i] != NULL) // if the file pointer is not NULL
        {
            openedFiles[count++] = files[i];
            continue;
        }
        printf("Error opening file number %d.\n", i + 1);
        for (int j = 0; j < count; j++)
        {
            fclose(openedFiles[j]);
            printf("closed file number %d\n", j + 1);
        }
        printf("Program exited with error.\n");
        exit(1);
    }
}
void getWordsFromFile(FILE *file, char *delimiters, char *output[], int *initSize)
{
    char inputString[1024];
    char *token;
    while ((fgets(inputString, sizeof(inputString), file)) != NULL)
    {
        token = strtok(inputString, delimiters);
        while (token != NULL)
        {
            strcpy(output[*initSize], token);
            *initSize++;
            token = strtok(NULL, delimiters);
        }
    }
}
