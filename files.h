#ifndef __FILES_H__
#define __FILES_H__

//list of file pointers and the number of element in the array as input
void fileStatusCheck(FILE *files[], int size);

void getWordsFromFile(FILE *file, char *delimiters, char *output[], int *initSize);

#endif