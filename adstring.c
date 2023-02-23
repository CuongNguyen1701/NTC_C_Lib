#include <stdio.h>
#include "adstring.h"
#include <string.h>
#include <stdlib.h>
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
int stringContainsChar(char *str, char charList[], int listSize, int MODE)
{
    // printf("%s\n", str);
    for (int i = 0; i < listSize; i++)
        // MODE = AND = 0
        //=> if there is 0 result from strchr => return 0(mising one of the characters)

        // MODE = OR = 1
        //=> if there is 1 result from strchr => return 1(contains one of the characters)
        if (!!strchr(str, charList[i]) == MODE)
            return MODE;
    // MODE = AND => return 1(contains all of the characters)
    // MODE = OR => return 0(mising all of the characters)
    return !MODE;
}
int stringContainsSubstr(char *str, char stringList[][LISTSIZE], int listSize, int MODE)
{
    for (int i = 0; i < listSize; i++)
        // MODE = AND = 0
        //=> if there is 0 result from strstr => return 0(mising one of the substrings)

        // MODE = OR = 1
        //=> if there is 1 result from strstr => return 1(contains one of the substrings)
        if (!!strstr(str, stringList[i]) == MODE)
            return MODE;
    // MODE = AND => return 1(contains all of the substrings)
    // MODE = OR => return 0(mising all of the substrings)
    return !MODE;
}
void stringSplit(char *inputString, char *delimiters, char output[][LISTSIZE], int *initSize)
{
    // initSize should be 0 initially
    char *token = strtok(inputString, delimiters);
    while (token != NULL)
    {
        strcpy(output[*initSize], token);
        *initSize += 1;
        token = strtok(NULL, delimiters);
    }
}
void stringSplitField(char *inputString, char *firstFieldChars, char output[][LISTSIZE], int *initSize)
{
    int splitPosition = strspn(inputString, firstFieldChars);
    strcpy(output[*initSize], inputString + splitPosition);
    *initSize += 1;
    strncpy(output[*initSize], inputString, splitPosition);
}
