#ifndef __ADSTRING_H__
#define __ADSTRING_H__
#define LISTSIZE 100
enum mode
{
    AND,
    OR
};
// list of file pointers and the number of element in the array as input
// Made by Nguyen Truc Cuong
void fileStatusCheck(FILE *files[], int size);
int stringContainsChar(char *str, char charList[], int listSize, int MODE);
int stringContainsSubstr(char *str, char stringList[][LISTSIZE], int listSize, int MODE);
void stringSplit(char *inputString, char *delimiters, char output[][LISTSIZE], int *initSize);
void stringSplitField(char *inputString, char *firstFieldChars, char output[][LISTSIZE], int *initSize);
#endif